add_library(Graphs SHARED graph.cpp graph.h searching.cpp searching.h)
target_include_directories(Graphs PUBLIC CMAKE_CURRENT_SOURCE_DIR)