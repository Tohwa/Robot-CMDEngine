#!/bin/bash
cd "$( dirname "$0" )"

read -p "Generate XCode or GNU Make files [xcode4, gmake2]: " iversion

version=xcode4

if iversion=="xcode4" then version=xcode4
if iversion=="gmake2" then version=gmake2

pushd ../
ThirdParty/premake5-alpha15/premake5-macos clean
ThirdParty/premake5-alpha15/premake5-macos $version
popd

echo "Robot-CMDEngine $version project files were successfully generated"