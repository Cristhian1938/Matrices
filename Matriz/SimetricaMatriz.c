#include <stdio.h>
//Imprimir la matriz
void printMatrix(int mat[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

//
void makeSymmetric(int mat[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            // Hacer que mat[i][j] sea igual a mat[j][i]
            mat[j][i] = mat[i][j];
        }
    }
}

int main() {
//Matriz de 3 x 3
    int matrisC[3][3] = {
        {-2, 1, 4},
        {1, 3, 0},
        {4, 0, 1}
    };

    // Imprimir matriz original
    printf("Matriz original:\n");
    printMatrix(matrisC);

    // Hacer la matriz simétrica
    makeSymmetric(matrisC);

    // Imprimir matriz simétrica
    printf("\nMatriz simétrica:\n");
    printMatrix(matrisC);

    return 0;
}
