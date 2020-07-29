#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os

USER_HOME = os.path.expanduser('~')

DICT_DIGIT_UNIT_CN = {'十': 10, '百': 100, '千': 1000, '万': 10000, '亿': 100000000}

LIST_DIGIT_CN = ['〇', '一', '二', '三', '四', '五', '六', '七', '八', '九']
DICT_DIGIT_CN = {'〇': 0, '一': 1, '二': 2, '三': 3, '四': 4,
                 '五': 5, '六': 6, '七': 7, '八': 8, '九': 9,
                 '零': 0}


def convDigitCnToNum(cn_digit_str):
    assert type(cn_digit_str) == str

    num = 0
    for i in len(cn_digit_str):
        ch = cn_digit_str[i]
        if i > 0:
            if next_is_digit:
                if ch in DICT_DIGIT_CN:
                    n = DICT_DIGIT_CN[ch]
                    next_is_digit = False
            else:
                if ch in DICT_DIGIT_UNIT_CN:
                    n = DICT_DIGIT_UNIT_CN[ch]
        else:
            if ch == '十':
                num = 10
                next_is_digit = True
                continue
            if ch in DICT_DIGIT_CN:
                n = DICT_DIGIT_CN[ch]
                if n > 0:
                    num = n
                    next_is_digit = False
                    continue
            break
    return num, i


def convDigitNumToCn(num_digit):
    cn_str = ''
    return cn_str
