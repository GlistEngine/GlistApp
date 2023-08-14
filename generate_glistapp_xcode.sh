export CC="/opt/homebrew/opt/llvm@15/bin/clang"
export CXX="/opt/homebrew/opt/llvm@15/bin/clang++"

BINARY_DIR="./../../zbin/glistzbin-macos/mingw64/lib"
BUILD_TYPE="Debug"

cmake . -G Xcode -B _build
xattr -w com.apple.quarantine "$(xattr -p com.apple.quarantine "$BINARY_DIR/libfmod.dylib" | sed 's/^.\{4\}/00c1/')" $BINARY_DIR/libfmod.dylib
xattr -w com.apple.quarantine "$(xattr -p com.apple.quarantine "$BINARY_DIR/libfmodL.dylib" | sed 's/^.\{4\}/00c1/')" $BINARY_DIR/libfmodL.dylib

cp -r "assets" "_build/$BUILD_TYPE"
cp "_build/_build/$BUILD_TYPE/libGlistEngine.dylib" "_build/$BUILD_TYPE"
