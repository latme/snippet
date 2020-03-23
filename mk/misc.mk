# 一般来说，make 会以 UNIX 的标准 Shell，也就是/bin/sh 来执行命令。


# 文件包含
include base.mk     # base.mk如果不存在，会报错
-include base.mk    # base.mk如果不存在，忽略

# 通配符，支持与shell相同的四种 * ? [] ~
# 可使用wildcard函数展开通配符，例如 objects := $(wildcard *.o)


# 伪目标，使用.PHONY关键字定义
# 无论目标是否存在，始终要执行命令部分
.PHONY: clean
clean:
    rm *.o

# “$@”表示目标的集合，就像一个数组，“$@”依次取出目标，并执于命令。


# make命令参数
# -n, --just-print     只显示命令，而不执行，用于调试Makefile

# 变量值替换，如下变量bar的值为a.c b.c
foo := a.o b.o
bar := $(foo:.o=.c)
bar := $(foo:%.o=%.c)

# 变量值当变量，如下变量bar的值为xxx
aaa := xxx
foo := aaa
bar := $($(foo))

# 条件判断
# <conditional-directive>  ifeq,ifneq, ifdef,ifndef
# <text-if-true>
# else
# <text-if-false>
# endif
ifeq ($(CC),gcc)
$(CC) -o foo $(objects) $(libs_for_gcc)
else
$(CC) -o foo $(objects) $(normal_libs)
endif

# 函数
# 字符串处理：
#   $(subst <from>,<to>,<text>)，相当于$(var:<from>=<to>)
#   $(patsubst <pattern>,<replacement>,<text>)，相当于$(var:<pattern>=<replacement>)
#   $(strip <string>)，去除字符串首尾空字符
#   $(findstring <find>,<in>)
#   $(filter <pattern...>,<text>)，获取匹配的字串
#   $(filter-out <pattern...>,<text>)，去除匹配的字串
#   $(sort <list>)，升序排序
#   $(word <n>,<text>)，取text中第n个单词，n=1,2,3,...
#   $(wordlist <s>,<e>,<text>)，取text中从s开始到e的所有单词
#   $(words <text>)，统计<text>中字符串中的单词个数。如果我们要取<text>中最后的一个单词，我们可以这样：$(word $(words <text>),<text>)
#   $(firstword <text>)，取字符串<text>中的第一个单词
#
# 文件名处理：
#   $(dir <names...>) 从文件名序列<names>中取出目录部分。目录部分是指最后一个反斜杠（“/”）之前的部分。如果没有反斜杠，那么返回“./”。
#   $(notdir <names...>) 从文件名序列<names>中取出非目录部分。非目录部分是指最后一个反斜杠（“ /”）之后的部分。
#   $(suffix <names...>) 从文件名序列<names>中取出各个文件名的后缀。
#   $(basename <names...>) 从文件名序列<names>中取出各个文件名的前缀部分。
#   $(addsuffix <suffix>,<names...>) 把后缀<suffix>加到<names>中的每个单词后面。
#   $(addprefix <prefix>,<names...>) 把前缀<prefix>加到<names>中的每个单词前面。
#   $(join <list1>,<list2>) 把<list2>中的单词对应地加到<list1>的单词后面。
#      如果<list1>的单词个数要比<list2>多，那么，<list1>中的多出来的单词将保持原样。
#      如果<list2>的单词个数要比<list1>多，那么，<list2>多出来的单词将被复制到<list2>中。
filepath = /wrk/base.inc.mk
$(dir      $(filepath))     # /wrk/
$(notdir   $(filepath))     # base.inc.mk
$(suffix   $(filepath))     # .mk
$(basename $(filepath))     # /wrk/base.inc
#
# 其他：
#   $(foreach <var>,<list>,<text>) 把参数<list>中的单词逐一取出放到参数<var>所指定的变量中，
#      然后再执行<text>所包含的表达式。每一次<text>会返回一个字符串，循环过程中，<text>
#      的所返回的每个字符串会以空格分隔，最后当整个循环结束时，<text>所返回的每个字符串
#      所组成的整个字符串（以空格分隔）将会是 foreach 函数的返回值。
#      下例 files的值为a.o b.o c.o d.o
names := a b c d
files := $(foreach n,$(names),$(n).o)
#
#   $(if <condition>,<then-part>,<else-part>)
#   $(call <expression>,<parm1>,<parm2>,<parm3>...) 当 make 执行这个函数时，<expression>参数中的变量，
#          如$(1)，$(2)，$(3)等，会被参数<parm1>，<parm2>，<parm3>依次取代。而<expression>的返回值就是 call 函数的返回值。
#   $(origin <variable>) 以其返回值来告诉你这个变量的来源：
#       “undefined”
#       “default”
#       “file”            定义在Makefile中
#       “command line”    被命令行定义的
#       “override”        被override指示符重新定义的
#       “automatic”       命令运行中的自动化变量
#   $(shell <shell cmd>)  新生成一个 Shell 程序来执行命令，所以要注意其运行性能
contents := $(shell cat foo)
#
#   $(error <text ...>)
#   $(warning <text ...>)

# make退出码
#  0 - 表示成功执行。
#  1 - 如果 make 运行时出现任何错误，其返回 1。
#  2 - 如果你使用了 make 的“-q”选项，并且 make 使得一些目标不需要更新，那么返回 2。



