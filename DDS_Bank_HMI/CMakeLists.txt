cmake_minimum_required(VERSION 3.14)

project(DDS_Bank_HMI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

# -------------------------------------------- RECURSES ------------------------------------------------------
file(GLOB_RECURSE UTILS
    ${PROJECT_SOURCE_DIR}/utils/*.hpp)

file(GLOB_RECURSE MODEL
    ${PROJECT_SOURCE_DIR}/model/*.hpp)

file(GLOB_RECURSE PACKAGE_FRONTEND
    ${PROJECT_SOURCE_DIR}/frontend/*.hpp
    ${PROJECT_SOURCE_DIR}/frontend/*.cpp)

file(GLOB_RECURSE PACKAGE_BACKEND
    ${PROJECT_SOURCE_DIR}/backend/*.hpp
    ${PROJECT_SOURCE_DIR}/backend/*.cpp)
# -------------------------------------------- RECURSES ------------------------------------------------------

# --------------------------------------- ADD SUBDIRECTORIES -------------------------------------------------
add_subdirectory(model) # hay una nueva carpeta con un nuevo CMakeList, para que lea y ejecute en cmakelist
add_subdirectory(utils)
# --------------------------------------- ADD SUBDIRECTORIES -------------------------------------------------

# --------------------------------------------- GTEST --------------------------------------------------------
# GTEST is required for testing
find_package(GTest REQUIRED)

# Enables testing for this directory and below.
# This command should be in the source directory root because ctest expects to
# find a test file in the build directory root.
enable_testing()
# --------------------------------------------- GTEST --------------------------------------------------------

# -------------------------------------------- RTI-DDS -------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)
find_package(RTIConnextDDS "6.1.0" REQUIRED COMPONENTS core routing_service)
# -------------------------------------------- RTI-DDS -------------------------------------------------------

# ------------------------------------------- IDL to C++ -----------------------------------------------------
# Configura la ubicación de los archivos IDL
set(IDL_DIRECTORY
    ${PROJECT_SOURCE_DIR}/idl/
    )

# Buscar todos los archivos con extensión .idl en la ruta especificada
file(GLOB IDL_FILES ${IDL_DIRECTORY}*.idl)

message(STATUS "Archivos idl encontrados: ${IDL_FILES}")

# Configura la ubicación de la herramienta de generación de código
set(CODE_GEN_TOOL rtiddsgen)

# Configura la ubicación del directorio de salida para el código generado
set(GENERATED_CODE_DIR ${PROJECT_SOURCE_DIR}/idl)

# Creamos una lista con todos los archivos generados para luego agregarlas al ejecutable
set(GENERATED_IDL_FILES)

# Iterar sobre cada archivo IDL encontrado
foreach(IDL_FILE ${IDL_FILES})
    # Extraer el nombre base del archivo IDL
    get_filename_component(IDL_BASENAME ${IDL_FILE} NAME_WE)

    # Construir los nombres de los archivos generados
    set(GENERATED_CXX_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}.cxx)
    set(GENERATED_HPP_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}.hpp)
    set(GENERATED_CXX_PLUGIN_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}Plugin.cxx)
    set(GENERATED_HPP_PLUGIN_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}Plugin.hpp)

    message(STATUS "${IDL_DIRECTORY}")

    # Agregar el comando personalizado
    add_custom_command(
        OUTPUT ${GENERATED_CXX_FILE} ${GENERATED_HPP_FILE} ${GENERATED_CXX_PLUGIN_FILE} ${GENERATED_HPP_PLUGIN_FILE}
        COMMAND ${CODE_GEN_TOOL} -language c++11 -platform x64Linux4gcc7.3.0 -create makefiles -create typefiles ${IDL_FILES}
        WORKING_DIRECTORY ${GENERATED_CODE_DIR}
        )

endforeach()

# -------------------------------------------- RECURSES ------------------------------------------------------
file(GLOB_RECURSE IDL
    ${PROJECT_SOURCE_DIR}/idl/*.hpp
    ${PROJECT_SOURCE_DIR}/idl/*.cxx)
# -------------------------------------------- RECURSES ------------------------------------------------------
# ------------------------------------------- IDL to C++ -----------------------------------------------------

# ------------------------------------------- PROJECT SOURCES ------------------------------------------------
set(PROJECT_SOURCES_FRONTEND
    ${IDL}
    ${UTILS}
    ${MODEL}
    ${PACKAGE_FRONTEND}
    mainFront.cpp
    qml.qrc
    )

set(PROJECT_SOURCES_BACKEND
    ${IDL}
    ${UTILS}
    ${MODEL}
    ${PACKAGE_BACKEND}
    mainBack.cpp
    )
# ------------------------------------------- PROJECT SOURCES ------------------------------------------------

# ----------------------------------------- GENERING EXECUTABLE ----------------------------------------------
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DDS_Bank_HMI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET DDS_Bank_HMI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DDS_Bank_HMI SHARED
            ${PROJECT_SOURCES_FRONTEND}
            )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FRONTEND
            ${PROJECT_SOURCES_FRONTEND}
            )
        add_executable(BACKEND
            ${PROJECT_SOURCES_BACKEND}
            )
    endif()
endif()
# ----------------------------------------- GENERING EXECUTABLE ----------------------------------------------

# ---------------------------------- CONFIGURATION EXECUTABLE FRONTEND ---------------------------------------
target_compile_definitions(FRONTEND
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(FRONTEND
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
    PUBLIC RTIConnextDDS::cpp2_api
    PUBLIC ${PROJECT_SOURCE_DIR}/model/libmodelLib.so
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

# ---------------------------------- CONFIGURATION EXECUTABLE BACKEND ----------------------------------------
target_link_libraries(BACKEND
    PUBLIC RTIConnextDDS::cpp2_api
    PUBLIC ${PROJECT_SOURCE_DIR}/model/libmodelLib.so
    PUBLIC ${PROJECT_SOURCE_DIR}/utils/libutilsLib.a
    )
# ---------------------------------- CONFIGURATION EXECUTABLE BACKEND ----------------------------------------
