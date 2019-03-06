@echo off

rem установка кодировки
chcp 1251

set PROGRAM="%~1"
set TEMP_FILE_CRYPT="%TEMP%\out1.txt"
set TEMP_FILE_DECRYPT="%TEMP%\out2.txt"
set PERMANENT_FILE="test-data\out.txt"

rem ------- ТЕСТИРОВАНИЕ ПРОГРАММЫ С НЕКОРРЕКТНЫМИ ВХОДНЫМИ ДАННЫМИ
echo ------ RUN PROGRAM WITH INCORRECT INPUT PARAMS ------

rem запуск без параметров должен привести к ненулевому коду возврата
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1.1 passed!

rem запуск с указанием некорректного режима должен привести к ненулевому коду возврата
%PROGRAM% CREATE in.txt out.txt 10
if NOT ERRORLEVEL 1 goto err
echo Test #1.2 passed!

rem запуск с указанием некорректных входных файлов должен привести к ненулевому коду возврата
%PROGRAM% crypt unexisting.txt out.txt 12
if NOT ERRORLEVEL 1 goto err
echo Test #1.3 passed!

rem запуск с указанием некорректного ключа должен привести к ненулевому коду возврата
%PROGRAM% crypt test-data\inputs\input1.txt %TEMP_FILE_CRYPT% -2
if NOT ERRORLEVEL 1 goto err
echo Test #1.4 passed!

%PROGRAM% decrypt test-data\inputs\input1.txt %TEMP_FILE_DECRYPT% 512
if NOT ERRORLEVEL 1 goto err
echo Test #1.5 passed!

%PROGRAM% crypt test-data\inputs\input1.txt %TEMP_FILE_CRYPT%
if NOT ERRORLEVEL 1 goto err
echo Test #1.6 passed!

rem ------ ТЕСТИРОВАНИЕ ПРОГРАММЫ С КОРРЕКТНЫМИ ДАННЫМИ
echo ------ RUN PROGRAM WITH CORRECT INPUT PARAMS ------

rem запуск программы сначала в режиме шифрования, затем в режиме дешифрования - в результате должен получиться исходный файл
%PROGRAM% crypt test-data\inputs\input1.txt %TEMP_FILE_CRYPT% 12
if ERRORLEVEL 1 goto err
%PROGRAM% decrypt %TEMP_FILE_CRYPT% %TEMP_FILE_DECRYPT% 12
if ERRORLEVEL 1 goto err
fc %TEMP_FILE_DECRYPT% test-data\inputs\input1.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.1 passed!

rem запуск программы в режиме шифрования и проверка разности исходного файла и выходного
%PROGRAM% crypt test-data\inputs\input1.txt %TEMP_FILE_CRYPT% 12
if ERRORLEVEL 1 goto err
fc %TEMP_FILE_CRYPT% test-data\inputs\input1.txt > nul
if NOT ERRORLEVEL 1 goto err
echo Test #2.2 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1