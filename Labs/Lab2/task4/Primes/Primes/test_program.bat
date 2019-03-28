@echo off

rem установка кодировки
chcp 1251

set PROGRAM="%~1"

rem ------- ТЕСТИРОВАНИЕ ПРОГРАММЫ С НЕКОРРЕКТНЫМИ ВХОДНЫМИ ДАННЫМИ
echo ------ RUN PROGRAM WITH INCORRECT INPUT PARAMS ------

rem запуск без параметров должен привести к ненулевому коду возврата
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1.1 passed!

rem запуск с большмим кол-вом должен привести к ненулевому коду возврата
%PROGRAM% 12 13
if NOT ERRORLEVEL 1 goto err
echo Test #1.2 passed!

rem запуск с некорректным параметром должен привести к ненулевому коду возврата
%PROGRAM% 9AF
if NOT ERRORLEVEL 1 goto err
echo Test #1.3 passed!

rem запуск с некорректным параметром должен привести к ненулевому коду возврата
%PROGRAM% 100000001
if NOT ERRORLEVEL 1 goto err
echo Test #1.4 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1