cmake_minimum_required(VERSION 3.8)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE MinSizeRel)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg ")

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})

add_library(functions functions.cpp)
target_link_libraries(functions ${CURL_LIBRARIES}) # link curl to functions

add_executable(fibonacci main_fibonacci.cpp)
target_link_libraries(fibonacci functions)

add_executable(sleep main_sleep.cpp)
target_link_libraries(sleep functions)

add_executable(inefficient main_inefficient.cpp)
target_link_libraries(inefficient functions)

add_executable(download main_download.cpp)
target_link_libraries(download functions)

add_executable(run_all main.cpp)
target_link_libraries(run_all functions)
