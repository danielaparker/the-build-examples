cmake_minimum_required (VERSION 3.9)

project (example)

set(EXAMPLE_PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(EXAMPLE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(example INTERFACE $<BUILD_INTERFACE:${EXAMPLE_INCLUDE_DIR}>
                                           $<INSTALL_INTERFACE:include>)

add_executable(example src/example.cpp)
