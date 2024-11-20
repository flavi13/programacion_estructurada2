#ifndef MAIN_H
#define MAIN_H

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
Estudiante copiarEstudiante(Estudiante est);
void imprimirEstudiante(Estudiante est);
void modificarEstudiante(Estudiante *est);
void imprimirEstudiante2(Estudiante *est);

// Declaración de la unión Dato
union Dato {
    int i;
    float f;
    char str[20];
};

#endif // MAIN_H
