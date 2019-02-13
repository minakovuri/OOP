@echo off

rem ��������� ���������
chcp 1251

set PROGRAM="%~1"
set TEMP_FILE="%TEMP%\out.txt"
set PERMANENT_FILE="test-data\out.txt"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1 passed!

rem ��� ������� � ������������ ������ �������� ����� ��������� ��� ��������
%PROGRAM% test-data\inputs\Unexisting.txt %TEMP_FILE% Hello Hi
if NOT ERRORLEVEL 1 goto err
echo Test #2 passed!

rem ��� ������� � ������ ������� ������ �� ��������� - �� ������ ������ ���� ���� ���������� ��������
%PROGRAM% test-data\inputs\Unchangable.txt %TEMP_FILE% "" "Some expression"
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\Unchanged.txt > nul
if ERRORLEVEL 1 goto err
echo Test #3 passed!

rem ������ ��������� � ������� ������ "Hello" �� "Hi"
%PROGRAM% test-data\inputs\Hello.txt %TEMP_FILE% "Hello" "Hi"
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\HelloToHi.txt > nul
if ERRORLEVEL 1 goto err
echo Test #4 passed!

rem ������ ��������� � ������� �������������� ���������
%PROGRAM% test-data\inputs\Unchangable.txt %TEMP_FILE% "Unexisting substring" "is cool"
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\Unchanged.txt > nul
if ERRORLEVEL 1 goto err
echo Test #5 passed!

rem ������ ��������� � ������� ������ "��" �� ������ "����" - �������� �� ������������
%PROGRAM% test-data\inputs\Mama.txt %TEMP_FILE% "����" "��"
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\MamaToMa.txt > nul
if ERRORLEVEL 1 goto err
echo Test #6 passed!

rem ������ ��������� � ������� ��������� "1231234" ������ "12312312345" �� ��������� "0"
%PROGRAM% test-data\inputs\Digits.txt %TEMP_FILE% "1231234" "0"
if ERRORLEVEL 1 goto err
fc %TEMP_FILE% test-data\expected-data\DigitsToZero.txt > nul
if ERRORLEVEL 1 goto err
echo Test #7 passed!

echo ----------------
echo All tests passed!
exit 0

:err
echo Test failed
exit 1
