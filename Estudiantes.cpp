#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <setjmp.h>

// Estructura Estudiante en C++
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
    std::vector<std::string> asistencias;
};

// Estructura para simular excepciones en C
struct C_Exception {
    const char* mensaje;
};

// Variable para el manejo de excepciones en C
jmp_buf buffer;

// Función para lanzar excepción en C
void lanzarExcepcionEnC() {
    C_Exception excepcion = {"Error personalizado en C"};
    longjmp(buffer, 1);
}

// Función para mostrar información del estudiante
void mostrarEstudiante(Estudiante* estudiante) {
    std::cout << "Nombre: " << estudiante->nombre << "\nEdad: " << estudiante->edad << "\nPromedio: " << estudiante->promedio << "\nMaterias inscritas:\n";
    for (const auto& materia : estudiante->materias) {
        std::cout << "- " << materia << "\n";
    }
    std::cout << "\nRegistro de asistencias:\n";
    for (const auto& asistencia : estudiante->asistencias) {
        std::cout << "- " << asistencia << "\n";
    }
    std::cout << std::endl;
}

int main() {
    Estudiante estudiante;
    estudiante.nombre = "Vitaliy el vapor max";
    estudiante.edad = 20;
    estudiante.promedio = 8.5;

    estudiante.materias.push_back("Matematicas");
    estudiante.materias.push_back("Historia");

    estudiante.asistencias.push_back("Asistio el 01/01/2023");
    estudiante.asistencias.push_back("Falta el 02/01/2023");

    // Manejo de excepciones en C
    if (setjmp(buffer) == 0) {
        // Código que puede lanzar una excepción en C
        lanzarExcepcionEnC();
    } else {
        // Código para manejar la excepción en C
        std::cerr << "Excepcion atrapada en C: Error personalizado en C\n";
    }

    // Código adicional en C++
    try {
        // Código que puede lanzar una excepción en C++
        throw std::runtime_error("Error personalizado en C++");
    } catch (const std::exception& e) {
        // Código para manejar la excepción en C++
        std::cerr << "Excepcion atrapada en C++: " << e.what() << std::endl;
    }

    // Mostrar información del estudiante
    mostrarEstudiante(&estudiante);

    return 0;
}
// ya no da error
// este codigo no contiene ni una mierda de lo pedido en el examen
// vamos  a cambiar todo el codigo
