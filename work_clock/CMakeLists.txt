cmake_minimum_required(VERSION 3.10)

project(clock)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


include_directories("${PROJECT_SOURCE_DIR}/dll_files")
add_subdirectory(dll_files)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


add_executable(clock main.cpp hand.cpp help_function.cpp clock_face.cpp)
target_link_libraries(clock ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
