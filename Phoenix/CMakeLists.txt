#cmake min file requiremnt
cmake_minimum_required(VERSION 3.6)

#project name
project(Phoenix)

#project source directory
#add_subdirectory(Phoenix)
#add_subdirectory(GamePlayground)

file(GLOB SOURCES
    Phoenix/*.cpp
    Phoenix/*.h
    GamePlayground/Main.cpp
    GamePlayground/*.cpp
    GamePlayground/*.h
    )

#set c++ compiler flags
# Wall = all compiler warnings
set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -lBox2D")

#add include files
#include_directories("../include")

set(EXECUTABLE_NAME "phoenix")
#the exec file
add_executable(${EXECUTABLE_NAME} 
    ${SOURCES}
    )
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})