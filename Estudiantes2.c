#include <stdio.h>

int main() {
    int calificaciones[5][3];
    int opc, cont = 0;
    float promedio[5];
    float promedio_asignatura[3];

    do {
        printf("\n----- MENU DE OPCIONES -----\n");
        printf("1. Ingreso de estudiantes\n");
        printf("2. Ver notas y estudiantes\n");
        printf("3. Promedio por estudiante\n");
        printf("4. Promedio por materia\n");
        printf("5. Calificacion mas alta y baja\n");
        printf("6. Aprobados y reprobados por asignatura\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opc) != 1) {
            printf("Entrada invalida. Ingrese un numero.\n");
            fflush(stdin);
            continue;
        }

        switch (opc) {
        case 1: {
            if (cont >= 5) {
                printf("Ya se ingresaron todos los estudiantes permitidos.\n");
                break;
            }
            printf("\nIngrese las calificaciones del Estudiante %d:\n", cont + 1);
            for (int m = 0; m < 3; m++) {
                int nota;
                while (1) {
                    printf("Materia %d (1-10): ", m + 1);
                    if (scanf("%d", &nota) == 1 && nota >= 1 && nota <= 10) {
                        break;
                    } else {
                        printf("Entrada invalida. Ingrese un numero entre 1 y 10.\n");
                        fflush(stdin);
                    }
                }
                calificaciones[cont][m] = nota;
            }
            cont++; 
            break;
        }

        case 2: {
            if (cont == 0) {
                printf("Debe ingresar al menos un estudiante primero.\n");
                break;
            }
            printf("Informacion de estudiantes\n");
            printf("Estudiante\tMateria 1\tMateria 2\tMateria 3\n");
            for (int i = 0; i < cont; i++) {
                printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1,
                       calificaciones[i][0], calificaciones[i][1], calificaciones[i][2]);
            }
            break;
        }

        case 3: {
            if (cont == 0) {
                printf("Debe ingresar al menos un estudiante primero.\n");
                break;
            }
            printf("Promedio por estudiante\n");
            for (int i = 0; i < cont; i++) {
                promedio[i] = (calificaciones[i][0] + calificaciones[i][1] + calificaciones[i][2]) / 3.0;
                printf("Estudiante %d: Promedio = %.2f\n", i + 1, promedio[i]);
            }
            break;
        }

        case 4: {
            if (cont == 0) {
                printf("Debe ingresar al menos un estudiante primero.\n");
                break;
            }
            printf("Promedio por materia\n");
            for (int m = 0; m < 3; m++) {
                promedio_asignatura[m] = 0;
                for (int i = 0; i < cont; i++) {
                    promedio_asignatura[m] += calificaciones[i][m];
                }
                promedio_asignatura[m] /= cont;
                printf("Materia %d: Promedio = %.2f\n", m + 1, promedio_asignatura[m]);
            }
            break;
        }

        case 5: {
            if (cont == 0) {
                printf("Debe ingresar al menos un estudiante primero.\n");
                break;
            }
            printf("Calificacion mas alta y baja\n");
            for (int m = 0; m < 3; m++) {
                int max = calificaciones[0][m];
                int min = calificaciones[0][m];
                for (int i = 1; i < cont; i++) {
                    if (calificaciones[i][m] > max) {
                        max = calificaciones[i][m];
                    }
                    if (calificaciones[i][m] < min) {
                        min = calificaciones[i][m];
                    }
                }
                printf("Materia %d: Maxima = %d, Minima = %d\n", m + 1, max, min);
            }
            break;
        }

        case 6: {
            if (cont == 0) {
                printf("Debe ingresar al menos un estudiante primero.\n");
                break;
            }
            printf("Aprobados y reprobados por asignatura\n");
            for (int m = 0; m < 3; m++) {
                int aprobados = 0;
                int reprobados = 0;
                for (int i = 0; i < cont; i++) {
                    if (calificaciones[i][m] >= 6) {
                        aprobados++;
                    } else {
                        reprobados++;
                    }
                }
                printf("Materia %d: Aprobados = %d, Reprobados = %d\n", m + 1, aprobados, reprobados);
            }
            break;
        }

        case 7:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida, Intente de nuevo.\n");
            break;
        }
    } while (opc != 7);

    return 0;
}
