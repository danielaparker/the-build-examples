cmake_minimum_required (VERSION 3.9)

set(EXAMPLES_TARGET test_examples)

set(EXAMPLES_TESTS_DIR ${EXAMPLES_PROJECT_DIR}/tests)
set(EXAMPLES_TESTS_SOURCE_DIR ${EXAMPLES_PROJECT_DIR}/tests/src)
set(EXAMPLES_INCLUDE_DIR ${EXAMPLES_PROJECT_DIR}/include)
set(EXAMPLES_THIRD_PARTY_INCLUDE_DIR ${EXAMPLES_PROJECT_DIR}/third_party)

set(CATCH_INCLUDE_DIR ${EXAMPLES_THIRD_PARTY_INCLUDE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories (Catch INTERFACE ${CATCH_INCLUDE_DIR})

option(EXAMPLES_VALGRIND "Execute tests with valgrind" 0)

if(EXAMPLES_VALGRIND)
    find_program(CMAKE_MEMORYCHECK_COMMAND valgrind)
    message(STATUS "Executing test suite with Valgrind (${CMAKE_MEMORYCHECK_COMMAND})")
    set(memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1 --leak-check=full")
    separate_arguments(memcheck_command)
endif()

file(GLOB_RECURSE EXAMPLES_TESTS_SOURCES ${EXAMPLES_TESTS_SOURCE_DIR}/*.cpp)

include (CTest)

add_executable(${EXAMPLES_TARGET} EXCLUDE_FROM_ALL ${EXAMPLES_TESTS_SOURCES})
add_test(example_test example)

target_include_directories (${EXAMPLES_TARGET} PUBLIC ${EXAMPLES_INCLUDE_DIR})
target_link_libraries(${EXAMPLES_TARGET} Catch)

add_custom_target(jtest COMMAND test_examples DEPENDS ${EXAMPLES_TARGET})

