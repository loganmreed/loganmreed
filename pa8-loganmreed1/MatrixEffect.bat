@echo off
cls
echo Starting countdown...
for /L %%i in (10,-1,0) do (
  echo %%i
  timeout /t 1 >nul
)
echo Time's up!
