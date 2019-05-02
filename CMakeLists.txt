cmake_minimum_required (VERSION 3.9)

project (example)

set(EXAMPLE_TARGET example)

set(EXAMPLE_PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(EXAMPLE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

option(JSONCONS_VALGRIND "Execute tests with valgrind" 0)

if(JSONCONS_VALGRIND)
    find_program(CMAKE_MEMORYCHECK_COMMAND valgrind)
    message(STATUS "Executing test suite with Valgrind (${CMAKE_MEMORYCHECK_COMMAND})")
    set(memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1 --leak-check=full")
    separate_arguments(memcheck_command)
endif()

include (CTest)

add_executable(${EXAMPLE_TARGET} src/example.cpp)
add_test(example_test example)

target_include_directories (${EXAMPLE_TARGET} PUBLIC ${EXAMPLE_INCLUDE_DIR})

