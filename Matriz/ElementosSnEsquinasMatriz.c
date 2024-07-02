#include <stdio.h>

int main() {
    int matrisC[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matriz 3 x 3\n");
//Presenta la Matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++){
            printf("%d ", matrisC[i][j]);
        }
        printf("\n");
    }

    printf("Matriz sin los elementos de las esquinas:\n");
//Imprime los elementos de la matriz sin las esquinas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Verificar si el elemento no está en las esquinas
            if (!((i == 0 && (j == 0 || j == 2)) || (i == 2 && (j == 0 || j == 2)))) {
                printf("%d ", matrisC[i][j]);
            } else {
                printf("  "); // Espacio en lugar de los elementos de las esquinas
            }
        }
        printf("\n");
    }

    return 0;
}
