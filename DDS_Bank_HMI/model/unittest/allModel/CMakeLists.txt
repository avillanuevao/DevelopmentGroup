cmake_minimum_required(VERSION 3.14)

#file(GLOB_RECURSE REC_GTEST
#    /opt/devlib/googletest/include/*.h)

#enable_testing()
#find_package(GTest REQUIRED)

#include_directories(${REC_GTEST})

add_executable(allModelUnitTest
    AllModelTest.cpp)

target_link_libraries(allModelUnitTest
    PRIVATE GTest::gtest_main
    PRIVATE modelLib
)

gtest_discover_tests(allModelUnitTest)

message(STATUS "______________________HOLAAAAAAAAAAAAAAAAAa")
message(STATUS ${GTest_FOUND})
message(STATUS ${GTEST_INCLUDE_DIRS})
# no pilla los .h
