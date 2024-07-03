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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrisC[i][j]);
        }
        printf("\n");
    }
    
    printf("Elementos impares de la Matriz:\n");

    // Imprime los elementos impares de la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrisC[i][j] % 2 != 0) { // Verifica si el elemento es impar
                printf("%d ", matrisC[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}