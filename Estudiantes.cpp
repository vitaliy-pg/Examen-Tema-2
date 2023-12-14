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

void mostrarEstudianteCpp(EstudianteCpp estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nPromedio: " << estudiante.promedio << "\n";
}
void agregarMateriaCpp(EstudianteCpp& estudiante, const std::string& materia) {
    estudiante.materias.push_back(materia);
}

void eliminarMateriaCpp(EstudianteCpp& estudiante, const std::string& materia) {
    auto it = std::find(estudiante.materias.begin(), estudiante.materias.end(), materia);
    if (it != estudiante.materias.end()) {
        estudiante.materias.erase(it);
    }
}

void mostrarMateriasCpp(EstudianteCpp& estudiante) {
    std::cout << "Materias inscritas:\n";
    for (const auto& materia : estudiante.materias) {
        std::cout << "- " << materia << "\n";
    }
    std::cout << "\n";
}

struct EstudianteC {
    char nombre[50];
    int edad;
    float promedio;
    // Lista de materias en las que está inscrito el estudiante
    char materias[10][50];
    // Lista de asistencias
    struct AsistenciaC asistencias[50];
    int asistencias_count;
};

void mostrarEstudianteC(struct EstudianteC estudiante) {
    printf("Nombre: %s\nEdad: %d\nPromedio: %.2f\n", estudiante.nombre, estudiante.edad, estudiante.promedio);
}

void agregarMateriaC(struct EstudianteC* estudiante, const char* materia) {
    for (int i = 0; i < 10; ++i) {
        if (estudiante->materias[i][0] == '\0') {
            strcpy(estudiante->materias[i], materia);
            return;
        }
    }
    printf("No se pueden agregar más materias.\n");
}
void eliminarMateriaC(struct EstudianteC* estudiante, const char* materia) {
    for (int i = 0; i < 10; ++i) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            estudiante->materias[i][0] = '\0';
            return;
        }
    }
    printf("La materia no está registrada.\n");
}

void mostrarMateriasC(struct EstudianteC* estudiante) {
    printf("Materias inscritas:\n");
    for (int i = 0; i < 10 && estudiante->materias[i][0] != '\0'; ++i) {
        printf("- %s\n", estudiante->materias[i]);
    }
    printf("\n");
}

struct AsistenciaCpp {
    std::string fecha;
    std::string materia;
    std::string estado;
};

// Funciones para gestionar asistencias en C++
void registrarAsistenciaCpp(EstudianteCpp& estudiante, const std::string& fecha, const std::string& materia, const std::string& estado) {
    AsistenciaCpp asistencia;
    asistencia.fecha = fecha;
    asistencia.materia = materia;
    asistencia.estado = estado;

    estudiante.asistencias.push_back(asistencia);
}

void mostrarAsistenciasCpp(EstudianteCpp& estudiante) {
    std::cout << "Registro de asistencias:\n";
    for (const auto& asistencia : estudiante.asistencias) {
        std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << "\n";
    }
    std::cout << "\n";
}

struct AsistenciaC {
    char fecha[20];
    char materia[50];
    char estado[20];
};


void registrarAsistenciaC(struct EstudianteC* estudiante, const char* fecha, const char* materia, const char* estado) {
    // Integración de la estructura Asistencia con Estudiante
    struct AsistenciaC asistencia;
    strcpy(asistencia.fecha, fecha);
    strcpy(asistencia.materia, materia);
    strcpy(asistencia.estado, estado);

    // Agregar asistencia al estudiante
    // (En una implementación más completa, podrías usar vectores o listas en lugar de arreglos estáticos)
    // Aquí asumimos que hay un límite de 50 asistencias
    if (estudiante->asistencias_count < 50) {
        estudiante->asistencias_count++;
        estudiante->asistencias[estudiante->asistencias_count - 1] = asistencia;
    } else {
        printf("No se pueden registrar más asistencias.\n");
    }
}
