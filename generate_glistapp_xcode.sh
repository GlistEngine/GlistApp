export CC="/opt/homebrew/opt/llvm@15/bin/clang"
export CC="/opt/homebrew/opt/llvm@15/bin/clang++"

cmake . -GXcode -B build

cd scripts/macos
sh install_assets.sh
