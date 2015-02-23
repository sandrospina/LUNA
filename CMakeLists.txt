cmake_minimum_required(VERSION 2.8.4)
project(LUNA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "/Users/sandrospina/ClionProjects/LUNA/cmake/;${CMAKE_MODULE_PATH}")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES main.cpp device.cpp entity.cpp)
add_executable(LUNA ${SOURCE_FILES})
target_link_libraries(LUNA ${SDL2_LIBRARY})