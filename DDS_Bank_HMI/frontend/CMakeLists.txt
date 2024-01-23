cmake_minimum_required(VERSION 3.14)

# -------------------------------------------- RECURSES ------------------------------------------------------

file(GLOB_RECURSE PACKAGE_FRONTEND
    ${PROJECT_SOURCE_DIR}/frontend/*.hpp
    ${PROJECT_SOURCE_DIR}/frontend/*.cpp)

file(GLOB_RECURSE IDL
    ${PROJECT_SOURCE_DIR}/idl/*.hpp
    ${PROJECT_SOURCE_DIR}/idl/*.cxx)
# -------------------------------------------- RECURSES ------------------------------------------------------

# ------------------------------------------- PROJECT SOURCES ------------------------------------------------
set(PROJECT_SOURCES_FRONTEND
    ${IDL}
    ${PACKAGE_FRONTEND}
    ${PROJECT_SOURCE_DIR}/mainFront.cpp
    ${PROJECT_SOURCE_DIR}/qml.qrc
    )
# ------------------------------------------- PROJECT SOURCES ------------------------------------------------

# ----------------------------------------- GENERING EXECUTABLE ----------------------------------------------
add_executable(FRONTEND
    ${PROJECT_SOURCES_FRONTEND}
    )
# ----------------------------------------- GENERING EXECUTABLE ----------------------------------------------

# ---------------------------------- CONFIGURATION EXECUTABLE FRONTEND ---------------------------------------
target_include_directories(FRONTEND
    PUBLIC ${PROJECT_SOURCE_DIR}/
    PUBLIC ${PROJECT_SOURCE_DIR}/utils
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source
)

target_compile_definitions(FRONTEND
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(FRONTEND
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
    PUBLIC RTIConnextDDS::cpp2_api
    PUBLIC ${PROJECT_SOURCE_DIR}/model/source/libmodelLib.so
    PUBLIC ${PROJECT_SOURCE_DIR}/utils/libutilsLib.a
    )

set_target_properties(FRONTEND PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(FRONTEND)
    qt_finalize_executable(FRONTEND)
endif()
# ---------------------------------- CONFIGURATION EXECUTABLE FRONTEND ---------------------------------------

