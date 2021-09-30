@echo off 
chcp 1251 > nul
set /a i= %1 %3 %2
echo --строка параметров: %*
echo --параметр 1: %1
echo --параметр 2: %2
echo --параметр 3: %3
echo Результат: %i%
