cmake_minimum_required (VERSION 3.9)

project (example)

set(EXAMPLE_TARGET test_examples)

set(EXAMPLE_TESTS_DIR ${EXAMPLE_PROJECT_DIR}/tests)
set(EXAMPLE_TESTS_SOURCE_DIR ${EXAMPLE_PROJECT_DIR}/tests/src)
set(EXAMPLE_INCLUDE_DIR ${EXAMPLE_PROJECT_DIR}/include)
set(EXAMPLE_THIRD_PARTY_INCLUDE_DIR ${EXAMPLE_PROJECT_DIR}/third_party)

set(CATCH_INCLUDE_DIR ${EXAMPLE_THIRD_PARTY_INCLUDE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories (Catch INTERFACE ${CATCH_INCLUDE_DIR})

option(EXAMPLE_VALGRIND "Execute tests with valgrind" 0)

if(EXAMPLE_VALGRIND)
    find_program(CMAKE_MEMORYCHECK_COMMAND valgrind)
    message(STATUS "Executing test suite with Valgrind (${CMAKE_MEMORYCHECK_COMMAND})")
    set(memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1 --leak-check=full")
    separate_arguments(memcheck_command)
endif()

file(GLOB_RECURSE EXAMPLE_TESTS_SOURCES ${EXAMPLE_TESTS_SOURCE_DIR}/*.cpp)

include (CTest)

add_executable(${EXAMPLE_TARGET} EXCLUDE_FROM_ALL ${EXAMPLE_TESTS_SOURCES})
add_test(example_test example)

target_include_directories (${EXAMPLE_TARGET} PUBLIC ${EXAMPLE_INCLUDE_DIR})
target_link_libraries(${EXAMPLE_TARGET} Catch)

add_custom_target(jtest COMMAND test_examples DEPENDS ${EXAMPLE_TARGET})

