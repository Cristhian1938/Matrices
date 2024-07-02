#include <stdio.h>

void obtenerDimensiones(int matriz[][3], int *filas, int *columnas) {
    *filas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
    *columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
}

int main() {
//Matriz 3 x 3
    int matrizC[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int filas, columnas;

    // Obtener dimensiones de la matriz
    obtenerDimensiones(matrizC, &filas, &columnas);

    printf("La matriz tiene %d filas y %d columnas.\n", filas, columnas);

    return 0;
}
