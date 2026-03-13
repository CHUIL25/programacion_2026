
#include <iostream>
#include "figura.h"
#include "circulo.h"
#include "rectangulo.h"

int main() {
    std::cout << "=Figuras Geométricas (Polimorfismo) =" << std::endl << std::endl;

    // Polimorfismo:
    Figura* f1 = new Circulo("Círculo", 5.0);
    Figura* f2 = new Rectangulo("Rectángulo", 4.0, 6.0);

    // Tratamiento uniforme
    Figura* figuras[] = { f1, f2 };

    for (int i = 0; i < 2; i++) {
        figuras[i]->describir();
        std::cout << "Área: " << figuras[i]->calcularArea() << std::endl << std::endl;
    }

    // Liberación de memoria
    delete f1;
    delete f2;

    return 0;
}
