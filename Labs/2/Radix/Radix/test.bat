@echo off

rem ��������� ���������
chcp 1251

set PROGRAM="%~1"
set TEMP_FILE="%TEMP%\out.txt"
set PERMANENT_FILE="test-data\out.txt"

rem ------- ������������ ��������� � ������������� �������� �������
echo ------ RUN PROGRAM WITH INCORRECT INPUT PARAMS ------

rem ������ ��� ���������� ������ �������� � ���������� ���� ��������
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1.1 passed!


rem ������ � ������������� ���������� ������ ��������� (����������� ���. ����� �� 2 �� 36) ������ �������� � ���������� ���� ��������
%PROGRAM% 37 10 1F
if NOT ERRORLEVEL 1 goto err
echo Test #1.2 passed!

%PROGRAM% 10 -1 1F
if NOT ERRORLEVEL 1 goto err
echo Test #1.3 passed!


rem ������ � �������� ��������� ������� ��������� �������� �������� ������ �������� � ���������� ���� ��������
%PROGRAM% 10 16 1F
if NOT ERRORLEVEL 1 goto err
echo Test #1.4 passed!

%PROGRAM% 2 16 3
if NOT ERRORLEVEL 1 goto err
echo Test #1.5 passed!


rem ������ � ������� ���������, �� �������� � ������� ���� int (-2147483647 - 1; 2147483647) ������ �������� � ���������� ���� ��������
%PROGRAM% 36 10 ZZZZZZ
if NOT ERRORLEVEL 1 goto err
echo Test #1.6 passed!

%PROGRAM% 16 8 -FFFFFFFF
if NOT ERRORLEVEL 1 goto err
echo Test #1.7 passed!


rem ------ ������������ ��������� � ����������� �������
echo ------ RUN PROGRAM WITH CORRECT INPUT PARAMS ------

rem 10 -> 16
%PROGRAM% 10 16 2147483647 > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\MaxIntFrom10To16.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.1 passed!

rem 2 -> 8
%PROGRAM% 2 8 011011 > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\From2To8.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.2 passed!

rem 4 -> 3
%PROGRAM% 4 3 32 > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\From4To3.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.3 passed!

rem 12 -> 36
%PROGRAM% 12 36 AB > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\From12To36.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.4 passed!

rem 20 -> 5
%PROGRAM% 20 5 C0G > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\From20To5.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.5 passed!

rem 35 -> 6
%PROGRAM% 35 6 F00 > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\From35To6.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.6 passed!

rem 34 -> 7
%PROGRAM% 34 7 CED > %TEMP_FILE%
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\From34To7.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.7 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1
