#include <stdio.h>
#include "vetor.h"

void removerRepetidos(int vetor[], int *tamanho) {
    for (int indiceAtual = 0; indiceAtual < *tamanho; indiceAtual++) {
        for (int indiceComparacao = indiceAtual + 1; indiceComparacao < *tamanho; ) {
            if (vetor[indiceComparacao] == vetor[indiceAtual]) {
                for (int indiceDeslocamento = indiceComparacao; indiceDeslocamento < *tamanho - 1; indiceDeslocamento++) {
                    vetor[indiceDeslocamento] = vetor[indiceDeslocamento + 1];
                }
                (*tamanho)--;
            } else {
                indiceComparacao++;
            }
        }
    }
}

void ordenarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                int temporario = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temporario;
            }
        }
    }
}

void mostrarVetor(int vetor[], int tamanho) {
    for (int indice = 0; indice < tamanho; indice++) {
        printf("%d ", vetor[indice]);
    }
    printf("\n");
}