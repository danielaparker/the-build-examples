cmake_minimum_required (VERSION 3.9)

project (example)

set(EXAMPLES_PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(EXAMPLES_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

OPTION(BUILD_TESTS "examples tests" ON)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()


