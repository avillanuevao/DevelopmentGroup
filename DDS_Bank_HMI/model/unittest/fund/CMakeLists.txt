cmake_minimum_required(VERSION 3.14)

add_executable(fundUnitTest
    FundUnitTest.cpp)

target_include_directories(fundUnitTest
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source
)

target_link_libraries(fundUnitTest
    PRIVATE GTest::gtest_main
    PRIVATE modelLib
)

gtest_discover_tests(fundUnitTest)
