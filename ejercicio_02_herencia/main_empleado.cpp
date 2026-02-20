#include <iostream>
#include "empleado_tiempo_completo.h"

int main() {
    std::cout << "=== Sistema de Gestion de Empleados ===" << std::endl << std::endl;

    // 1. Empleado base
    Empleado emp1("Ana Perla Lopez Garcia", "EMP-001", 18000.0, "Recursos Humanos");
    std::cout << "Empleado (clase base):" << std::endl;
    emp1.mostrarInformacion();
    std::cout << std::endl;

    // 2. Constructor por defecto
    EmpleadoTiempoCompleto etc1;
    std::cout << "Empleado tiempo completo (constructor por defecto):" << std::endl;
    etc1.mostrarInformacion();
    std::cout << std::endl;

    // 3. Constructor con parametros 
    EmpleadoTiempoCompleto etc2("Jose Carlos Ruiz Martines", "EMP-002", 25000.0, "Sistemas", 48, 2000.0);
    std::cout << "Empleado tiempo completo (constructor con parametros):" << std::endl;
    etc2.mostrarInformacion();
    std::cout << "Salario total: " << etc2.calcularSalarioTotal() << std::endl;
    std::cout << std::endl;

    // 4. Actualizar bono
    etc2.actualizarBono(4000.0);
    std::cout << "Despues de actualizar bono:" << std::endl;
    etc2.mostrarInformacion();
    std::cout << "Salario total: " << etc2.calcularSalarioTotal() << std::endl;

    return 0;
}