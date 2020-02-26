#!/usr/bin/python
# -*- coding: utf-8 -*-

import fisheep as fs


class TestCase():
    def tstWriteCrLn(self):
        r"""测试文件的write方法是否会在末尾加换行符。
        判定标准：生成的文件中，两次写入的字符串中间是否会有\r或\n
        实测结果：不会有
        测试原因：之前开发中发现，从串口读回的数据使用文件的write方法写到文件中，每行结尾是\r\r\n
        """
        filepath = 'tstWriteCrLn_' + fs.util.dtname() + '.txt'
        f = self.openFile(filepath)
        if f is not None:
            f.write('aaaaaaaa')
            f.write('bbbbbbbb')

            print('file(%s) write success. please open it for check' % filepath)
            f.close()

    def openFile(self, filepath):
        try:
            file = open(filepath, 'w+')
        except Exception as e:
            print('open file(%s) fail! %s' % (filepath, repr(e)))
            return None
        return file


if __name__ == '__main__':
    t = TestCase()
    t.tstWriteCrLn()

