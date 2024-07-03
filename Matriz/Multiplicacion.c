#include <stdio.h>

// Función para multiplicar dos matrices 3x3
void multiplicarMatrices(int matrizA[][3], int matrizB[][3], int resultado[][3]) {
    // Inicializar la matriz resultado con 0s
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
        }
    }

    // Multiplicar las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

// Función para mostrar una matriz 3x3
void mostrarMatriz(int matriz[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
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
        {6, 5, 4},
        {3, 2, 1}
    };

    // Matriz para almacenar el resultado de la multiplicación
    int matrizResultado[3][3];

    // Multiplicar las matrices A y B
    multiplicarMatrices(matrizA, matrizB, matrizResultado);

    // Mostrar las matrices y el resultado de la multiplicación
    printf("Matriz A:\n");
    mostrarMatriz(matrizA);

    printf("\nMatriz B:\n");
    mostrarMatriz(matrizB);

    printf("\nMatriz Resultado (A * B):\n");
    mostrarMatriz(matrizResultado);

    return 0;
}