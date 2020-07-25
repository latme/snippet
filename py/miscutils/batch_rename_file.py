#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import re

PY_ROOT = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
sys.path.append(PY_ROOT)
import latme.datetime as ldt


def rename_files(pattern, replace, dirs):
    for d in dirs:
        if not os.path.isdir(d):
            continue

        for filename in os.listdir(d):
            filename_new = re.sub(pattern, replace, filename)
            print(filename + ' -> ' + filename_new)
            os.rename(filename, filename_new)


if __name__ == '__main__':
    rename_files(r'^(.*)$', r'\1', r'.')
