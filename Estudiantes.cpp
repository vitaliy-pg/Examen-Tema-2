#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
    std::vector<std::string> asistencias;