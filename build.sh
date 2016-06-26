#!/usr/bin/bash

set -e

name=torrent-file-editor

git clean -dfx . -e linux -e linux-qt5 -e CMakeLists.txt.user
mkdir win32
pushd win32
mingw32-cmake .. -DCMAKE_EXE_LINKER_FLAGS=-static -DCMAKE_BUILD_TYPE=Release
make -j5
version=$(cat version)
mv ${name}.exe ../${name}-${version}-x32.exe
popd

mkdir win64
pushd win64
mingw64-cmake .. -DCMAKE_EXE_LINKER_FLAGS=-static -DCMAKE_BUILD_TYPE=Release
make -j5
version=$(cat version)
mv ${name}.exe ../${name}-${version}-x64.exe
popd
