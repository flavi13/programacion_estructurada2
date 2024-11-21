#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejercicio_1/estudiante.h"
#include "ejercicio_2/union_dato.h"
#include "ejercicio_3/copia_estudiante.h"
#include "ejercicio_4/alias_estudiante.h"
#include "ejercicio_5/funciones_estudiante.h"

int main() {
    // Parte 1: Estructuras

    // a. Constitución de una estructura
    Est estudiante1;
    strcpy(estudiante1.nombre, "Flavia");
    estudiante1.edad = 18;
    estudiante1.promedio = 9.5;

    // b. Instanciación de estructuras
    Est estudiante2;
    strcpy(estudiante2.nombre, "Ana");
    estudiante2.edad = 22;
    estudiante2.promedio = 9.8;

    // c. Instanciación con el operador malloc
    Est *estudiante3 = (Est *) malloc(sizeof(Est));
    strcpy(estudiante3->nombre, "Pedro");
    estudiante3->edad = 25;
    estudiante3->promedio = 9.7;

    // d. Punteros y estructuras
    Est *punteroEst = &estudiante1;
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", punteroEst->nombre, punteroEst->edad, punteroEst->promedio);

    // e. Organización de la programación: Lista de estudiantes
    Est *cabeza = NULL;
    agregarEstudiante(&cabeza, "Flavia", 18, 9.5);
    agregarEstudiante(&cabeza, "Ana", 22, 8.7);
    agregarEstudiante(&cabeza, "Luis", 19, 7.8);

    printf("Lista de estudiantes:\n");
    mostrarEstudiantes(cabeza);

    eliminarEstudiante(&cabeza, "Ana");
    printf("\nLista de estudiantes después de eliminar a Ana:\n");
    mostrarEstudiantes(cabeza);

    // Parte 2: Uniones
    union Dato dato;
    dato.i = 10;
    printf("dato.i: %d\n", dato.i);

    dato.f = 220.5;
    printf("dato.f: %.2f\n", dato.f);

    strcpy(dato.str, "C programming");
    printf("dato.str: %s\n", dato.str);

    // Parte 3: Copia de estructuras
    Est copiaEstudiante1 = copiarEstudiante(estudiante1);
    printf("\nCopia del estudiante:\n");
    imprimirEstudiante(copiaEstudiante1);
}