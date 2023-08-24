#!/bin/sh

export CC="/opt/homebrew/opt/llvm/bin/clang"
export CXX="/opt/homebrew/opt/llvm/bin/clang++"

BINARY_DIR="./../../zbin/glistzbin-macos/mingw64/lib"
BUILD_TYPE="Debug"
GLISTWD="$(pwd)"
BUILD_DIR="$GLISTWD/_build"

cmake . -G Xcode -B _build
xattr -w com.apple.quarantine "$(xattr -p com.apple.quarantine "$BINARY_DIR/libfmod.dylib" | sed 's/^.\{4\}/00c1/')" $BINARY_DIR/libfmod.dylib
xattr -w com.apple.quarantine "$(xattr -p com.apple.quarantine "$BINARY_DIR/libfmodL.dylib" | sed 's/^.\{4\}/00c1/')" $BINARY_DIR/libfmodL.dylib

if [ ! -d "$BUILD_DIR/$BUILD_TYPE" ]
then
    cd $BUILD_DIR
    mkdir $BUILD_TYPE
fi
cd $BUILD_DIR/$BUILD_TYPE
mkdir assets

cd $GLISTWD

cp -r "assets/" "_build/$BUILD_TYPE/assets/"

open _build/GlistApp.xcodeproj
