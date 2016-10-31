@echo off
goto Test1

:RunTest
echo Testing in: %RunTest_in%, out: %RunTest_out%
for /f %%i in ('Flipbyte.exe %RunTest_in%') do set tmpResult=%%i
if %tmpResult%==%RunTest_out% (
	echo Success
) else (
	echo Fail
)
goto %RunTest_rp%

:Test1
set RunTest_in=6
set RunTest_out=96
set RunTest_rp=Test2
goto RunTest

:Test2
set RunTest_in=1
set RunTest_out=128
set RunTest_rp=Test3
goto RunTest

:Test3
set RunTest_in=2
set RunTest_out=64
set RunTest_rp=Test4
goto RunTest

:Test4
set RunTest_in=3
set RunTest_out=192
set RunTest_rp=Test5
goto RunTest

:Test5
echo Testing wrong usage
Flipbyte.exe
Flipbyte.exe str
Flipbyte.exe 1234
Flipbyte.exe -1

pause
