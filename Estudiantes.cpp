#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Estructura Estudiante en C++
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
    std::vector<std::string> asistencias;

    void mostrarEstudiante() {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << "\nMaterias inscritas:\n";
        for (const auto& materia : materias) {
            std::cout << "- " << materia << "\n";