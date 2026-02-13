#include <stdio.h>
#include "vetor.h"

int main() {
    int vetor[MAX], quantidade;

    printf("Digite a quantidade de valores (max %d): ", MAX);
    scanf("%d", &quantidade);

    if (quantidade > MAX || quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return 1;
    }

    printf("Digite %d valores inteiros:\n", quantidade);
    for (int indice = 0; indice < quantidade; indice++) {
        scanf("%d", &vetor[indice]);
    }

    printf("\nVetor original:\n");
    mostrarVetor(vetor, quantidade);

    removerRepetidos(vetor, &quantidade);

    printf("\nVetor após remoção e compactação:\n");
    mostrarVetor(vetor, quantidade);

    ordenarVetor(vetor, quantidade);

    printf("\nVetor ordenado:\n");
    mostrarVetor(vetor, quantidade);

    return 0;
}
//comentários de melhoria: 
//1. O código não verifica se o valor digitado está dentro do intervalo permitido (0 a 100).
//2. A função `removerRepetidos` pode ser otimizada para reduzir a complexidade de tempo.
