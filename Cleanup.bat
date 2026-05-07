@echo off

del /q "*.sln" 2>nul
del /q "*.slnx" 2>nul

if exist "Build" (
    rmdir /s /q "Build"
)

if exist "Intermediate" (
    rmdir /s /q "Intermediate"
)

echo Successfuly cleaned up project files!

pause