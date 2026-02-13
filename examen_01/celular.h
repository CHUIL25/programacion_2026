#ifndef CELULARES_H
#define CELULARES_H

#include <string>
#include <iostream>

class celulares {
private:
    std::string modelo;
    std::string color;
    int precio; 
    bool disponible;

public:
    // Constructores
    celulares();
    celulares(std::string modelo, std::string color, int precio, bool disponible);

    // Métodos para actualizar (Setters)
    void actualizarModelo(std::string nuevoModelo);
    void actualizarColor(std::string nuevoColor);
    void actualizarPrecio(int nuevoPrecio);
    void actualizarDisponible(bool nuevoEstado);

    // Métodos para mostrar
    void mostrarModelo();
    void mostrarColor();
    void mostrarPrecio();
    void mostrarDisponible();
    void mostrarInformacionCompleta();

    // Getters
    std::string obtenerModelo();
    std::string obtenerColor();
    int obtenerPrecio(); 
    bool obtenerDisponible();
};

#endif
