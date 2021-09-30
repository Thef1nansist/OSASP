@echo off 
chcp 1251 > nul
@echo -- имя этого файла: %~n0
@echo -- этот bat-файл создан:%~t0
@echo -- путь bat-файла: %~dpnx0
