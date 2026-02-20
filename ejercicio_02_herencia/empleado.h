#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

class Empleado {
protected: 
    std::string nombre;      
    std::string id;          
    float salarioBase;       
    std::string departamento;

public:
    Empleado();
    Empleado(std::string nombre, std::string id, float salarioBase, std::string departamento);

    void actualizarNombre(std::string nombre);
    void actualizarId(std::string id);
    void actualizarSalarioBase(float salarioBase);

    void mostrarInformacion();
};
#endif
