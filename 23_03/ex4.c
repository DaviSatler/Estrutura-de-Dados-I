#include <stdio.h>
#include <stdlib.h>

void alocarVetor(int **vetor, int tamanho) {
    *vetor = (int *) calloc(tamanho, sizeof(int));

    if (*vetor == NULL) {
        printf("0 = Erro ao alocar memoria!\n");
        exit(1);
    }
}

int main() {
    int *vetor = NULL;
    int n, i, novo_tamanho;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);

    alocarVetor(&vetor, n);

    printf("\nAgora, preencha o seu vetor:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor inicial:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nDigite agora o tamanho do novo vetor! ");
    scanf("%d", &novo_tamanho);

    vetor = (int *) realloc(vetor, novo_tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("0 = Erro ao realocar memoria!\n");
        return 1;
    }

    printf("\nPreencha o vetor novamente:\n");
    for (i = 0; i < novo_tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor atualizado:\n");
    for (i = 0; i < novo_tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}