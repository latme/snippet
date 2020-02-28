#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import sys
import platform



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


# 获取相对、绝对路径
#------------------
os.path.relpath(r'/wrk/snippet/py', '/wrk')  # 返回'snippet/py'
os.path.abspath('.')
os.path.realpath('.')   # 对符号链接，返回符号指向的真实路径。对非符号链接，与abspath一样。
os.path.expanduser('~/Desktop')  # 将首字符为'~'的扩展为用户绝对路径，非首字符的'~'不扩展

# 获取当前路径
#------------
os.getcwd()
os.path.abspath('.')
os.path.abspath(os.curdir)

# 改变当前路径
#------------
path = r'/wrk/snippet'
os.chdir(path)

# 组合路径
#---------
os.path.join('wrk', 'snippet', 'py')


# 列出目录内容
# os.walk(top,topdown=True,οnerrοr=None)  遍历整个目录树
# (1)参数top表示需要遍历的顶级目录的路径。
# (2)参数topdown的默认值是“True”表示首先返回顶级目录下的文件，然后再遍历子目录中的文件。当topdown的值为"False"时，表示先遍历子目录中的文件，然后再返回顶级目录下的文件。
# (3)参数onerror默认值为"None"，表示忽略文件遍历时的错误。如果不为空，则提供一个自定义函数提示错误信息后继续遍历或抛出异常中止遍历。
# 返回值：函数返回一个元组，含有三个元素。这三个元素分别是：每次遍历的路径名、路径下子目录列表、目录下文件列表。
#------------
dirpath = r'/wrk/snippet/py'
dircontent = os.listdir(dirpath)
for root,dirs,files in os.walk(dirpath):
    pass


# 系统分隔符
#----------    windows  linux
os.sep       #  \\       /
os.altsep    #  /
os.pathsep   #  ;        :
os.extsep    #  .        .
os.linesep   #  \r\n     \n


# 判断是文件还是目录
#------------------
os.path.isdir(dirpath)
os.path.isfile(filepath)
os.path.exists(filepath)
os.path.islink(filepath)
os.path.isabs(filepath)


# 判断系统类型
#------------
platform.system()           # 返回'Windows' / 'Linux'
platform.architecture()     # 返回系统体系结构信息，例如位宽
platform.uname()
platform.version()

# 查看python版本
#---------------
sys.version                # 返回版本信息字符串
sys.version_info           # 返回版本信息类实例



