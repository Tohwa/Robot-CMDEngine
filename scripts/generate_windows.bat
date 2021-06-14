::This script generates project files for the windows IDE Visual Studio

@echo off

set /p ivsVersion="Please select a Visual Studio version [vs2019, vs2017, vs2015, vs2013, vs2012, vs2010, vs2008, vs2005]: "

::vs2019 is the only tested version
SET vsVersion=vs2019

IF "%ivsVersion%"=="vs2019" SET vsVersion=vs2019

::It is not guranteed that the vs versions below work with the source code 
IF "%ivsVersion%"=="vs2017" SET vsVersion=vs2017
IF "%ivsVersion%"=="vs2015" SET vsVersion=vs2015
IF "%ivsVersion%"=="vs2013" SET vsVersion=vs2013
IF "%ivsVersion%"=="vs2012" SET vsVersion=vs2012
IF "%ivsVersion%"=="vs2010" SET vsVersion=vs2010
IF "%ivsVersion%"=="vs2008" SET vsVersion=vs2008
IF "%ivsVersion%"=="vs2005" SET vsVersion=vs2005

pushd %~dp0\..\

call ThirdParty\premake5-alpha15\premake5-windows.exe clean
call ThirdParty\premake5-alpha15\premake5-windows.exe %vsVersion%

popd

echo Robot-CMDEngine Visual Studio 2019 project files were successfully generated
pause