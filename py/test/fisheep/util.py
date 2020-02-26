#!/usr/bin/python
# -*- coding: utf-8 -*-

from datetime import datetime


def dtname(dt=None):
    """返回日期时间作为路径名的字符串"""
    if dt is None:
        dt = datetime.now()
    return dt.strftime('%Y%m%d_%H%M%S')


def dtstr(dt=None):
    """返回日期时间来显示的字符串"""
    if dt is None:
        dt = datetime.now()
    return dt.strftime('%Y-%m-%d %H:%M:%S')


def dname(dt=None):
    """返回日期作为路径名的字符串"""
    if dt is None:
        dt = datetime.now()
    return dt.strftime('%Y%m%d')


def dstr(dt=None):
    """返回日期来显示的字符串"""
    if dt is None:
        dt = datetime.now()
    return dt.strftime('%Y-%m-%d')


def tname(dt=None):
    """返回时间作为路径名的字符串"""
    if dt is None:
        dt = datetime.now()
    return dt.strftime('%H%M%S')


def tstr(dt=None):
    """返回时间来显示的字符串"""
    if dt is None:
        dt = datetime.now()
    return dt.strftime('%H:%M:%S')


