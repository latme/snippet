#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

# 文件所在目录添加到import搜索路径
TOPDIR = os.path.dirname(__file__)
sys.path.append(TOPDIR)


if __name__ == '__main__':
    # python3 x_cmdline_args.py  a1 a2 a3 a4 a5
    argv = sys.argv
    argc = len(argv)

    for arg in argv:
        print(arg)
    # x_cmdline_args.py
    # a1
    # a2
    # a3
    # a4
    # a5

    i = 0
    while i < argc:
        print(str(i)+'/'+str(argc) + '  ' + argv[i])
        i += 1
    # 0/6  x_cmdline_args.py
    # 1/6  a1
    # 2/6  a2
    # 3/6  a3
    # 4/6  a4
    # 5/6  a5

