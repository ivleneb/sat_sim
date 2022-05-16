cmake_minimum_required(VERSION 3.10.2)

message("Init test")

#project(testBen)
set(tar "test_ben")

find_package(GTest REQUIRED)
#enable_testing()

add_executable(${tar} test_sat.cpp)

set(CMAKE_CXX_STANDARD 11)

#target_link_libraries(${PROJECT_NAME} PUBLIC
#
#task
#gtest
#gtest_main
#
#)

message("${CONAN_LIBS}")
target_link_libraries(${tar} 
PRIVATE
GTest::GTest 
task
satelite
estacionterrena
 )

add_test(gtest_ben ${EXECUTABLE_OUTPUT_PATH}/${tar})
#include(GoogleTest)
#gtest_discover_tests(${tar})

message("End test")
