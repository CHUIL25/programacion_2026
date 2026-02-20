#include "empleado.h"
#include <iostream>

Empleado::Empleado() : nombre(""), id(""), salarioBase(0.0f), departamento("") {}

Empleado::Empleado(std::string nombre, std::string id, float salarioBase, std::string departamento) {
    this->nombre = nombre;
    this->id = id;
    this->salarioBase = salarioBase;
    this->departamento = departamento;
}

void Empleado::actualizarNombre(std::string nombre) { this->nombre = nombre; }
void Empleado::actualizarId(std::string id) { this->id = id; }
void Empleado::actualizarSalarioBase(float salarioBase) { this->salarioBase = salarioBase; }

void Empleado::mostrarInformacion() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Salario base: " << salarioBase << std::endl;
}
