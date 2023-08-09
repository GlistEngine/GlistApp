
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd ~/dev/glist/myglistapps/GlistApp/build
  /opt/homebrew/opt/cmake/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
if test "$CONFIGURATION" = "Release"; then :
  cd ~/dev/glist/myglistapps/GlistApp/build
  /opt/homebrew/opt/cmake/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd ~/dev/glist/myglistapps/GlistApp/build
  /opt/homebrew/opt/cmake/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd ~/dev/glist/myglistapps/GlistApp/build
    /opt/homebrew/opt/cmake/bin/cmake -DBUILD_TYPE=$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P cmake_install.cmake
fi
