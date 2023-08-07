@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
echo ----------------- STARTING BUILD FOR AZURE ----------------
echo ...
devenv "Azure.sln" /build Debug
echo COPYING DLL TO SANDBOX
xcopy /s C:\dev\Azure\bin\Debug-x64\Azure\Azure.dll C:\dev\Azure\bin\Debug-x64\Sandbox\
echo ---------------------- BUILD COMPLETE ---------------------