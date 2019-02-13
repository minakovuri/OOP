@echo off

rem установка кодировки
chcp 1251

set PROGRAM="%~1"
set TEMP_FILE="%TEMP%\out.txt"
set PERMANENT_FILE="test-data\out.txt"

rem ------- ПРОВЕРКА ВЫПОЛНЕНИЯ ПРОГРАММЫ С НЕКОРРЕКТНЫМИ ВХОДНЫМИ ДАННЫМИ
rem запуск без параметров должен привести к ненулевому коду возврата
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1 passed!


rem запуск с некорректными значениями систем счисления (корректными явл. числа от 2 до 36) должен привести к ненулевому коду возврата
%PROGRAM% 37 10 1F
if NOT ERRORLEVEL 1 goto err
echo Test #2 passed!

%PROGRAM% 10 -1 1F
if NOT ERRORLEVEL 1 goto err
echo Test #3 passed!


rem запуск с неверным указанием системы счисления входного значения должен привести к ненулевому коду возврата
%PROGRAM% 10 16 1F
if NOT ERRORLEVEL 1 goto err
echo Test #4 passed!

%PROGRAM% 2 16 3
if NOT ERRORLEVEL 1 goto err
echo Test #5 passed!


rem запуск с входным значением, не входящим в пределы типа int (-2147483647 - 1; 2147483647) должен привести к ненулевому коду возврата
%PROGRAM% 36 10 ZZZZZZ
if NOT ERRORLEVEL 1 goto err
echo Test #6 passed!

%PROGRAM% 16 8 -FFFFFFFF
if NOT ERRORLEVEL 1 goto err
echo Test #7 passed!


rem ------ ТЕСТИРОВАНИЕ ПРОГРАММЫ С КОРРЕКТНЫМИ ДАННЫМИ

%PROGRAM% 10 16 2147483647 > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\MaxIntFrom10To16.txt > nul
if ERRORLEVEL 1 goto err
echo Test #8 passed!
rem NOTE! При переводе в 16-тиричную систему счисления отображаются маленькие буквы, а не заглавные""""  


echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1