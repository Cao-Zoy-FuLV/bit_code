$exeFile = Get-ChildItem -Path $PSScriptRoot -Filter *.exe | Select-Object -First 1
if ($exeFile)
{
    Start-Process -FilePath $exeFile.FullName
    exit
}