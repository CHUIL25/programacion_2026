#include "estudiante.h"
#include <iostream>

int main() {
    // estudiante usando el constructor 
    Estudiante est1;

    std::cout << "--- Datos iniciales del estudiante (Default) ---" << std::endl;
    est1.mostrarInformacionCompleta();

    // Actualizar Setters
    est1.actualizarNombre("Agustin Poot");
    est1.actualizarCodigo("A0012345");
    est1.actualizarEdad(20);
    est1.actualizarPromedio(8.5);
    est1.actualizarActivo(true);

    std::cout << "\n--- Datos tras actualizar atributos ---" << std::endl;
    est1.mostrarInformacionCompleta();

    // métodos de utilidad
    std::cout << "\nIncrementando edad y mejorando promedio..." << std::endl;
    est1.incrementarEdad();
    est1.actualizarPromedio(9.5);
    
    est1.mostrarInformacionCompleta();

    // 4. Crear estudiante con constructor parametrizado
    Estudiante est2("Maria Lopez", "B0098765", 22, 5.5, true);
    std::cout << "\n--- Nuevo Estudiante (Parametrizado) ---" << std::endl;
    est2.mostrarInformacionCompleta();

    return 0;
}
