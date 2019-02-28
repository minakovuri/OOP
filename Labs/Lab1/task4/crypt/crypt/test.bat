@echo off

rem ��������� ���������
chcp 1251

set PROGRAM="%~1"
set TEMP_FILE_CRYPT="%TEMP%\out1.txt"
set TEMP_FILE_DECRYPT="%TEMP%\out2.txt"
set PERMANENT_FILE="test-data\out.txt"

rem ------- ������������ ��������� � ������������� �������� �������
echo ------ RUN PROGRAM WITH INCORRECT INPUT PARAMS ------

rem ������ ��� ���������� ������ �������� � ���������� ���� ��������
%PROGRAM%
if NOT ERRORLEVEL 1 goto err
echo Test #1.1 passed!

rem ������ � ��������� ������������� ������ ������ �������� � ���������� ���� ��������
%PROGRAM% CREATE in.txt out.txt 10
if NOT ERRORLEVEL 1 goto err
echo Test #1.2 passed!

rem ������ � ��������� ������������ ������� ������ ������ �������� � ���������� ���� ��������
%PROGRAM% crypt unexisting.txt out.txt 12
if NOT ERRORLEVEL 1 goto err
echo Test #1.3 passed!

rem ������ � ��������� ������������� ����� ������ �������� � ���������� ���� ��������
%PROGRAM% crypt test-data\inputs\input1.txt %TEMP_FILE_CRYPT% -2
if NOT ERRORLEVEL 1 goto err
echo Test #1.4 passed!

%PROGRAM% decrypt test-data\inputs\input1.txt %TEMP_FILE_DECRYPT% 512
if NOT ERRORLEVEL 1 goto err
echo Test #1.5 passed!

rem ------ ������������ ��������� � ����������� �������
echo ------ RUN PROGRAM WITH CORRECT INPUT PARAMS ------

rem ������ ��������� ������� � ������ ����������, ����� � ������ ������������ - � ���������� ������ ���������� �������� ����
%PROGRAM% crypt test-data\inputs\input1.txt %TEMP_FILE_CRYPT% 12
if ERRORLEVEL 1 goto err
%PROGRAM% decrypt %TEMP_FILE_CRYPT% %TEMP_FILE_DECRYPT% 12
if ERRORLEVEL 1 goto err
fc %TEMP_FILE_DECRYPT% test-data\inputs\input1.txt > nul
if ERRORLEVEL 1 goto err
echo Test #2.1 passed!

echo ----------------
echo All tests passed!
exit 0


:err
echo Test failed
exit 1