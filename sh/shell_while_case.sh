#!/usr/bin/env sh

:<<EOF
参考：https://www.runoob.com/linux/linux-shell-process-control.html

条件控制
=======
if condition; then
    command1
elif condition2; then
    command2
else
    command3
fi

case语句
========
case val in
pattern1)
    command1
    ;;
pattern2）
    command2
    ;;
*)
    command3
    ;;
esac

while循环，直到条件为false时停止
==============================
while condition
do
    command
done

until循环，直至条件为 true 时停止
===============================
until condition
do
    command
done

break和continue可用于for/while/until循环控制。


EOF




