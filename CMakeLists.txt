cmake_minimum_required (VERSION 3.9)

project (example)

set(EXAMPLE_TARGET example)

set(EXAMPLE_PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(EXAMPLE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(example src/example.cpp)

target_include_directories(${EXAMPLE_TARGET} INTERFACE $<BUILD_INTERFACE:${EXAMPLE_INCLUDE_DIR}>
                                           $<INSTALL_INTERFACE:include>)

#  “generator expressions” with the syntax $<...>.

