#!/usr/bin/python
# -*- coding: utf-8 -*-

import os



# 获取文件目录和名称
#------------------
filepath = r'/wrk/snippet/py/filesystem.py'
dirname  = os.path.dirname(filepath)
filename = os.path.basename(filepath)
(dirname, filename) = os.path.split(filepath)

dirname  = '/wrk/snippet/py'
filename = 'filesystem.py'


# 获取文件名和扩展名
#------------------
filepath = r'/wrk/snippet/py/filesystem.xx.py'
(base, ext) = os.path.splitext(filepath)

base = '/wrk/snippet/py/filesystem.xx'
ext  = '.py'


