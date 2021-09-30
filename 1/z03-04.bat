@echo off 
chcp 1251 > nul
set /a i=%1 + %2
set /a b=%1 * %2
set /a c=%3 / %2
set /a d=%3 - %1
set /a e=(d * (-d))
echo --строка параметров: %*
echo --параметр 1: %1
echo --параметр 2: %2
echo --параметр 3: %3
echo -- %1 + %2 = %i%
echo -- %1 * %2 = %b%
echo -- %3 / %2 = %c%
echo -- %3 - %1 = %d%
echo -- (%3 - %1)*(%1 - %3) = %e%