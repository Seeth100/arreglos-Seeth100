#include <stdio.h>
#include "funciones2.h"


char nombres[10][50];
float precios[10];
int cantidades[10];
int totalProductos = 0;


void copiarCadena(char destino[], char origen[]) {
    int i = 0;
    while (origen[i] != '\0' && i < 50 - 1) {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; 
}


int compararCadenas(char a[], char b[]) {
    for (int i = 0; i < 50; i++) {
        if (a[i] != b[i]) return 0;
        if (a[i] == '\0' && b[i] == '\0') return 1;
    }
    return 0;
}


int buscarIndiceProducto(char nombre[]) {
    for (int i = 0; i < totalProductos; i++) {
        if (compararCadenas(nombres[i], nombre)) {
            return i;
        }
    }
    return -1;
}

void agregarProducto() {
    if (totalProductos >= 10) {
        printf("No se pueden agregar mas de %d productos.\n", 10);
        return;
    }

    char nombre[50];
    printf("Ingrese el nombre del producto: ");
    scanf(" %s", nombre);
    fflush(stdin);

    if (buscarIndiceProducto(nombre) != -1) {
        printf("Este producto ya existe.\n");
        return;
    }

    float precio;
    int cantidad;
    int resultado;

    do {
        printf("Ingrese el precio del producto: ");
        resultado = scanf("%f", &precio);
        fflush(stdin);
        if (resultado != 1 || precio < 0) {
            printf("Entrada invalida. Ingrese un numero positivo.\n");
        }
    } while (resultado != 1 || precio < 0);

    do {
        printf("Ingrese la cantidad del producto: ");
        resultado = scanf("%d", &cantidad);
        fflush(stdin);
        if (resultado != 1 || cantidad < 0) {
            printf("Entrada invalida. Ingrese un numero entero positivo.\n");
        }
    } while (resultado != 1 || cantidad < 0);

    copiarCadena(nombres[totalProductos], nombre);
    precios[totalProductos] = precio;
    cantidades[totalProductos] = cantidad;

    totalProductos++;
    printf("Producto agregado correctamente.\n");
}

void calcularTotal() {
    float total = 0;
    for (int i = 0; i < totalProductos; i++) {
        total += precios[i] * cantidades[i];
    }
    printf("Valor total del inventario: %.2f\n", total);
}

void encontrarExtremos() {
    if (totalProductos == 0) {
        printf("No hay productos en el inventario\n");
        return;
    }

    int indiceMax = 0, indiceMin = 0;
    for (int i = 1; i < totalProductos; i++) {
        if (precios[i] > precios[indiceMax]) indiceMax = i;
        if (precios[i] < precios[indiceMin]) indiceMin = i;
    }

    printf("Producto mas caro: %s %.2f Cantidad: %d\n", nombres[indiceMax], precios[indiceMax], cantidades[indiceMax]);
    printf("Producto mas barato: %s %.2f Cantidad: %d\n", nombres[indiceMin], precios[indiceMin], cantidades[indiceMin]);
}

void calcularPromedio() {
    if (totalProductos == 0) {
        printf("No hay productos en el inventario\n");
        return;
    }

    float suma = 0;
    for (int i = 0; i < totalProductos; i++) {
        suma += precios[i];
    }
    printf("Precio promedio: %.2f\n", suma / totalProductos);
}

void buscarProducto() {
    char nombre[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf(" %s", nombre);
    fflush(stdin);

    int indice = buscarIndiceProducto(nombre);
    if (indice == -1) {
        printf("Producto no encontrado\n");
    } else {
        printf("Producto encontrado: %s - Precio: %.2f - Cantidad: %d\n", nombres[indice], precios[indice], cantidades[indice]);
    }
}

void mostrarMenu() {
    printf("\nMENU\n");
    printf("1. Agregar producto\n");
    printf("2. Calcular valor total del inventario\n");
    printf("3. Encontrar producto mas caro y mas barato\n");
    printf("4. Calcular precio promedio\n");
    printf("5. Buscar producto por nombre\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
}