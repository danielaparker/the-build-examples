cmake_minimum_required (VERSION 3.9)

project (example)
OPTION(BUILD_TESTS "jsoncons test suite" ON)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()


