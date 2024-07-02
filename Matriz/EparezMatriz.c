#include <stdio.h>

int main(){

    int matrisC [3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
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
    
    printf("Elementos pares de la Matriz:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrisC[i][j] % 2 == 0) { // Verificar si el elemento es par
                printf("%d ", matrisC[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}