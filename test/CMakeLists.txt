cmake_minimum_required(VERSION 3.10)

# collect all test files
file(GLOB_RECURSE DATURE_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cpp")

foreach(dature_test_source ${DATURE_TEST_SOURCES})

    # get executable file name
    get_filename_component(dature_test_filename ${dature_test_source} NAME)
    string(REPLACE ".cpp" "" dature_test_name ${dature_test_filename})
    # add executable file for each source file
    add_executable(${dature_test_name} ${dature_test_source})
    # link the dature library
    target_link_libraries(${dature_test_name} dature)
    
    set_target_properties(${dature_test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
        COMMAND ${dature_test_name}
    )

endforeach()
