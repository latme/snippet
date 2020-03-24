
# 判断系统是否为WINDOWS，利用WINDOWS特有的环境变量：
# WINDIR=C:\Windows
# OS=OS=Windows_NT
# HOMEDRIVE=C:
# HOMEPATH=\Users\xuyi
# SystemDrive=C:
# SystemRoot=C:\Windows
#
ifdef WINDIR
CP      := ./bin.bat cp
RM      := ./bin.bat rm
MKDIR   := ./bin.bat mkdir
MAKE    := make
else    
CP      := cp -f
RM      := rm -rf
MKDIR   := mkdir -p
MAKE    := make
endif


self = $(lastword $(MAKEFILE_LIST))
all :
	$(MKDIR) aaaa/xxxx bbbb/yyyy
	$(CP)    $(self) bbbb/yyyy/b.x
	$(CP)    $(self) aaaa/xxxx
	$(RM)    aaaa/xxxx/$(self) bb/1 2 3 4 5 6 7 8 9 10 11 aaaa/xxxx bbbb aaaa


