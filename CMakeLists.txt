cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME MonaServer)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
# set output folders
# libs
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all")
# executables
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all")
# libs .a
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib CACHE PATH "Single Directory for all")

add_subdirectory(MonaBase)
add_subdirectory(MonaCore)
add_subdirectory(MonaFilter)
add_subdirectory(MonaServer)
