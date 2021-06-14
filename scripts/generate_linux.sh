#!/bin/bash
cd "$( dirname "$0" )"

pushd ../
ThirdParty/premake5-alpha15/premake5-linux clean
ThirdParty/premake5-alpha15/premake5-linux gmake2
popd

echo "Robot-CMDEngine GNU Make project files were successfully generated"