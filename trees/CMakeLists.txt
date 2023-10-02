add_library(Trees SHARED bst.cpp bst.h bTree.cpp bTree.h trie.cpp trie.h)

target_include_directories(Trees PUBLIC CMAKE_CURRENT_SOURCE_DIR)