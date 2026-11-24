@echo off
setlocal
for /r %%f in (*.c) do (
  echo Compiling %%f
  gcc -std=c11 -Wall -Wextra -O2 "%%f" -o "%%~dpnf.exe" || exit /b 1
)
echo All programs compiled successfully.
