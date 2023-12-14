#include <stdio.h>
#include <string.h>

// Estructura Asistencia en C
struct AsistenciaC {
    char fecha[20];
    char materia[50];
    char estado[20];
};

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
void agregarMateriaC(struct EstudianteC *estudiante, const char *materia) {
    for (int i = 0; i < 10; ++i) {
        if (estudiante->materias[i][0] == '\0') {
            strcpy(estudiante->materias[i], materia);
            return;
        }
    }
    printf("No se pueden agregar más materias.\n");
}

void eliminarMateriaC(struct EstudianteC *estudiante, const char *materia) {
    for (int i = 0; i < 10; ++i) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            estudiante->materias[i][0] = '\0';
            return;
        }
    }
    printf("La materia no está registrada.\n");
}

void mostrarMateriasC(struct EstudianteC *estudiante) {
    printf("Materias inscritas:\n");
    for (int i = 0; i < 10 && estudiante->materias[i][0] != '\0'; ++i) {
        printf("- %s\n", estudiante->materias[i]);
    }
    printf("\n");
}

// Funciones para gestionar asistencias en C
void registrarAsistenciaC(struct EstudianteC *estudiante, const char *fecha, const char *materia, const char *estado) {
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

void mostrarAsistenciasC(struct EstudianteC *estudiante) {
    printf("Registro de asistencias:\n");
    for (int i = 0; i < estudiante->asistencias_count; ++i) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n", estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia, estudiante->asistencias[i].estado);
    }
    printf("\n");
}

int main() {
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

    return 0;
}