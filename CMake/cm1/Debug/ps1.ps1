#Get-ChildItem - 获取子项（类似 ls 或 dir）
#-Path $PSScriptRoot - 当前脚本所在目录
#-Filter *.exe - 只筛选 .exe 文件
#| - 管道符，将前一个命令的输出传递给下一个
#Select-Object -First 1 - 只选择第一个结果

$exeFile = Get-ChildItem -Path $PSScriptRoot -Filter *.exe | Select-Object -First 1
if ($exeFile)
{
    #    Start-Process - PowerShell 命令，用于启动进程/程序
    #    -FilePath - 指定要运行的文件路径
    #    $exeFile.FullName - exe 文件的完整路径（如 F:\L\bit_code\CMake\cm1\Debug\CM1.exe）
    Start-Process -FilePath $exeFile.FullName
    exit
}