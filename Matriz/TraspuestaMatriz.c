#include <stdio.h>
//Funcion para hacer la transpuesta
void transpuesta(int mat[][3], int trans[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans[i][j] = mat[j][i];
        }
    }
}
//Funcion para imprimir la matriz
void printMatrix(int mat[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrisC[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transpues[3][3];
    // Generar la matriz transpuesta
    transpuesta(matrisC, transpues);

    // Imprimir la matriz original
    printf("Matriz original:\n");
    printMatrix(matrisC);

    // Imprimir la matriz transpuesta
    printf("\nMatriz transpuesta:\n");
    printMatrix(transpues);

    return 0;
}
