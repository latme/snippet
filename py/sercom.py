#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import serial
import sys
import msvcrt
import time
import argparse


keymap = {
    b'H': bytes([0x1b, 0x5b, 0x41]),            # up
    b'P': bytes([0x1b, 0x5b, 0x42]),            # down
    b'M': bytes([0x1b, 0x5b, 0x43]),            # right
    b'K': bytes([0x1b, 0x5b, 0x44]),            # left
    b'O': bytes([0x1b, 0x5b, 0x46]),            # end
    b'G': bytes([0x1b, 0x5b, 0x48]),            # home
    b'R': bytes([0x1b, 0x5b, 0x32, 0x7e]),      # insert
    b'S': bytes([0x1b, 0x5b, 0x33, 0x7e]),      # delete
    b'I': bytes([0x1b, 0x5b, 0x35, 0x7e]),      # page-up
    b'Q': bytes([0x1b, 0x5b, 0x36, 0x7e]),      # page-down
}


parser = argparse.ArgumentParser()
parser.add_argument("com_port", type=str, help="the serial port will connect to. e.g. COM1")
parser.add_argument("-b", "--baudrate", type=int, help="baudrate of the port", default=115200)
args = parser.parse_args()

ser = serial.Serial(args.com_port, args.baudrate)
ser.timeout = 0

idle_cnt = 0

while True:
    ret = ser.readall()
    if ret != b'':
        idle_cnt = 0
        sys.stdout.write(ret.decode())
        sys.stdout.flush()
    else:
        idle_cnt = idle_cnt + 1

    if msvcrt.kbhit():
        idle_cnt = 0
        ret = msvcrt.getch()
        if ret == b'\xe0':
            ret = msvcrt.getch()
            if ret in keymap:
                ret = keymap[ret]
            else:
                print('unknown map key: ' + repr(ret))
                ret = None

        if ret is not None:
            ser.write(ret)
    else:
        idle_cnt = idle_cnt + 1

    if idle_cnt > 10:
        time.sleep(0.05)
