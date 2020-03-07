#!/usr/bin/env sh

:<<EOF
C语言风格：
---------
for((初始化语句; 判断条件; 自增或自减))
do
    statements
done

Python语言风格：
--------------
for variable in value_list
do
    statements
done

value_list形式：
1. 直接给出具体值，多个值之间以空格分隔。例如 1 2 3 4、"abc" "123" "efg"
2. 给出取值范围：{start..end}
3. 使用命令执行结果。例如 $(seq 0 1 10), $(ls)


shell for用法，以下三种循环结果完全一致：
1. for ((i=0; i<=10; i++));
2. for i in $(seq 0 1 10);    # 0为最小值，1为间隔，100为结束值
   for i in $(seq 0   10);    # 等同于$(seq 0 1 10);
   for i in $(seq     10);    # 等同于$(seq 1 1 10);
3. for i in {0..10};          # 起始和结束值必须是常数
EOF

for((i=0; i<=4; i++)); do
  echo '(()): '$i
done

for i in $(seq 0 1 4); do
  echo 'in seq3: '$i
done

for i in $(seq 0 4); do
  echo 'in seq2: '$i
done

for i in $(seq 4); do
  echo 'in seq1: '$i
done

for i in {0..4}; do
  echo 'in {}: '$i
done



:<<EOF
执行结果：
(()): 0
(()): 1
(()): 2
(()): 3
(()): 4
in seq3: 0
in seq3: 1
in seq3: 2
in seq3: 3
in seq3: 4
in seq2: 0
in seq2: 1
in seq2: 2
in seq2: 3
in seq2: 4
in seq1: 1
in seq1: 2
in seq1: 3
in seq1: 4
in {}: 0
in {}: 1
in {}: 2
in {}: 3
in {}: 4
EOF
