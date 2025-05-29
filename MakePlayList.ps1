$deployFolder = '.\deploy'
$installFolder = '.\build\installer'
$exeFile = '.\build\Desktop_Qt_6_9_0_MSVC2022_64bit-Release\MakePlayList.exe'
$winDeployQT = 'C:\Qt\6.9.0\msvc2022_64\bin\windeployqt6.exe'
$innoSetup = 'C:\Users\yoshia\AppData\Local\Programs\Inno Setup 6\ISCC.exe'

if (Test-Path $deployFolder) {
  Remove-Item -Path $deployFolder -Recurse -Force
}

New-Item -Path . -Name $deployFolder -ItemType "Directory"

if ((Test-Path $installFolder) -ne $true) {
  New-Item $installFolder -ItemType "Directory"
}

if (Test-Path $exeFile) {
  Start-Process -FilePath $winDeployQT -ArgumentList "--dir $deployFolder $exeFile" -NoNewWindow -Wait
  Start-Process -FilePath $innoSetup -ArgumentList "MakePlayList.iss" -NoNewWindow -Wait
} else {
  Write-Host "実行ファイルがありません"
}

pause

