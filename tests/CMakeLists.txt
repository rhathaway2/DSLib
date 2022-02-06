# Add GTest subdirectory in extern/
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_sample gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

# Macro for adding tests
macro(package_add_test TESTNAME)
    # Create an executable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # Link the google test infrastructure, mocking library, and a default main function to
    # the test executable.
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)

    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}")
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()
