#!/usr/bin/env sh


:<<EOF
参考：https://www.runoob.com/w3cnote/linux-shell-brackets-features.html

小括号：
=======
单小括号()，$(x)等同于`x`
------------------------
命令组：新建一个进程顺序执行括号中的命令，命令之间用分号分开。部分shell返回括号内命令的标准输出。
初始化数组：例如 array_name=(a b c d)

双小括号(())，$((x))等同于`expr x`
---------------------------------
((exp))结构扩展并计算一个算术表达式的值，双括号中的变量可以不使用$符号前缀。括号内多个表达式用逗号分开。


中括号：
=======
单中括号[]
----------
shell内部命令：[与test等同。
字符范围：例如 [a-f0-9]
数组索引：例如 array_name[0]

双中括号[[]]
------------
shell关键字：相比[]，[[]]内的字符都不会发生文件名扩展或单词分隔，但是会发生参数扩展和命令替换（例如 $(ls)）。
作为判断结构：相比[]，能够防止许多逻辑错误。可用&&, ||, <, >等，例如
             if [[ $a != 1 && $a != 2 ]]，等效于if [ $a -ne 1] && [ $a != 2 ]，或者if [ $a -ne 1 -a $a != 2 ]

大括号：
=======
单大括号{}
---------
1. 常规用法
大括号拓展：将对大括号中的文件名做扩展，大括号中不允许有空白。
            以逗号分隔文件列表进行拓展，例如 touch {a,b}.txt等同于touch a.txt b.txt
            以点点分隔文件列表进行拓展，例如 touch {a..c}.txt等同于touch a.txt b.txt c.txt
代码块（内部组）：与小括号不同的是，不会新建一个进程执行括号内的命令。且第一调命令前必须有空格，最后一条命令后必须有分号。

2. 几种特殊的替换结构
${var:-string} 如果var为空，结果为string，否则结果为var；
${var:+string} 如果var为空，结果为var，否则结果为string；
${var:=string} 如果var为空，结果为string，且var赋值为string，否则结果为var；
${var:?string} 如果var为空，把string输出到stderr，并从退出脚本，否则结果为var。

3. 四种模式匹配替换结构。例如 var=testcase
${var%pattern}  去掉var中右边最短的匹配模式，${var%s*e}结果为testca
${var%%pattern} 去掉var中右边最长的匹配模式，${var%%s*e}结果为te
${var#pattern}  去掉var中左边最短的匹配模式，${var#*s}结果为tcase
${var##pattern} 去掉var中左边最长的匹配模式，${var##*s}结果为e

4. 字符串提取和替换
${var:num}                提取第num个字符到末尾的字符。num为正，从左边0处开始；num为负，从右边开始提取，但必须空格分开或括号包围。
${var:num1:num2}          从num1位置开始，提取num2个字符，不能为负数。
${var/pattern1/pattern2}  把第一个匹配的pattern1替换为pattern2
${var//pattern1/pattern2} 把所有匹配的pattern1替换为pattern2

EOF

