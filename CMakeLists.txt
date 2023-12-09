cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(graphTrees)
include(CMakeOptions.cmake)

set(CMAKE_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if (INCLUDE_GRAPHS)
    add_subdirectory(graph)
endif()

if (INCLUDE_TREES)
    add_subdirectory(trees)
endif()

if (BUILD_TEST_EXE)
    enable_testing()
    add_subdirectory(test)
endif()