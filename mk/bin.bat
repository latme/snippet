:: batĬ��ֻ�ܻ�ȡ��1-9���������ֱ���%1 %2 ... %9���ã��������bat�Ĳ�������9�����ͱ�����shift��
:: bat���������������ʽΪ��./bin.bat cp src.file dst.file
::   %0  ./bin.bat
::   %1  cp
::   %2  src.file
::   %3  dst.file
::   %*  cp src.file dst.file
@echo off
SETLOCAL ENABLEEXTENSIONS
SETLOCAL ENABLEDELAYEDEXPANSION

::echo before shift: %* .. %1
set cmd=%1
shift /1
::echo after  shift: %* .. %1


::set ec=echo
set ec=

if "%cmd%"=="cp" (
	set src=%1
	set dst=%2
	%ec% copy /y !src:/=\! !dst:/=\! >nul

	goto :EOF
)
if "%cmd%"=="rm" (
	:_loop_rm
	set file=%1
	if "!file!"=="" goto :EOF
	
	set file=!file:/=\!
	if exist !file!\ (
		%ec% rd /s /q !file! 2>nul
	) else (
		%ec% del /f /q !file! 2>nul
	)

	shift /1
	goto :_loop_rm
)
if "%cmd%"=="mkdir" (
	:_loop_mkdir
	set dir=%1
	if "!dir!"=="" goto :EOF
	
	%ec% mkdir !dir:/=\! 2>nul

	shift /1
	goto :_loop_mkdir
)
goto :EOF


