#!/usr/bin/env sh

:<<EOF
参考：https://www.runoob.com/linux/linux-shell-func.html

shell函数定义：
--------------
[ function ] funname [()]
{
    action
    [return int]
}


参数处理	说明
------------
$0  执行文件名
$1  第一个参数
$*	以一个单字符串显示所有向脚本传递的参数。
    如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。
$@	与$*相同，但是使用时加引号，并在引号中返回每个参数。
    如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。
$#	传递到脚本的参数个数
$$	脚本运行的当前进程ID号
$!	后台运行的最后一个进程的ID号
$-	显示Shell使用的当前选项，与set命令功能相同。
$?	显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。
EOF


demofunc()
{
  echo \$#: $#
  echo \$0: $0
  echo \$1: $1
  echo \$2: $2
  echo \$3: $3

  for arg in "$@"; do
    echo \$@: $arg
  done

  for arg in $*; do
    echo \$*: $arg
  done

  return $#
}


demofunc 1 "arg2" "arg 3"
echo retval: $?

:<<EOF
$#: 3
$0: ./shell_arg.sh
$1: 1
$2: arg2
$3: arg 3

$@: 1
$@: arg2
$@: arg 3

$*: 1
$*: arg2
$*: arg
$*: 3

retval: 3
EOF

