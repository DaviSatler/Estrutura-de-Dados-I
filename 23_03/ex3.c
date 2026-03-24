#include <stdio.h>
#include <stdlib.h>

int main() {
    int L, C;
    int **matriz;
    int i, j;
    int maior;


    printf("Digite o numero de linhas: ");
    scanf("%d", &L);
    printf("Digite o numero de colunas: ");
    scanf("%d", &C);

    matriz = (int **) malloc(L * sizeof(int *));

    if (matriz == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (i = 0; i < L; i++) {
        matriz[i] = (int *) malloc(C * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }
    }

    printf("Digite os valores da matriz:\n");
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if (i == 0 && j == 0) {
                maior = matriz[i][j];
            } else if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    printf("\nSoma de cada linha:\n");
    for (i = 0; i < L; i++) {
        int soma = 0;
        for (j = 0; j < C; j++) {
            soma += matriz[i][j];
        }
        printf("Linha %d: %d\n", i, soma);
    }

    printf("\nMaior elemento da matriz: %d\n", maior);

    for (i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz); 

    return 0;
}