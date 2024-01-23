cmake_minimum_required(VERSION 3.14)

add_executable(allFundsUnitTest
    AllFundsUnitTest.cpp)

target_include_directories(allFundsUnitTest
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source
)

target_link_libraries(allFundsUnitTest
    PRIVATE GTest::gtest_main
    PRIVATE modelLib
)

gtest_discover_tests(allFundsUnitTest)
