#!/usr/bin/python
# -*- coding: utf-8 -*-

from datetime import datetime


get_datetime: datetime = lambda dt: dt is None and datetime.now() or dt


def dateStr(dt=None):
    """date: 1990-12-31  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%Y-%m-%d')


def timeName(dt=None):
    """time: 235900  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%H%M%S')


def timeNameM(dt=None):
    """time: 2359  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%H%M')


def timeNameH(dt=None):
    """time: 23  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%H')


def timeStr(dt=None):
    """time: 23:59:00  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%H:%M:%S')


def dateName(dt=None):
    """date: 19901231  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%Y%m%d')


def dateNameM(dt=None):
    """date: 199012  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%Y%m')


def dateNameY(dt=None):
    """date: 1990  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%Y')


def datetimeStr(dt=None):
    """datetime: 1990-12-31 23:59:00  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%Y-%m-%d %H:%M:%S')


def datetimeName(dt=None):
    """datetime: 19901231_235900  (1990-12-31 23:59:00)"""
    return get_datetime(dt).strftime('%Y%m%d_%H%M%S')
