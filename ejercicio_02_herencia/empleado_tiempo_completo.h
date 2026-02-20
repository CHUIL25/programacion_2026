#ifndef EMPLEADO_TIEMPO_COMPLETO_H
#define EMPLEADO_TIEMPO_COMPLETO_H
#include "empleado.h"

class EmpleadoTiempoCompleto : public Empleado {
private:
    int horasSemanales; 
    float bono;          

public:
    EmpleadoTiempoCompleto();
    EmpleadoTiempoCompleto(std::string n, std::string i, float s, std::string d, int h, float b);

    void actualizarBono(float nuevoBono);
    void mostrarInformacion();
    float calcularSalarioTotal();
};
#endif
