@echo off 
chcp 1251 > nul
echo -- ������ ����������:%*
echo -- �����:%1
echo -- ��� �����:%2

if "%1" == "" (
echo ---+ %~n0 ����� ����
echo ---++ ����� = {�������, �������}
echo ---++ ���� = ��� �����
goto end
)

if "%2" == "" (
echo ---+ �� ������ ��� �����
goto end
)
if "%1" == "�������" (
if exist %2 (
del %2
echo ---+ ���� %2 �����
goto end 
)
echo ---+ ���� %2 �� ������
goto end
)
if "%1" == "�������" (
if exist %2 (
echo ---+ ���� %2 ��� ����
goto end
)
echo. 2>%2 
echo ---+ ���� %2 ������
goto end
)
echo ---+ ����� ����� �� ���������

:end






