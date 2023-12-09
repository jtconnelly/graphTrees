
if (INCLUDE_GRAPHS)
    add_executable(TestGraph testGraph.cpp)
    target_link_directories(TestGraph PUBLIC ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    target_link_libraries(TestGraph PUBLIC Graphs)
    target_compile_definitions(TestGraph PUBLIC TEST_GRAPHS)
    add_test(NAME TestGraphs
        COMMAND TestGraph)
endif()
if (INCLUDE_TREES)
    add_executable(TestTree testTree.cpp)
    target_link_directories(TestTree PUBLIC ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    target_link_libraries(TestTree PUBLIC Trees)
    target_compile_definitions(TestTree PUBLIC TEST_TREES)
    add_test(NAME TestTrees
        COMMAND TestTree)
endif()