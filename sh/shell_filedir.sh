#!/usr/bin/env bash

:<<EOF
1. 遍历目录

1.1 遍历普通目录（子文件或目录名不带空格）
filelist=$(ls -A .)
for file in $filelist; do
    echo \"$file\"
done


1.2 遍历特殊目录（子文件或目录名带空格）
# 因为输入默认分隔符IFS默认为空格、制表符、换行符，带空格的文件名会被当作多个文件。
ian@LAPTOP:~$ set | grep ^IFS
IFS=$' \t\n'

1.2.1 方法一：临时修改IFS
# 在遍历时，临时修改IFS为换行符。
oldIFS=$IFS
IFS=$'\n'
filelist=$(ls -A .)
for file in $filelist; do
    echo "file:\"$file\""
done
IFS=$oldIFS

1.2.2 方法二：临时替换空格为其他不可能出现的字符，使用的时候再替换回空格
filelist=$(ls -A . | tr ' ' '|')
for f in $filelist; do
    file=${f//|/ }
    echo "file:\"$f -> $file\""
done

EOF

