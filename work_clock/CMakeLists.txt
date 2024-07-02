cmake_minimum_required(VERSION 3.7)

project(clock)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(clock main.cpp hand.cpp clock_face.cpp help_function.cpp)
target_link_libraries(clock ${SDL2_LIBRARIES}) # libjpeg-9.dll libpng16-16.dll libtiff-5.dll libwebp-7.dll zlib.dll

