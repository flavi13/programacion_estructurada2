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

// Funciones para manejar la lista de estudiantes
void agregarEstudiante(Estudiante **cabeza, const char *nombre, int edad, float promedio) {
    Estudiante *nuevoEst = (Estudiante *)malloc(sizeof(Estudiante));
    strcpy(nuevoEst->nombre, nombre);
    nuevoEst->edad = edad;
    nuevoEst->promedio = promedio;
    nuevoEst->siguiente = *cabeza;
    *cabeza = nuevoEst;
}

void mostrarEstudiantes(Estudiante *cabeza) {
    Estudiante *actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", actual->nombre, actual->edad, actual->promedio);
        actual = actual->siguiente;
    }
}

void eliminarEstudiante(Estudiante **cabeza, const char *nombre) {
    Estudiante *actual = *cabeza;
    Estudiante *anterior = NULL;

    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        return; // No se encontró el estudiante
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente; // Eliminar el primer nodo
    } else {
        anterior->siguiente = actual->siguiente; // Eliminar un nodo intermedio
    }

    free(actual);
}

// Función para copiar una estructura Estudiante
Estudiante copiarEstudiante(Estudiante est) {
    Estudiante nuevoEst;
    strcpy(nuevoEst.nombre, est.nombre);
    nuevoEst.edad = est.edad;
    nuevoEst.promedio = est.promedio;
    return nuevoEst;
}

// Funciones para imprimir y modificar estructuras
void imprimirEstudiante(Estudiante est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est.nombre, est.edad, est.promedio);
}

void modificarEstudiante(Estudiante *est) {
    est->edad = 30;
}

void imprimirEstudiante2(Estudiante *est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est->nombre, est->edad, est->promedio);
}

// Unión Dato
union Dato {
   int i;
   float f;
   char str[20];
};

int main() {
    // Parte 1: Estructuras

    // a. Constitución de una estructura
    Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 9.5;

    // b. Instanciación de estructuras
    Estudiante estudiante2;
    strcpy(estudiante2.nombre, "Ana");
    estudiante2.edad = 22;
    estudiante2.promedio = 9.8;

    // c. Instanciación con el operador malloc
    Estudiante *estudiante3 = (Estudiante *) malloc(sizeof(Estudiante));
    strcpy(estudiante3->nombre, "Pedro");
    estudiante3->edad = 25;
    estudiante3->promedio = 9.7;

    // d. Punteros y estructuras
    Estudiante *punteroEst = &estudiante1;
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", punteroEst->nombre, punteroEst->edad, punteroEst->promedio);

    // e. Organización de la programación: Lista de estudiantes
    Estudiante *cabeza = NULL;
    agregarEstudiante(&cabeza, "Juan", 20, 9.5);
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
    Estudiante copiaEstudiante1 = copiarEstudiante(estudiante1);
    printf("\nCopia del estudiante:\n");
    imprimirEstudiante(copiaEstudiante1);

    // Parte 4: Creación de alias de tipos de estructuras (ya se hizo antes con typedef)

    Estudiante estudiante4;
    strcpy(estudiante4.nombre, "Carlos");
    estudiante4.edad = 28;
    estudiante4.promedio = 8.5;

    // Parte 5: Estructuras y funciones
    imprimirEstudiante(estudiante4); // Pasar por valor
    modificarEstudiante(&estudiante4); // Pasar por referencia
    imprimirEstudiante2(&estudiante4); // Pasar por dirección

    // Liberar memoria asignada con malloc
    free(estudiante3);

    return 0;
}
