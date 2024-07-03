#include <stdio.h>

int main() {
    // Declaración e inicialización de una matriz 3x3
    int matrisC[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matriz 3 x 3\n");

    // Presenta la Matriz
    for (int i = 0; i < 3; i++) { // Itera sobre las filas
        for (int j = 0; j < 3; j++) { // Itera sobre las columnas
            printf("%d ", matrisC[i][j]); // Imprime cada elemento de la matriz
        }
        printf("\n"); // Nueva línea después de cada fila
    }
    
    printf("Elementos impares de la Matriz:\n");

    // Itera sobre la matriz para encontrar e imprimir los elementos impares
    for (int i = 0; i < 3; i++) { // Itera sobre las filas
        for (int j = 0; j < 3; j++) { // Itera sobre las columnas
            if (matrisC[i][j] % 2 != 0) { // Verifica si el elemento es impar
                printf("%d ", matrisC[i][j]); // Imprime el elemento impar
            }
        }
    }
    printf("\n");

    return 0;
}