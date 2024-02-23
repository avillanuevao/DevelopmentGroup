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

# -------------------------------------------- RTI-DDS -------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH $ENV{NDDSHOME}/resource/cmake)
find_package(RTIConnextDDS "6.1.0" REQUIRED COMPONENTS core routing_service)
# -------------------------------------------- RTI-DDS -------------------------------------------------------

# --------------------------------------- ADD SUBDIRECTORIES -------------------------------------------------
add_subdirectory(model)
add_subdirectory(utils)
#add_subdirectory(frontend)
add_subdirectory(backend)
add_subdirectory(lib)
# --------------------------------------- ADD SUBDIRECTORIES -------------------------------------------------

# --------------------------------------------- GTEST --------------------------------------------------------
# GTEST is required for testing
find_package(GTest REQUIRED)

# Enables testing for this directory and below.
# This command should be in the source directory root because ctest expects to
# find a test file in the build directory root.
enable_testing()
# --------------------------------------------- GTEST --------------------------------------------------------

# ------------------------------------------- IDL to C++ -----------------------------------------------------
## Configura la ubicación de los archivos IDL
#set(IDL_DIRECTORY
#    ${PROJECT_SOURCE_DIR}/idl/
#    )

## Buscar todos los archivos con extensión .idl en la ruta especificada
#file(GLOB IDL_FILES ${IDL_DIRECTORY}*.idl)

#message(STATUS "Archivos idl encontrados: ${IDL_FILES}")

## Configura la ubicación de la herramienta de generación de código
#set(CODE_GEN_TOOL rtiddsgen)

## Configura la ubicación del directorio de salida para el código generado
#set(GENERATED_CODE_DIR ${PROJECT_SOURCE_DIR}/idl)

## Creamos una lista con todos los archivos generados para luego agregarlas al ejecutable
#set(GENERATED_IDL_FILES)

## Iterar sobre cada archivo IDL encontrado
#foreach(IDL_FILE ${IDL_FILES})
#    # Extraer el nombre base del archivo IDL# hay una nueva carpeta con un nuevo CMakeList, para que lea y ejecute en cmakelist
#    get_filename_component(IDL_BASENAME ${IDL_FILE} NAME_WE)

#    # Construir los nombres de los archivos generados
#    set(GENERATED_CXX_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}.cxx)
#    set(GENERATED_HPP_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}.hpp)
#    set(GENERATED_CXX_PLUGIN_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}Plugin.cxx)
#    set(GENERATED_HPP_PLUGIN_FILE ${GENERATED_CODE_DIR}/${IDL_BASENAME}Plugin.hpp)

#    message(STATUS "${IDL_DIRECTORY}")

#    # Agregar el comando personalizado
#    add_custom_command(
#        OUTPUT ${GENERATED_CXX_FILE} ${GENERATED_HPP_FILE} ${GENERATED_CXX_PLUGIN_FILE} ${GENERATED_HPP_PLUGIN_FILE}
#        COMMAND ${CODE_GEN_TOOL} -language c++11 -platform x64Linux4gcc7.3.0 -create makefiles -create typefiles ${IDL_FILES}
#        WORKING_DIRECTORY ${GENERATED_CODE_DIR}
#        )

#endforeach()
# ------------------------------------------- IDL to C++ -----------------------------------------------------
