@echo off

Vendor\Premake\premake5.exe --file=Build.lua vs2026

powershell -command "(New-Object -ComObject Shell.Application).Windows() | %% { $_.Refresh() }"

pause