cmake_minimum_required(VERSION 3.14)

# Search the files in the directory
file(GLOB_RECURSE UTILS_LIB
    ${PROJECT_SOURCE_DIR}/utils/*.hpp
    ${PROJECT_SOURCE_DIR}/utils/*.cpp)

list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)
find_package(RTIConnextDDS "6.1.0" REQUIRED COMPONENTS core routing_service)

# Add the library
add_library(utilsLib ${UTILS_LIB})

# Where the library's file saves
set_target_properties(utilsLib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/utils/)

# Configuring the include directories (headers files) of the library
target_include_directories(utilsLib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(utilsLib
    PUBLIC RTIConnextDDS::cpp2_api
    )
