:: bat默认只能获取到1-9个参数，分别用%1 %2 ... %9引用，如果传给bat的参数大于9个，就必须用shift。
:: bat参数，假如调用形式为：./bin.bat cp src.file dst.file
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


