#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def gram_exception():
    try:
        with open('not_existed_filename', 'r') as fp:
            fp.close()
    except Exception as e:
        print(e)            # [Errno 2] No such file or directory: 'not_existed_filename'
        print(e.args)       # (2, 'No such file or directory')
        print(e.errno)      # 2
        print(e.strerror)   # No such file or directory
    else:
        pass    # will execute only if no any exception happen
    finally:
        pass    # will always execute whether exception happen or not


if __name__ == '__main__':
    gram_exception()
