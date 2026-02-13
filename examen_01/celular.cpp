#include "celulares.h"

// Constructor por defecto
celulares::celulares() {
    modelo = "Generico";
    color = "";
    precio = 0;
    disponible = false;
}

// Constructor con parámetros
celulares::celulares(std::string m, std::string c, int p, bool d) {
    modelo = m;
    color = c;
    precio = p;
    disponible = d;
}

// Setters
void celulares::actualizarModelo(std::string m) { modelo = m; }
void celulares::actualizarColor(std::string c) { color = c; }
void celulares::actualizarPrecio(int p) { 
    if(p >= 0) precio = p; 
    else std::cout << "Precio no puede ser negativo.\n";
}
void celulares::actualizarDisponible(bool d) { disponible = d; }

// Getters
std::string celulares::obtenerModelo() { return modelo; }
std::string celulares::obtenerColor() { return color; }
int celulares::obtenerPrecio() { return precio; }
bool celulares::obtenerDisponible() { return disponible; }

// Métodos de Visualización
void celulares::mostrarModelo() { std::cout << "Modelo: " << modelo << std::endl; }
void celulares::mostrarColor() { std::cout << "Color: " << color << std::endl; }
void celulares::mostrarPrecio() { std::cout << "Precio: $" << precio << std::endl; }
void celulares::mostrarDisponible() { 
    std::cout << "Estado: " << (disponible ? "Disponible" : "Agotado") << std::endl; 
}

void celulares::mostrarInformacionCompleta() {
    std::cout << "=== Info Celular ===" << std::endl;
    mostrarModelo();
    mostrarColor();
    mostrarPrecio();
    mostrarDisponible();
    std::cout << "====================" << std::endl;
}
