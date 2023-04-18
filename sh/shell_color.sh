#!/usr/bin/env bash

:<<EOF
echo [SHORT-OPTION]... [STRING]...

-n     do not output the trailing newline
-e     enable  interpretation of backslash escapes
-E     disable interpretation of backslash escapes (default)

If -e is in effect, the following sequences are recognized:
\\           backslash
\a  \x07     alert (BEL)
\b  \x7f     backspace
\c           produce no further output
\e  \x1b     escape
\f  \x0c     form feed
\n  \x0a     new line
\r  \x0d     carriage return
\t  \x09     horizontal tab
\v	\x0b     vertical tab
\0NNN        byte with octal value NNN (1 to 3 digits)
\xHH         byte with hexadecimal value HH (1 to 2 digits)

\e或\E或\033（八进制ASCII）或\x1B或\x1b（十六进制ASCII）是等效的。


\e[ 开始转义序列，m 终止转义序列。
\e[XXXm      XXX定义属性，多个属性用分号间隔
0   默认
1	粗体
4	下划线
5	闪烁
7	反色

前景 背景 颜色 （前景色即字体颜色）
----------------------------------
30   40   黑色Black
31   41   红色Red
32   42   绿色Green
33   43   黄色Yellow
34   44   蓝色Blue
35   45   紫红色Magenta
36   46   青色Cyan
37   47   白色White

EOF


for STYLE in 0 1 4 5 7; do
  for FG in 30 31 32 33 34 35 36 37; do
    for BG in 40 41 42 43 44 45 46 47; do
      CTRL="\033[${STYLE};${FG};${BG}m"
      echo -en "${CTRL}"
      echo -n "${STYLE};${FG};${BG}"
      echo -en "\033[0m"
    done
    echo
  done
  echo
done

# Reset
echo -e "\033[0m"


CRST='\e[0m'
CRED='\e[31m'
CGRN='\e[32m'
CYEL='\e[33m'
CBLU='\e[34m'
CMAG='\e[35m'
CCYA='\e[36m'
CWHI='\e[37m'
echo -e "$CRED红色$CYEL黄色$CBLU蓝色$CRST默认"

