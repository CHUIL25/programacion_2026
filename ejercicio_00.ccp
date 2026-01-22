
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50

// Estructura 
typedef struct {
    char nombre[100];
    char codigo[20];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

//  	Para actualizar 
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
        printf("Promedio invalido. Se asignara 0.0\n");
        e->promedio = 0.0;
    }
}

void actualizarActivo(Estudiante *e, bool nuevoEstado) {
    e->activo = nuevoEstado;
}

// ----- Funciones para mostrar -----
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
    if (e.activo)
        printf("Estado: Activo\n");
    else
        printf("Estado: Inactivo\n");
}

void mostrarInformacionCompleta(Estudiante e) {
    mostrarNombre(e);
    mostrarCodigo(e);
    mostrarEdad(e);
    mostrarPromedio(e);
    mostrarActivo(e);
}

// -----  principal -----
int main() {
    Estudiante estudiantes[MAX];
    int total = 0;
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar un estudiante en especifico\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        if (opcion == 1 && total < MAX) {

            char nombre[100];
            char codigo[20];
            int edad;
            float promedio;
            int activo;

            printf("Nombre: ");
            fgets(nombre, 100, stdin);
            nombre[strcspn(nombre, "\n")] = 0;

            printf("Codigo: ");
            fgets(codigo, 20, stdin);
            codigo[strcspn(codigo, "\n")] = 0;

            printf("Edad: ");
            scanf("%d", &edad);

            printf("Promedio: ");
            scanf("%f", &promedio);

            printf("Activo (1 = si, 0 = no): ");
            scanf("%d", &activo);
            getchar();

            actualizarNombre(&estudiantes[total], nombre);
            actualizarCodigo(&estudiantes[total], codigo);
            actualizarEdad(&estudiantes[total], edad);
            actualizarPromedio(&estudiantes[total], promedio);
            actualizarActivo(&estudiantes[total], activo == 1);

            total++;
            printf("Estudiante agregado correctamente.\n");
        }

        else if (opcion == 2) {
            char buscarCodigo[20];
            bool encontrado = false;

            printf("Codigo del estudiante: ");
            fgets(buscarCodigo, 20, stdin);
            buscarCodigo[strcspn(buscarCodigo, "\n")] = 0;

            for (int i = 0; i < total; i++) {
                if (strcmp(estudiantes[i].codigo, buscarCodigo) == 0) {
                    mostrarInformacionCompleta(estudiantes[i]);
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                printf("Estudiante no encontrado.\n");
            }
        }

        else if (opcion == 3) {

            if (total == 0) {
                printf("No hay estudiantes registrados.\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("\nEstudiante %d\n", i + 1);
                    mostrarInformacionCompleta(estudiantes[i]);
                }
            }
        }

        else if (opcion == 4) {
            printf("Programa finalizado.\n");
        }

        else {
            printf("Opcion invalida.\n");
        }

    } while (opcion != 4);

    return 0;
}