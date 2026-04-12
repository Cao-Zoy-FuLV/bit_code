::  生成一个运行当前文件夹内的exe文件的bat
:: <code>
@echo off
setlocal ::
::  %~dp0 - 当前脚本所在驱动器和路
::  查询到当前路径 运行第一个exe文件
::  %%f - 在 .bat 文件中使用的变量（需要双百分号转义
for %%f in ("%~dp0*.exe") do (
    start "" "%%f"
    exit /b 0
)