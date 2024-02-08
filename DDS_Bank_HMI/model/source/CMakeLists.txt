cmake_minimum_required(VERSION 3.14)

# Buscamos los ficheros
file(GLOB_RECURSE MODEL_LIB
    ${PROJECT_SOURCE_DIR}/model/source/*.hpp
    ${PROJECT_SOURCE_DIR}/model/source/*.cpp)

# Añadimos la librería
add_library(modelLib SHARED ${MODEL_LIB})

# Decimos donde se va a guardar la libreria
set_target_properties(modelLib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/model/source/)

# Establece un directorio al target que esta compilado (se le añaden directorios cuando compila, pero no se para que se le añaden)
target_include_directories(modelLib
    PUBLIC ${PROJECT_SOURCE_DIR}/utils/source
    PUBLIC ${PROJECT_SOURCE_DIR}/lib
)
