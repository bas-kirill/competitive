@ echo off
:1
echo good
gen.exe
alien.exe
own.exe
fc /L output.txt output_brut.txt 
if %errorlevel% == 0 goto 1
echo NeSovpalo
pause