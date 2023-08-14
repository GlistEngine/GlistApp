if(APPLE)
	cmake_minimum_required (VERSION 3.26)
else()
	cmake_minimum_required (VERSION 3.10.2)
endif()

########## PROJECT NAME ##########
set(APP_NAME GlistApp)


########## USED PLUGINS LIST ##########
set(PLUGINS)


##################################################
# DO NOT CHANGE BELOW
##################################################

########## CMAKE THING ##########
if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()


########## WINDOWS COMPILER PATH ##########
# Clang compiler definition for Windows. Do not change this value for other OS.
# For UNIX like systems, configure the compiler via OS commands.
if(WIN32)
	set(CMAKE_C_COMPILER "${CMAKE_SOURCE_DIR}/../../zbin/glistzbin-win64/clang64/bin/clang.exe")
	set(CMAKE_CXX_COMPILER "${CMAKE_SOURCE_DIR}/../../zbin/glistzbin-win64/clang64/bin/clang++.exe")
endif(WIN32)


########## MACOS ARCHITECTURE ##########
EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE DEVICEARCHITECTURE )
message( STATUS "Architecture: ${DEVICEARCHITECTURE}" )

set(GLIST_CXX_FLAGS_RELEASE)
set(GLIST_CXX_FLAGS_DEBUG)

if(APPLE)
if(NOT ${DEVICEARCHITECTURE} STREQUAL "arm64")
    set(GLIST_CXX_FLAGS_RELEASE "-march=x86-64")
    set(GLIST_CXX_FLAGS_DEBUG "-march=x86-64")
    set(SYS_NAME "macos-x86_64")
    set(SYS_PATH "/usr/local")
    set(BREW_PATH "${SYS_PATH}/opt")
    set(SYS_INC_PATH "${SYS_PATH}/include")
    set(CMAKE_C_COMPILER "/usr/local/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")
    set(ENGINE_USE_SYMLINKS ON)
else()
    set(SYS_NAME "macos")
    set(SYS_PATH "/opt/homebrew")
    set(BREW_PATH "${SYS_PATH}/opt")
    set(SYS_INC_PATH "${SYS_PATH}/include")
    set(CMAKE_C_COMPILER "${BREW_PATH}/llvm/bin/clang")
    set(CMAKE_CXX_COMPILER "${BREW_PATH}/llvm/bin/clang++")
    set(ENGINE_USE_SYMLINKS ON)
endif()
endif(APPLE)


########## PATHS AND VARIABLES ##########
set(APP_DIR ${CMAKE_SOURCE_DIR})
project (${APP_NAME})

set(TOP_DIR ${APP_DIR}/../..)
set(MAIN_DIR ${TOP_DIR}/GlistEngine)
set(ENGINE_DIR ${MAIN_DIR}/engine)

if(APPLE)
	add_subdirectory(${ENGINE_DIR} ./build)
else()
	include(${ENGINE_DIR}/CMakeLists.txt)
endif()

########## SOURCE FILES AND INCLUDE DIRECTORIES ##########

if(APPLE)
	set(GlistApp_SOURCES
		${APP_DIR}/src/main.cpp
		${APP_DIR}/src/gApp.cpp
		${APP_DIR}/src/gCanvas.cpp
	)
	
	set(GlistApp_HEADERS
		${APP_DIR}/src/gApp.h
		${APP_DIR}/src/gCanvas.h
	)
	
	add_executable(${APP_NAME}
	                ${GlistApp_SOURCES}
	                ${GlistApp_HEADERS}
	)
else()
	add_executable(${APP_NAME} 
				${APP_DIR}/src/main.cpp
				${APP_DIR}/src/gApp.cpp
				${APP_DIR}/src/gCanvas.cpp)
endif()

set_target_properties(
    ${APP_NAME}
        PROPERTIES
            CXX_STANDARD 14
            CXX_STANDARD_REQUIRED True
)

if(APPLE)
	target_include_directories(
	    ${APP_NAME}
	        PRIVATE
	            ${APP_DIR}/src
	            ${BREW_PATH}/llvm@15/include/c++/v1
	)
else()
	include_directories(${APP_NAME} PRIVATE
                        ${APP_DIR}/src)
endif()

########## LINKING ##########
# add lib dependencies
target_link_libraries(${APP_NAME} PRIVATE GlistEngine)

install(
    DIRECTORY assets
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>
)
