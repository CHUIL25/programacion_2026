#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ESTUDIANTES 100
#define MAX_TEXTO 100

// ----- Estructura Estudiante -----
typedef struct {
    char nombre[MAX_TEXTO];
    char codigo[MAX_TEXTO];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

// ----- Prototipos -----
void actualizarNombre(Estudiante *e, char nuevoNombre[]);
void actualizarCodigo(Estudiante *e, char nuevoCodigo[]);
void actualizarEdad(Estudiante *e, int nuevaEdad);
void actualizarPromedio(Estudiante *e, float nuevoPromedio);
void actualizarActivo(Estudiante *e, bool nuevoEstado);

void mostrarNombre(Estudiante e);
void mostrarCodigo(Estudiante e);
void mostrarEdad(Estudiante e);
void mostrarPromedio(Estudiante e);
void mostrarActivo(Estudiante e);
void mostrarInformacionCompleta(Estudiante e);

void agregarEstudiante(Estudiante estudiantes[], int *contador);
void mostrarEstudiantePorCodigo(Estudiante estudiantes[], int contador);
void mostrarTodosLosEstudiantes(Estudiante estudiantes[], int contador);

// ----- Funciones de actualización -----
void actualizarNombre(Estudiante *e, char nuevoNombre[]) {
    strcpy(e->nombre, nuevoNombre);
}

void actualizarCodigo(Estudiante *e, char nuevoCodigo[]) {
    strcpy(e->codigo, nuevoCodigo);
}

void actualizarEdad(Estudiante *e, int nuevaEdad) {
    e->edad = nuevaEdad;
}

void actualizarPromedio(Estudiante *e, float nuevoPromedio) {
    if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
        e->promedio = nuevoPromedio;
    } else {
        printf("Promedio invalido. Debe estar entre 0.0 y 10.0\n");
    }
}

void actualizarActivo(Estudiante *e, bool nuevoEstado) {
    e->activo = nuevoEstado;
}

// ----- Funciones de visualización -----
void mostrarNombre(Estudiante e) {
    printf("Nombre: %s\n", e.nombre);
}

void mostrarCodigo(Estudiante e) {
    printf("Codigo: %s\n", e.codigo);
}

void mostrarEdad(Estudiante e) {
    printf("Edad: %d años\n", e.edad);
}

void mostrarPromedio(Estudiante e) {
    printf("Promedio: %.2f\n", e.promedio);
}

void mostrarActivo(Estudiante e) {
    printf("Estado: %s\n", e.activo ? "Activo" : "Inactivo");
}

void mostrarInformacionCompleta(Estudiante e) {
    printf("\n----------------------------\n");
    mostrarNombre(e);
    mostrarCodigo(e);
    mostrarEdad(e);
    mostrarPromedio(e);
    mostrarActivo(e);
    printf("----------------------------\n");
}

// ----- Funciones del sistema -----
void agregarEstudiante(Estudiante estudiantes[], int *contador) {
    if (*contador >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar mas estudiantes.\n");
        return;
    }

    Estudiante e;
    char buffer[MAX_TEXTO];
    int estado;

    printf("Nombre completo: ");
    getchar(); // limpiar buffer
    fgets(buffer, MAX_TEXTO, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    actualizarNombre(&e, buffer);

    printf("Codigo: ");
    fgets(buffer, MAX_TEXTO, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    actualizarCodigo(&e, buffer);

    printf("Edad: ");
    scanf("%d", &e.edad);
    actualizarEdad(&e, e.edad);

    printf("Promedio (0.0 - 10.0): ");
    scanf("%f", &e.promedio);
    actualizarPromedio(&e, e.promedio);

    printf("Activo? (1 = Si, 0 = No): ");
    scanf("%d", &estado);
    actualizarActivo(&e, estado == 1);

    estudiantes[*contador] = e;
    (*contador)++;

    printf("Estudiante agregado correctamente.\n");
}

void mostrarEstudiantePorCodigo(Estudiante estudiantes[], int contador) {
    char codigoBuscado[MAX_TEXTO];
    printf("Ingrese el codigo del estudiante: ");
    getchar();
    fgets(codigoBuscado, MAX_TEXTO, stdin);
    codigoBuscado[strcspn(codigoBuscado, "\n")] = 0;

    for (int i = 0; i < contador; i++) {
        if (strcmp(estudiantes[i].codigo, codigoBuscado) == 0) {
            mostrarInformacionCompleta(estudiantes[i]);
            return;
        }
    }

    printf("Estudiante no encontrado.\n");
}

void mostrarTodosLosEstudiantes(Estudiante estudiantes[], int contador) {
    if (contador == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        mostrarInformacionCompleta(estudiantes[i]);
    }
}

// ----- Programa principal -----
int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int contador = 0;
    int opcion;

    do {
        printf("\n===== SISTEMA DE GESTION DE ESTUDIANTES =====\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar un estudiante en especifico\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &contador);
                break;
            case 2:
                mostrarEstudiantePorCodigo(estudiantes, contador);
                break;
            case 3:
                mostrarTodosLosEstudiantes(estudiantes, contador);
                break;
            case 4:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 4);

    return 0;
}