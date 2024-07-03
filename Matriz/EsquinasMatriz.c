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

    // Imprime las esquinas de la matriz
    printf("Las esquinas de la matriz son:\n");
    printf("%d %d\n", matrisC[0][0], matrisC[0][2]);
    printf("%d %d\n", matrisC[2][0], matrisC[2][2]);
    
    return 0;
}