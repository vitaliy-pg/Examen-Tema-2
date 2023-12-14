#include <iostream>
#include <vector>
#include <string>
#include <cstring> // Necesario para strcpy en C

// Estructura Estudiante en C++
struct EstudianteCpp {
    std::string nombre;
    int edad;
    float promedio;
    // Lista de materias en las que está inscrito el estudiante
    std::vector<std::string> materias;
    // Lista de asistencias
    std::vector<struct AsistenciaCpp> asistencias;
};

// Función para mostrar información del estudiante en C++
void mostrarEstudianteCpp(EstudianteCpp estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << "\nEdad: " << estudiante.edad << "\nPromedio: " << estudiante.promedio << "\n";
}

// Funciones para gestionar materias en C++
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

// Estructura Estudiante en C
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

// Función para mostrar información del estudiante en C
void mostrarEstudianteC(struct EstudianteC estudiante) {
    printf("Nombre: %s\nEdad: %d\nPromedio: %.2f\n", estudiante.nombre, estudiante.edad, estudiante.promedio);
}

// Funciones para gestionar materias en C
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

// Estructura Asistencia en C++
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

// Estructura Asistencia en C
struct AsistenciaC {
    char fecha[20];
    char materia[50];
    char estado[20];
};

// Funciones para gestionar asistencias en C
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

void mostrarAsistenciasC(struct EstudianteC* estudiante) {
    printf("Registro de asistencias:\n");
    for (int i = 0; i < estudiante->asistencias_count; ++i) {
        printf("Fecha: %
                       .asistencias[i].fecha,
               estudiante->asistencias[i].materia, estudiante->asistencias[i].estado);
    }
    printf("\n");
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

    // Uso de la estructura y funciones en C
    struct EstudianteC estudianteC;
    strcpy(estudianteC.nombre, "Juan");
    estudianteC.edad = 20;
    estudianteC.promedio = 8.5;

    agregarMateriaC(&estudianteC, "Matemáticas");
    agregarMateriaC(&estudianteC, "Historia");

    registrarAsistenciaC(&estudianteC, "01/01/2023", "Matemáticas", "Asistió");
    registrarAsistenciaC(&estudianteC, "02/01/2023", "Historia", "Falta");

    printf("Información del estudiante en C:\n");
    mostrarEstudianteC(estudianteC);
    mostrarMateriasC(&estudianteC);
    mostrarAsistenciasC(&estudianteC);




