#include <stdio.h>
#include <stdlib.h>

// Función para calcular el determinante de una matriz 3x3
double determinant3x3(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Función para calcular la adjunta de una matriz 3x3
void adjoint3x3(double matrix[3][3], double adj[3][3]) {
    adj[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    adj[0][1] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    adj[0][2] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];

    adj[1][0] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    adj[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    adj[1][2] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);

    adj[2][0] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
    adj[2][1] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);
    adj[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Función para calcular la inversa de una matriz 3x3
void inverse3x3(double matrix[3][3], double inverse[3][3]) {
    double det = determinant3x3(matrix);
    if (det == 0) {
        printf("La matriz no tiene inversa.\n");
        exit(1);
    }

    double adj[3][3];
    adjoint3x3(matrix, adj);

    double invDet = 1.0 / det;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverse[i][j] = adj[i][j] * invDet;
        }
    }
}

// Función para multiplicar dos matrices 3x3
void multiply3x3(double a[3][3], double b[3][3], double result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    double A[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    double B[3][3] = {
        {7, 8, 9},
        {2, 3, 4},
        {1, 4, 2}
    };

    double B_inv[3][3];
    inverse3x3(B, B_inv);  // Calcula la inversa de B

    double C[3][3];
    multiply3x3(A, B_inv, C);  // Multiplica A por la inversa de B

    printf("El resultado de A / B es:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
