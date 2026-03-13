
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include "circulo.h"

Circulo::Circulo(std::string nombre, double radio) : Figura(nombre), radio(radio) {}

double Circulo::calcularArea() {
    return M_PI * radio * radio;
}

void Circulo::describir() {
    std::cout << "Figura: " << nombre << ", radio: " << radio << std::endl;
}

double Circulo::obtenerRadio() {
    return radio;
}
