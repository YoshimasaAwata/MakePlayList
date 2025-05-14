set DEPLOYFOLDER=".\deploy"
set INSTALLFOLDER=".\build\installer"
set EXEFILE=".\build\Desktop_Qt_6_9_0_MinGW_64_bit-Release\MakePlayList.exe"
set WINDEPLOYQT="C:\Qt\6.9.0\mingw_64\bin\windeployqt.exe"
set INNOSETUP="C:\Users\yoshia\AppData\Local\Programs\Inno Setup 6\ISCC.exe"

if exist %DEPLOYFOLDER% (
  rmdir /s /q %DEPLOYFOLDER%
)

mkdir %DEPLOYFOLDER%

if not exist %INSTALLFOLDER% (
  mkdir %INSTALLFOLDER%
)

%WINDEPLOYQT% --dir %DEPLOYFOLDER% %EXEFILE% && %INNOSETUP% MakePlayList.iss

cmd /k
