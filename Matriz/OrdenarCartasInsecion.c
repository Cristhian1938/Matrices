#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define la estructura para cada elemento de la matriz
struct Matriz {
    char nombre;  // Nombre de la matriz (c, E, T, D)
    int elementos[13];  // Elementos de la matriz (1, 2, 3, ..., 13)
};

// Función para llenar la matriz con matrices que no se repitan
void llenarMatriz(struct Matriz matriz[13][4]) {
    char nombres[] = {'c', 'E', 'T', 'D'};
    int numeros[13];  // Para asegurar que no se repitan los números
    
    // Inicializar los números del 1 al 13
    for (int i = 0; i < 13; i++) {
        numeros[i] = i + 1;
    }
    
    // Desordenar los números
    srand(time(NULL));
    for (int i = 0; i < 13; i++) {
        int j = rand() % 13;
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }
    
    // Llenar la matriz
    for (int col = 0; col < 4; col++) {
        matriz[0][col].nombre = nombres[col];
        
        for (int fila = 0; fila < 13; fila++) {
            matriz[fila][col].nombre = nombres[col];
            matriz[fila][col].elementos[fila] = numeros[fila];
        }
    }
}

// Función para mostrar la matriz en el formato especificado
void mostrarMatriz(struct Matriz matriz[13][4]) {
    for (int col = 0; col < 4; col++) {
        for (int fila = 0; fila < 13; fila++) {
            printf("%d%c", matriz[fila][col].elementos[fila], matriz[fila][col].nombre);
            if (fila < 12) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Implementación del método de ordenamiento por inserción
void ordenarPorInsercion(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Matriz de 13x4 de estructuras Matriz
    struct Matriz matriz[13][4];

    // Llenar la matriz con matrices que no se repitan
    llenarMatriz(matriz);

    // Mostrar la matriz en el formato requerido
    mostrarMatriz(matriz);

    // Ejemplo de ordenamiento de una columna usando el método de inserción
    int ejemploOrdenamiento[13];
    for (int i = 0; i < 13; i++) {
        ejemploOrdenamiento[i] = matriz[i][0].elementos[i];
    }

    // Ordenar usando inserción
    ordenarPorInsercion(ejemploOrdenamiento, 13);
    printf("\nOrdenado por insercion:\n");
    for (int i = 0; i < 13; i++) {
        printf("%d ", ejemploOrdenamiento[i]);
    }
    printf("\n");

    return 0;
}
