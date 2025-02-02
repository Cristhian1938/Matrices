#include <stdio.h>

void sumarMatrices(int matrizA[3][3], int matrizB[3][3], int resultado[3][3]) {
    // Iterar sobre cada elemento de las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Sumar los elementos correspondientes de matrizA y matrizB
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void mostrarMatriz(int matriz[3][3]) {
    // Mostrar la matriz en formato hexadecimal
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%X ", matriz[i][j]);  // Imprimir en hexadecimal
        }
        printf("\n");
    }
}

int main() {
    // Matriz A 3x3
    int matrizA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Matriz B 3x3
    int matrizB[3][3] = {
        {9, 8, 7},
        {5, 4, 3},
        {2, 1, 0}
    };

    // Matriz para almacenar el resultado de la suma
    int matrizSuma[3][3];

    // Sumar las matrices A y B
    sumarMatrices(matrizA, matrizB, matrizSuma);

    // Mostrar la matriz resultado (matrizSuma) en hexadecimal
    printf("Matriz A:\n");
    mostrarMatriz(matrizA);

    printf("\nMatriz B:\n");
    mostrarMatriz(matrizB);

    printf("\nMatriz Suma (en hexadecimal):\n");
    mostrarMatriz(matrizSuma);

    return 0;
}
