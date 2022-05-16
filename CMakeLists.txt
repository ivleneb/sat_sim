cmake_minimum_required(VERSION 3.9.1)
message("Init ROOT")
project(MySatSys)

#include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)

#conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

#add_library(math STATIC lib/math/operations.cpp)

message(" ${CMAKE_SOURCE_DIR}")
message(" ${CMAKE_BINARY_DIR}")
message(" ${LIBRARY_OUTPUT_PATH}")
message(" ${CONAN_LIBS} ")

enable_testing()
add_subdirectory(lib/satelite)
add_subdirectory(lib/task)
add_subdirectory(lib/estacionterrena)
add_subdirectory(test)

add_executable(sat_sys main.cpp)
target_link_libraries(sat_sys satelite task estacionterrena)
message("END ROOT")
