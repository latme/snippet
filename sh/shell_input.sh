#!/usr/bin/env bash

# -e选项使用Readline获取行，以支持退格键修改输入内容
# -p选项输出提示信息，提示信息不会加入到输入内容
# -i选项输出提示信息，且提示信息会加入到输入内容
# -s选项不显示输入内容
# -a选项指定变量时数组
# 默认会忽略输入内容前后的空白
read -e var
read -ep  "select a function: " var
read -sep "input your password: " var

read -ep  "options: " -a var
for v in "$var"; do
    echo "$v"
done

