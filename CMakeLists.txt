cmake_minimum_required (VERSION 3.10.2)


########## PROJECT NAME ##########
set(APP_NAME GlistApp)



########## USED PLUGINS LIST ##########
set(PLUGINS)



########## DO NOT CHANGE BELOW ##########
set(APP_DIR ${CMAKE_SOURCE_DIR})
project (${APP_NAME})

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

set(TOP_DIR ${APP_DIR}/../..)
set(MAIN_DIR ${TOP_DIR}/glistengine)
set(ENGINE_DIR ${MAIN_DIR}/engine)

include(${ENGINE_DIR}/CMakeLists.txt)

add_executable(${APP_NAME} 
				${APP_DIR}/src/main.cpp
				${APP_DIR}/src/gApp.cpp
				${APP_DIR}/src/GameCanvas.cpp)


include_directories(${APP_NAME} PRIVATE
                        ${APP_DIR}/src)
                        
# add lib dependencies
target_link_libraries(${APP_NAME}
                      GlistEngine)
				
