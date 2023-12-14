#include <iostream>
#include <vector>
#include <algorithm>  // Necesario para std::find en C++

// Estructura Asistencia en C++
struct AsistenciaCpp {
    std::string fecha;
    std::string materia;
    std::string estado;
};

// Estructura Estudiante en C++
struct EstudianteCpp {
    std::string nombre;
    int edad;
    float promedio;
    // Lista de materias en las que está inscrito el estudiante
    std::vector<std::string> materias;
    // Lista de asistencias
    std::vector<AsistenciaCpp> asistencias;
};

// Función para mostrar información del estudiante en C++
void mostrarEstudianteCpp(EstudianteCpp estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nPromedio: " << estudiante.promedio << "\n";
}

// Funciones para gestionar materias en C++
void agregarMateriaCpp(EstudianteCpp &estudiante, const std::string &materia) {
    estudiante.materias.push_back(materia);
}

void eliminarMateriaCpp(EstudianteCpp &estudiante, const std::string &materia) {
    auto it = std::find(estudiante.materias.begin(), estudiante.materias.end(), materia);
    if (it != estudiante.materias.end()) {
        estudiante.materias.erase(it);
    }
}

void mostrarMateriasCpp(EstudianteCpp &estudiante) {
    std::cout << "Materias inscritas:\n";
    for (const auto &materia : estudiante.materias) {
        std::cout << "- " << materia << "\n";
    }
    std::cout << "\n";
}

// Funciones para gestionar asistencias en C++
void registrarAsistenciaCpp(EstudianteCpp &estudiante, const std::string &fecha, const std::string &materia, const std::string &estado) {
    AsistenciaCpp asistencia;
    asistencia.fecha = fecha;
    asistencia.materia = materia;
    asistencia.estado = estado;

    estudiante.asistencias.push_back(asistencia);
}

void mostrarAsistenciasCpp(EstudianteCpp &estudiante) {
    std::cout << "Registro de asistencias:\n";
    for (const auto &asistencia : estudiante.asistencias) {
        std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << "\n";
    }
    std::cout << "\n";
}

int main() {
    // Uso de la estructura y funciones en C++
    EstudianteCpp estudianteCpp;
    estudianteCpp.nombre = "Juan";
    estudianteCpp.edad = 20;
    estudianteCpp.promedio = 8.5;

    agregarMateriaCpp(estudianteCpp, "Matemáticas");
    agregarMateriaCpp(estudianteCpp, "Historia");

    registrarAsistenciaCpp(estudianteCpp, "01/01/2023", "Matemáticas", "Asistió");
    registrarAsistenciaCpp(estudianteCpp, "02/01/2023", "Historia", "Falta");

    std::cout << "Información del estudiante en C++:\n";
    mostrarEstudianteCpp(estudianteCpp);
    mostrarMateriasCpp(estudianteCpp);
    mostrarAsistenciasCpp(estudianteCpp);

    return 0;
}