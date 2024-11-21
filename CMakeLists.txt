# Establecer la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(proyecto_c C)

# Establecer el estándar de C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Incluir directorios de encabezados
include_directories(ejercicio_1 ejercicio_2 ejercicio_3 ejercicio_4 ejercicio_5)

# Añadir el ejecutable
add_executable(proyecto_c
        main.c
        ejercicio_1/estudiante.c
        ejercicio_1/estudiante.h
        ejercicio_2/union_dato.c
        ejercicio_3/copia_estudiante.c
        ejercicio_4/alias_estudiante.c
        ejercicio_5/funciones_estudiante.c
        main.h
)
