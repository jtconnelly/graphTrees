set(TARGET_HEADERS 
include/bst.h
include/trie.h
include/bTree.h
include/bTreeNode.h
include/red-black.h)

set(TARGET_SOURCE
src/bst.cpp
src/trie.cpp
src/bTree.cpp
src/red-black.cpp)


add_library(Trees SHARED ${TARGET_HEADERS} ${TARGET_SOURCE})
target_include_directories(Trees PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})
include(GenerateExportHeader)
generate_export_header(Trees)