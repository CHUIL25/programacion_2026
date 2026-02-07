#include "estudiante.h"
#include <iostream>

int main() {
    // 1. Crear un estudiante usando el constructor por defecto
    Estudiante est1;

    std::cout << "--- Datos iniciales del estudiante (Default) ---" << std::endl;
    est1.mostrarInformacionCompleta();

    // 2. Actualizar atributos usando Setters
    est1.actualizarNombre("Juan Perez");
    est1.actualizarCodigo("A0012345");
    est1.actualizarEdad(20);
    est1.actualizarPromedio(8.5);
    est1.actualizarActivo(true);

    std::cout << "\n--- Datos tras actualizar atributos ---" << std::endl;
    est1.mostrarInformacionCompleta();

    // 3. Probar métodos de utilidad
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
