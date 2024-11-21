#include "estudiante.h"

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
