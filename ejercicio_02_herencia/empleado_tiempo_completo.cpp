#include "empleado_tiempo_completo.h"
#include <iostream>

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto() : Empleado(), horasSemanales(0), bono(0.0f) {}

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(std::string n, std::string i, float s, std::string d, int h, float b) 
    : Empleado(n, i, s, d) { 
    this->horasSemanales = h;
    this->bono = b;
}

void EmpleadoTiempoCompleto::actualizarBono(float nuevoBono) {
    bono = nuevoBono;
}

void EmpleadoTiempoCompleto::mostrarInformacion() {
    Empleado::mostrarInformacion(); 
    std::cout << "Horas semanales: " << horasSemanales << std::endl;
    std::cout << "Bono: " << bono << std::endl;
}

float EmpleadoTiempoCompleto::calcularSalarioTotal() {
    return salarioBase + bono; 
}
