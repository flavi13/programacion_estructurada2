//
// Created by Flavia Rivero on 20/11/24.
//

#include "../ejercicio_3/copia_estudiante.h"
#include "estudiante.h"

Estudiante copiarEstudiante(Estudiante est) {
    Estudiante nuevoEst;
    strcpy(nuevoEst.nombre, est.nombre);
    nuevoEst.edad = est.edad;
    nuevoEst.promedio = est.promedio;
    return nuevoEst;
}
