#include <stdio.h>
#include <stdlib.h>

#define N 3  // Definimos el tamaño de la matriz (3x3 en este caso)

// Función para imprimir una matriz
void imprimirMatriz(double matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para intercambiar dos filas de una matriz
void intercambiarFilas(double matriz[N][N], int fila1, int fila2) {
    for (int j = 0; j < N; j++) {
        double temp = matriz[fila1][j];
        matriz[fila1][j] = matriz[fila2][j];
        matriz[fila2][j] = temp;
    }
}

// Función para realizar la eliminación de Gauss-Jordan para encontrar la inversa
void gaussJordan(double matriz[N][N], double matrizInversa[N][N]) {
    // Inicializamos la matriz inversa como la matriz identidad
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                matrizInversa[i][j] = 1.0;
            else
                matrizInversa[i][j] = 0.0;
        }
    }

    // Proceso de eliminación de Gauss-Jordan
    for (int i = 0; i < N; i++) {
        // Si el elemento diagonal es cero, intercambiamos filas
        if (matriz[i][i] == 0.0) {
            int filaNoNula = i + 1;
            while (filaNoNula < N && matriz[filaNoNula][i] == 0.0)
                filaNoNula++;
            
            if (filaNoNula == N) {
                printf("La matriz no tiene inversa (es singular).\n");
                exit(1);
            }

            intercambiarFilas(matriz, i, filaNoNula);
            intercambiarFilas(matrizInversa, i, filaNoNula);
        }

        // Hacemos que el elemento diagonal sea igual a 1
        double divisor = matriz[i][i];
        for (int j = 0; j < N; j++) {
            matriz[i][j] /= divisor;
            matrizInversa[i][j] /= divisor;
        }

        // Hacemos ceros en las columnas por debajo del elemento diagonal
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = matriz[k][i];
                for (int j = 0; j < N; j++) {
                    matriz[k][j] -= factor * matriz[i][j];
                    matrizInversa[k][j] -= factor * matrizInversa[i][j];
                }
            }
        }
    }
}

int main() {
    double matriz[N][N] = {
        {2, 1, -1},
        {0, 1, 2},
        {1, 1, 1}
    };

    double matrizInversa[N][N];

    gaussJordan(matriz, matrizInversa);

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    printf("\nMatriz inversa:\n");
    imprimirMatriz(matrizInversa);

    return 0;
}
