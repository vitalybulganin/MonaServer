cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME MonaFilter)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Collecting a list of sources.
file(GLOB_RECURSE SOURCE_FILES *.h *.cpp)
#
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
