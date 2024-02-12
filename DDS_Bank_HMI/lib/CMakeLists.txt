cmake_minimum_required(VERSION 3.14)

# Buscamos los ficheros
file(GLOB_RECURSE LIBS
    ${PROJECT_SOURCE_DIR}/lib/*.hpp)

# Añadimos la librería
add_library(libs SHARED ${LIBS})

# Decimos donde se va a guardar la libreria
set_target_properties(libs PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/)
