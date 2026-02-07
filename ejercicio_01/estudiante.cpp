#include "estudiante.h"

Estudiante::Estudiante() {
    nombre = "";
    codigo = "";
    edad = 0;
    promedio = 0.0;
    activo = false;
}


Estudiante::Estudiante(std::string n, std::string c, int e, float p, bool a) {
    nombre = n;
    codigo = c;
    edad = e;
    actualizarPromedio(p); 
    activo = a;
}


void Estudiante::actualizarNombre(std::string n) { nombre = n; }
void Estudiante::actualizarCodigo(std::string c) { codigo = c; }
void Estudiante::actualizarEdad(int e) { edad = e; }
void Estudiante::actualizarActivo(bool a) { activo = a; }

void Estudiante::actualizarPromedio(float p) {
    if (p >= 0.0 && p <= 10.0) {
        promedio = p;
    } else {
        std::cout << "Error: Promedio fuera de rango (0-10).\n";
    }
}

// Getters
std::string Estudiante::obtenerNombre() { return nombre; }
std::string Estudiante::obtenerCodigo() { return codigo; }
int Estudiante::obtenerEdad() { return edad; }
float Estudiante::obtenerPromedio() { return promedio; }
bool Estudiante::obtenerActivo() { return activo; }

// Visualización
void Estudiante::mostrarNombre() { std::cout << "Nombre: " << nombre << std::endl; }
void Estudiante::mostrarCodigo() { std::cout << "Codigo: " << codigo << std::endl; }
void Estudiante::mostrarEdad() { std::cout << "Edad: " << edad << " años" << std::endl; }
void Estudiante::mostrarPromedio() { std::cout << "Promedio: " << promedio << std::endl; }
void Estudiante::mostrarActivo() { 
    std::cout << "Estado: " << (activo ? "Activo" : "Inactivo") << std::endl; 
}

void Estudiante::mostrarInformacionCompleta() {
    std::cout << "---------------------------" << std::endl;
    mostrarNombre();
    mostrarCodigo();
    mostrarEdad();
    mostrarPromedio();
    mostrarActivo();
    calcularEstadoAcademico();
    std::cout << "---------------------------" << std::endl;
}

// Métodos de Utilidad
void Estudiante::incrementarEdad() { edad++; }

void Estudiante::calcularEstadoAcademico() {
    std::cout << "Estado Academico: ";
    if (promedio >= 9.0) std::cout << "Excelente";
    else if (promedio >= 8.0) std::cout << "Muy Bueno";
    else if (promedio >= 7.0) std::cout << "Bueno";
    else if (promedio >= 6.0) std::cout << "Regular";
    else std::cout << "Necesita Mejorar";
    std::cout << std::endl;
}
