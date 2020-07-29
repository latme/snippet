#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import urllib3
import requests
import os
import sys
import re
from bs4 import BeautifulSoup

sys.path.append(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))
import latme


class SpiderTextBiquge():
    """Spider Text Practice"""

    def __init__(self):
        self.url_root = ''
        self.book_name = ''
        self.chapter_names = []
        self.chapter_urls = []
        self.chapter_num = 0

    def get_chapter_urls(self, url):
        self.url_root = re.sub(r'(^\w+:/+.+?)/.*$', r'\1', url)

        html = requests.get(url)
        html.encoding = html.apparent_encoding
        html_text = html.text
        html_bs = BeautifulSoup(html_text, 'html.parser')

        self.book_name = html_bs.find('h1').text

        chapter_list = html_bs.find('div', id='list')
        chapter_list_bs = BeautifulSoup(str(chapter_list), 'html.parser')
        chapter_info = chapter_list_bs.find_all('a')
        for info in chapter_info[9:]:
            self.chapter_names.append(info.string)
            self.chapter_urls.append(self.url_root + info.get('href'))
        self.chapter_num = len(self.chapter_names)

    def get_chapter_content(self, url):
        html = requests.get(url)
        html.encoding = html.apparent_encoding
        html_text = html.text
        html_bs = BeautifulSoup(html_text, 'html.parser')

        chapter_content = html_bs.find('div', id='acontent')
        chapter_content_text = chapter_content.text
        chapter_content_text = chapter_content_text.replace('\n\n', '\n').replace('    ', '')
        # print(chapter_content_text)
        return chapter_content_text

    def run(self):
        self.get_chapter_urls('http://www.biqu.ge/183/183509/')
        if self.book_name == '':
            return

        os.chdir(latme.USER_HOME)
        os.mkdir(self.book_name)
        os.chdir(self.book_name)

        for i in range(self.chapter_num):
            name = self.chapter_names[i]
            if name[0] == '第':
                print('downloading %s %d/%d %s\r' % (self.book_name, i, self.chapter_num, name))
                with open(name+'.txt', 'w') as fd:
                    content = self.get_chapter_content(self.chapter_urls[i])
                    fd.write(content)
        print('\n')
        print('Download Done\n')


if __name__ == '__main__':
    spider = SpiderTextBiquge()
    spider.run()
