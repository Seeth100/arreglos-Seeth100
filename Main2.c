#include <stdio.h>
#include "funciones2.h"

int main() {
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                calcularTotal();
                break;
            case 3:
                encontrarExtremos();
                break;
            case 4:
                calcularPromedio();
                break;
            case 5:
                buscarProducto();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida, Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}