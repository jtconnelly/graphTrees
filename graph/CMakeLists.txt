set(TARGET_HEADERS
include/graph.h
include/searching.h
)

set(TARGET_SOURCE
src/graph.cpp
src/searching.cpp
)

add_library(Graphs SHARED ${TARGET_HEADERS} ${TARGET_SOURCE})
target_include_directories(Graphs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})
include(GenerateExportHeader)
generate_export_header(Graphs)
install(TARGETS Graphs RUNTIME DESTINATION bin)