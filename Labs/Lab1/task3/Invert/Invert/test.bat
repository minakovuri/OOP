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

rem При запуске с матрицей, определитель которой равен 0
%PROGRAM% test-data\inputs\Determenant0.txt > %TEMP_FILE%
if NOT ERRORLEVEL 1 goto err
echo Test #3 passed!

rem  При запуске с некорректной матрицей ожидается ненулевой код возврата
%PROGRAM% test-data\inputs\incorrect1.txt > %TEMP_FILE%
if NOT ERRORLEVEL 1 goto err
echo Test #4 passed!

%PROGRAM% test-data\inputs\incorrect2.txt > %TEMP_FILE%
if NOT ERRORLEVEL 1 goto err
echo Test #5 passed!

rem Запуск с корректными параметрами
%PROGRAM% test-data\inputs\matrix1.txt > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\invert1.txt > nul
if ERRORLEVEL 1 goto err
echo Test #6 passed!

%PROGRAM% test-data\inputs\matrix2.txt > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\invert2.txt > nul
if ERRORLEVEL 1 goto err
echo Test #7 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1