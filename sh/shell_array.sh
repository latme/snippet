#!/usr/bin/env sh

:<<EOF
参考：https://www.runoob.com/linux/linux-shell-array.html

shell数组，只支持一维数组（不支持多维数组），初始化时不需要定义数组大小

定义数组
=======
shell 数组用括号来表示，元素用"空格"符号分割开，语法格式如下：
array_name=(value0 value1 value2 ...)
也可以使用下标来定义数组:
array_name[0]=value0
array_name[1]=value1
array_name[2]=value2

读取数组
=======
读取数组元素值的一般格式是：
${array_name[index]}
读取所有元素值：
${array_name[*]}
${array_name[@]}

获取数组的长度
=============
获取数组长度的方法与获取字符串长度的方法相同，以下两种方法结果完全相同：
${#array_name[*]}
${#array_name[@]}
-----------------------------------------
EOF
users=(usr1 usr2 usr3 "usr x")

# 遍历数组
echo \${#users[@]} is ${#users[@]}
for user in ${users[@]}; do
  echo @: $user
done

echo \${#users[*]} is ${#users[*]}
for user in ${users[*]}; do
  echo *: $user
done

# 遍历数组
echo \${#users[@]} is ${#users[@]}
for idx in $(seq 0 1 $((${#users[@]} - 1))); do
  echo @$idx: ${users[$idx]}
done

echo \${#users[*]} is ${#users[*]}
for idx in $(seq 0 1 $((${#users[*]} - 1))); do
  echo *$idx: ${users[$idx]}
done

:<<EOF
结果为：
-------
${#users[@]} is 4
usr1
usr2
usr3
usr
x
${#users[*]} is 4
usr1
usr2
usr3
usr
x
${#users[@]} is 4
@0: usr1
@1: usr2
@2: usr3
@3: usr x
${#users[*]} is 4
*0: usr1
*1: usr2
*2: usr3
*3: usr x
EOF

