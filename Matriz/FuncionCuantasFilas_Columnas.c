#include <stdio.h>

// Función para obtener las dimensiones de la matriz
void obtenerDimensiones(int matriz[][3], int *filas, int *columnas) {
    *filas = sizeof(matriz[0]) / sizeof(matriz[0][0]); // Número de filas
    *columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]); // Número de columnas
}

int main() {
    // Matriz 3x3
    int matrizC[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int filas, columnas;

    // Obtener dimensiones de la matriz
    obtenerDimensiones(matrizC, &filas, &columnas);

    // Imprimir dimensiones de la matriz
    printf("La matriz tiene %d filas y %d columnas.\n", filas, columnas);

    return 0;
}