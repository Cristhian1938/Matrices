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
    for (int fila = 0; fila < 13; fila++) {
        for (int col = 0; col < 4; col++) {
            printf("%d%c", matriz[fila][col].elementos[fila], matriz[fila][col].nombre);
            if (col < 3) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Implementación del método de ordenamiento por mezcla para una columna
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void ordenarPorMezcla(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        ordenarPorMezcla(arr, l, m);
        ordenarPorMezcla(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

int main() {
    // Matriz de 13x4 de estructuras Matriz
    struct Matriz matriz[13][4];

    // Llenar la matriz con matrices que no se repitan
    llenarMatriz(matriz);

    // Mostrar la matriz en el formato requerido
    mostrarMatriz(matriz);

    // Ejemplo de ordenamiento de una columna usando el método de mezcla
    printf("\nOrdenado por mezcla:\n");
    for (int col = 0; col < 4; col++) {
        int ejemploOrdenamiento[13];
        for (int fila = 0; fila < 13; fila++) {
            ejemploOrdenamiento[fila] = matriz[fila][col].elementos[fila];
        }
        ordenarPorMezcla(ejemploOrdenamiento, 0, 12);
        for (int fila = 0; fila < 13; fila++) {
            printf("%d ", ejemploOrdenamiento[fila]);
        }
        printf("\n");
    }

    return 0;
}
