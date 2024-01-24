cmake_minimum_required(VERSION 3.14)

# -------------------------------------------- RECURSES ------------------------------------------------------

file(GLOB_RECURSE PACKAGE_BACKEND
    ${PROJECT_SOURCE_DIR}/backend/*.hpp
    ${PROJECT_SOURCE_DIR}/backend/*.cpp)

file(GLOB_RECURSE IDL
    ${PROJECT_SOURCE_DIR}/idl/*.hpp
    ${PROJECT_SOURCE_DIR}/idl/*.cxx)
# -------------------------------------------- RECURSES ------------------------------------------------------

# ------------------------------------------- PROJECT SOURCES ------------------------------------------------
set(PROJECT_SOURCES_BACKEND
    ${IDL}
    ${PACKAGE_BACKEND}
    ${PROJECT_SOURCE_DIR}/mainBack.cpp
    )
# ------------------------------------------- PROJECT SOURCES ------------------------------------------------
# ----------------------------------------- GENERING EXECUTABLE ----------------------------------------------

add_executable(BACKEND
    ${PROJECT_SOURCES_BACKEND}
    )
# ----------------------------------------- GENERING EXECUTABLE ----------------------------------------------

# ---------------------------------- CONFIGURATION EXECUTABLE BACKEND ----------------------------------------
target_include_directories(BACKEND
    PUBLIC ${PROJECT_SOURCE_DIR}/
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source
    PUBLIC ${PROJECT_SOURCE_DIR}/utils
)

target_link_libraries(BACKEND
    PUBLIC RTIConnextDDS::cpp2_api
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source/libmodelLib.so
    PUBLIC ${PROJECT_SOURCE_DIR}/utils/libutilsLib.a
    )
# ---------------------------------- CONFIGURATION EXECUTABLE BACKEND ----------------------------------------

