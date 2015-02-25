cmake_minimum_required(VERSION 2.8.4)
project(LUNA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "/Users/sandrospina/ClionProjects/LUNA/cmake/;${CMAKE_MODULE_PATH}")

set(BOX2D_INCLUDE_DIR "/opt/local/include/")
set(BOX2D_LIBRARY "/opt/local/lib/libBox2D.dylib")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${BOX2D_INCLUDE_DIR})

set(SOURCE_FILES main.cpp device.cpp entity.cpp stringify.cpp filemanager.cpp bglayer.cpp)
add_executable(LUNA ${SOURCE_FILES})
target_link_libraries(LUNA ${SDL2_LIBRARY} ${BOX2D_LIBRARY})