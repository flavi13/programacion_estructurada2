//
// Created by Flavia Rivero on 20/11/24.
//

#include "funciones_estudiante.h"
#include "estudiante.h"

void imprimirEstudiante(Estudiante est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est.nombre, est.edad, est.promedio);
}

void modificarEstudiante(Estudiante *est) {
    est->edad = 30;
}

void imprimirEstudiante2(Estudiante *est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est->nombre, est->edad, est->promedio);
}
