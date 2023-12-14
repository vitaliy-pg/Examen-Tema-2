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

    // Función para mostrar información del estudiante

    void mostrarEstudiante() {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nPromedio: " << promedio << "\nMaterias inscritas:\n";
        for (const auto& materia : materias) {
            std::cout << "- " << materia << "\n";
        }
        std::cout << "\nRegistro de asistencias:\n";
        for (const auto& asistencia : asistencias) {
            std::cout << "- " << asistencia << "\n";
        }
        std::cout << std::endl;
    }
    void agregarMateria(const std::string& materia) {
        materias.push_back(materia);
    }

    void eliminarMateria(const std::string& materia) {
        auto it = std::find(materias.begin(), materias.end(), materia);
        if (it != materias.end()) {
            materias.erase(it);
        }
    }

    void registrarAsistencia(const std::string& asistencia) {
        asistencias.push_back(asistencia);
    }