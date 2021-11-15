@echo off 
chcp 1251 > nul
echo -- строка параметров:%*
echo -- режим:%1
echo -- имя файла:%2

if "%1" == "" (
echo ---+ %~n0 режим файл
echo ---++ режим = {создать, удалить}
echo ---++ файл = имя файла
goto end
)

if "%2" == "" (
echo ---+ не задано имя файла
goto end
)
if "%1" == "удалить" (
if exist %2 (
del %2
echo ---+ файл %2 удалён
goto end 
)
echo ---+ файл %2 не найден
goto end
)
if "%1" == "создать" (
if exist %2 (
echo ---+ файл %2 уже есть
goto end
)
echo. 2>%2 
echo ---+ файл %2 создан
goto end
)
echo ---+ режим задан не корректно

:end






