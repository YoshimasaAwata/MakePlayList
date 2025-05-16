set DEPLOYFOLDER=".\deploy"
set INSTALLFOLDER=".\build\installer"
set EXEFILE=".\build\Desktop_Qt_6_9_0_MinGW_64_bit-Release\MakePlayList.exe"
set WINDEPLOYQT="C:\Qt\6.9.0\mingw_64\bin\windeployqt.exe"
set INNOSETUP="C:\Users\yoshia\AppData\Local\Programs\Inno Setup 6\ISCC.exe"
set CXXCOMPILER="C:\Qt\Tools\mingw1310_64\bin\g++.exe"
set CCOMPILER="C:\Qt\Tools\mingw1310_64\bin\gcc.exe"
set BUILDTARGETDIR=".\build\Desktop_Qt_6_9_0_MinGW_64_bit-Release"
set CMAKE="C:\Qt\Tools\CMake_64\bin\cmake.exe"

if exist %DEPLOYFOLDER% (
  rmdir /s /q %DEPLOYFOLDER%
)

mkdir %DEPLOYFOLDER%

if not exist %INSTALLFOLDER% (
  mkdir %INSTALLFOLDER%
)

%CMAKE% -S . -B %BUILDTARGETDIR% -DCMAKE_CXX_COMPILER=%CXXCOMPILER% -DCMAKE_C_COMPILER=%CCOMPILER% -DCMAKE_BUILD_TYPE=Release && %CMAKE% --build %BUILDTARGETDIR% && %WINDEPLOYQT% --dir %DEPLOYFOLDER% %EXEFILE% && %INNOSETUP% MakePlayList.iss

cmd /k
