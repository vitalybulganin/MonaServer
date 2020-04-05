cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME MonaCore)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Collecting a list of sources.
file(GLOB_RECURSE SOURCE_FILES sources/*.h sources/*.cpp)
#
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/MonaBase/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(${PROJECT_NAME} SHARED ${INCLUDE_FILES} ${SOURCE_FILES})
