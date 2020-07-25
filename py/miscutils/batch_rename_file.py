#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import re

PY_ROOT = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
sys.path.append(PY_ROOT)
import latme.datetime as ldt


def rename_files(pattern, replace, dir_path):
    if not os.path.isdir(dir_path):
        return

    for filename in os.listdir(dir_path):
        filename_new = re.sub(pattern, replace, filename)
        if filename_new != filename:
            print(filename + ' -> ' + filename_new)
            os.rename(os.path.join(dir_path, filename), os.path.join(dir_path, filename_new))


if __name__ == '__main__':
    rename_files(r'^(.*)$', r'\1', r'path')
