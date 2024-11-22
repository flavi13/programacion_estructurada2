#include "main.h"


int validarNombre(const char *nombre) {
    if (strlen(nombre) > 0 && strlen(nombre) < 50) {
        return 1;
    }
    return 0;
}

int validarEdad(int edad) {
    if (edad > 0) {
        return 1; // Edad válida
    }
    return 0; // Edad inválida
}


int validarPromedio(float promedio) {
    if (promedio >= 0.0 && promedio <= 10.0) {
        return 1; // Promedio válido
    }
    return 0; // Promedio inválido
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void solicitarNombre(char *nombre) {
    while (1) {
        printf("Introduce el nombre: ");
        if (scanf("%49s", nombre) == 1 && validarNombre(nombre)) {
            break;
        } else {
            printf("Error: Nombre inválido. Inténtalo de nuevo.\n");
            limpiarBuffer();
        }
    }
}

// Función para solicitar y validar la edad
void solicitarEdad(int *edad) {
    while (1) {
        printf("Introduce la edad: ");
        if (scanf("%d", edad) == 1 && validarEdad(*edad)) {
            break;
        } else {
            printf("Error: Edad inválida. Inténtalo de nuevo.\n");
            limpiarBuffer();
        }
    }
}

// Función para solicitar y validar el promedio
void solicitarPromedio(float *promedio) {
    while (1) {
        printf("Introduce el promedio (0.0 - 10.0): ");
        if (scanf("%f", promedio) == 1 && validarPromedio(*promedio)) {
            break;
        } else {
            printf("Error: Promedio inválido. Inténtalo de nuevo.\n");
            limpiarBuffer();
        }
    }
}

int main() {
    // Parte 1: Estructuras

    // a. Constitución de una estructura
    Estudiante estudiante1;
    solicitarNombre(estudiante1.nombre);
    solicitarEdad(&estudiante1.edad);
    solicitarPromedio(&estudiante1.promedio);

    // b. Instanciación de estructuras
    Estudiante estudiante2;
    solicitarNombre(estudiante2.nombre);
    solicitarEdad(&estudiante2.edad);
    solicitarPromedio(&estudiante2.promedio);

    // c. Instanciación con el operador malloc
    Estudiante *estudiante3 = (Estudiante *) malloc(sizeof(Estudiante));
    solicitarNombre(estudiante3->nombre);
    solicitarEdad(&estudiante3->edad);
    solicitarPromedio(&estudiante3->promedio);

    // d. Punteros y estructuras
    Estudiante *punteroEst = &estudiante1;
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", punteroEst->nombre, punteroEst->edad, punteroEst->promedio);

    // e. Organización de la programación: Lista de estudiantes
    Estudiante *cabeza = NULL;
    agregarEstudiante(&cabeza, estudiante1.nombre, estudiante1.edad, estudiante1.promedio);
    agregarEstudiante(&cabeza, estudiante2.nombre, estudiante2.edad, estudiante2.promedio);
    agregarEstudiante(&cabeza, estudiante3->nombre, estudiante3->edad, estudiante3->promedio);

    printf("Lista de estudiantes:\n");
    mostrarEstudiantes(cabeza);

    eliminarEstudiante(&cabeza, estudiante2.nombre);
    printf("\nLista de estudiantes después de eliminar a %s:\n", estudiante2.nombre);
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

    // Parte 4: Creación de alias de tipos de estructuras (ya se hizo antes con typedef)

    Est estudiante4;
    strcpy(estudiante4.nombre, "Flavia");
    estudiante4.edad = 28;
    estudiante4.promedio = 9.5;

    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", estudiante4.nombre, estudiante4.edad, estudiante4.promedio);

    // Parte 5: Estructuras y funciones
    modificarEstudiante(&estudiante4); // Pasar por referencia
    imprimirEstudiante(estudiante4); // Pasar por valor

    free(estudiante3);

    return 0;
}
