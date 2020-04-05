cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME MonaServer)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Collecting a list of sources.
file(GLOB_RECURSE SOURCE_FILES sources/*.h sources/*.cpp)
#
set(PROJECT_LIBS MonaBase MonaCore)
#
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/MonaBase/include")
include_directories("${CMAKE_SOURCE_DIR}/MonaCore/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(
        ${PROJECT_NAME}
        ${PROJECT_LIBS}
        pthread
        crypto
        ssl
        luajit-5.1
)
