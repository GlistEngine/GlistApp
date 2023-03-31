cmake_minimum_required (VERSION 3.10.2)


########## PROJECT NAME ##########
set(APP_NAME GlistApp)


########## USED PLUGINS LIST ##########
set(PLUGINS)


##################################################
# DO NOT CHANGE BELOW
##################################################

########## WINDOWS COMPILER PATH ##########
# Clang compiler definition for Windows. Do not change this value for other OS.
# For UNIX like systems, configure the compiler via OS commands.
if(WIN32)
set(CMAKE_C_COMPILER "${CMAKE_SOURCE_DIR}/../../zbin/glistzbin-win64/clang64/bin/clang.exe")
set(CMAKE_CXX_COMPILER "${CMAKE_SOURCE_DIR}/../../zbin/glistzbin-win64/clang64/bin/clang++.exe")
endif(WIN32)

########## CMAKE THING ##########
if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

########## PATHS AND VARIABLES ##########
set(APP_DIR ${CMAKE_SOURCE_DIR})
project (${APP_NAME})

set(TOP_DIR ${APP_DIR}/../..)
set(MAIN_DIR ${TOP_DIR}/GlistEngine)
set(ENGINE_DIR ${MAIN_DIR}/engine)

include(${ENGINE_DIR}/CMakeLists.txt)

########## SOURCE FILES AND INCLUDE DIRECTORIES ##########
add_executable(${APP_NAME} 
				${APP_DIR}/src/main.cpp
				${APP_DIR}/src/gApp.cpp
				${APP_DIR}/src/GameCanvas.cpp)


include_directories(${APP_NAME} PRIVATE
                        ${APP_DIR}/src)

########## LINKING ##########
# add lib dependencies
target_link_libraries(${APP_NAME}
                      GlistEngine)
				
