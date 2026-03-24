#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    vetor = (int *) calloc(n, sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("\nVetor apos calloc (inicializado com zero):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n\nDigite novos valores para o vetor:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("\nVetor atualizado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}