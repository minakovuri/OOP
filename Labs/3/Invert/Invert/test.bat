@echo off

rem установка кодировки
chcp 1251

set PROGRAM="%~1"
set TEMP_FILE="%TEMP%\out.txt"
set PERMANENT_FILE="test-data\out.txt"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1 passed!

rem При запуске с некорректным параметром ожидается ненулевой код возврата
%PROGRAM% test-data\inputs\2.txt > %TEMP_FILE%
if NOT ERRORLEVEL 1 goto err
echo Test #2 passed!

%PROGRAM% test-data\inputs\1.txt > %PERMANENT_FILE%
if ERRORLEVEL 1 goto err
echo Test #3 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1