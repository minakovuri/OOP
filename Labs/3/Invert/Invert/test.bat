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
%PROGRAM% test-data\inputs\Unexisting.txt > %TEMP_FILE%
if NOT ERRORLEVEL 1 goto err
echo Test #2 passed!

rem При запуске с матрицей, определитель которой 
%PROGRAM% test-data\inputs\Determenant0.txt > %TEMP_FILE%
if NOT ERRORLEVEL 1 goto err
echo Test #3 passed!

rem Запуск с корректными параметрами
%PROGRAM% test-data\inputs\1.txt > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\1.txt > nul
if ERRORLEVEL 1 goto err
echo Test #4 passed!

%PROGRAM% test-data\inputs\2.txt > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\2.txt > nul
if ERRORLEVEL 1 goto err
echo Test #5 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1