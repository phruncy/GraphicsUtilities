cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 11)

project(GraphicsUtilities CXX)

enable_testing()

option(BUILD_LIB_TESTS "Build the library tests" ON)

# don't build the tests by default 
if (BUILD_LIB_TESTS)
include_directories(${PROJECT_SOURCE_DIR}/external/googletest)
add_subdirectory(external/googletest)
add_subdirectory(Tests)
endif()

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)

set(GRAPHICSUTILS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/src)