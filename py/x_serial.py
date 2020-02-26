#!/usr/bin/python
# -*- coding: utf-8 -*-

# 需要安装pyserial包
# pip install pyserial


import serail



# 打开串口
#---------
ser_cfg = {
'port'    : 'COM1',
'baudrate': 115200,
'timeout' : 1
}

ser = serial.Serial(ser_cfg)
if ser.isOpen():
    print('open successful')


# 写数据
#-------
wr_cnt = ser.write('string')
print('written bytes: ', wr_cnt)


# 读数据
#-------
rd_str = read_all()
rd_str = readline()
rd_str = readlines()


# 关闭串口
#---------
ser.close()
