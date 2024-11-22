//
// Created by Flavia Rivero on 20/11/24.
//

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definición de la estructura Estudiante
typedef struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Estudiante *siguiente; // Para la lista enlazada
} Estudiante;

// Declaraciones de funciones para manejar la lista de estudiantes
void agregarEstudiante(Estudiante **cabeza, const char *nombre, int edad, float promedio);
void mostrarEstudiantes(Estudiante *cabeza);
void eliminarEstudiante(Estudiante **cabeza, const char *nombre);

#endif // ESTUDIANTE_H
