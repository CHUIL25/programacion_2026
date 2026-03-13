#include "figura.h"

Figura::Figura(std::string nombre) : nombre(nombre) {}

Figura::~Figura() {}

std::string Figura::obtenerNombre() {
    return nombre;
}
