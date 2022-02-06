# The first line of any CMake build looks like this.
cmake_minimum_required(VERSION 3.7...3.22)

# This is what new projects should do so that cmake policy gets set correctly
# on older versions of CMake.
if(${CMAKE_VERSION} VERSION_LESS 3.12)
        cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
        message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt")
endif()

project(DataStructures VERSION 1.0
		               DESCRIPTION "A basic data structure library"
                       LANGUAGES CXX)

# Add source subdirectory
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# Enable testing
option(BUILD_TESTS "Build the tests" ON)

# Only build tests for this project. Not when include by other project
if(PROJECT_NAME STREQUALS CMAKE_PROJECT_NAME AND BUILD_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()
