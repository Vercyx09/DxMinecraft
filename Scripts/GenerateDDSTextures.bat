@echo off

..\Vendor\Texassemble\texassemble array ..\Assets\Textures\Blocks\*.png ..\Assets\Textures\__transparent.png ..\Assets\Textures\__invalid.png -o ..\Assets\Textures\Blocks\Output\blocks.dds -y

..\Vendor\Texconv\texconv ..\Assets\Textures\Blocks\Output\blocks.dds -m 5 -o ..\Assets\Textures\Blocks\Output\ -y

pause