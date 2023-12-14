##include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Necesario para std::find en C++

struct EstudianteCpp {
    std::string nombre;
    int edad;
    float promedio;
    // Lista de materias en las que está inscrito el estudiante
    std::vector<std::string> materias;
    // Lista de asistencias
    std::vector<struct AsistenciaCpp> asistencias;
};