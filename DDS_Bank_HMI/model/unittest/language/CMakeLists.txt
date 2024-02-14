cmake_minimum_required(VERSION 3.14)

add_executable(LanguageEnglishUnitTest
    LanguageEnglishUnitTest.cpp)   

target_include_directories(LanguageEnglishUnitTest
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source
)

target_link_libraries(LanguageEnglishUnitTest
    PRIVATE GTest::gtest_main
    PRIVATE modelLib
)

gtest_discover_tests(LanguageEnglishUnitTest)

add_executable(LanguageSpanishUnitTest
    LanguageSpanishUnitTest.cpp)
    
target_include_directories(LanguageSpanishUnitTest
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source
)

target_link_libraries(LanguageSpanishUnitTest
    PRIVATE GTest::gtest_main
    PRIVATE modelLib
)

gtest_discover_tests(LanguageSpanishUnitTest)
