//Atividade 2 – Complexidade O(n)
//Implemente um programa em C que percorra um vetor de inteiros e determine o maior e menor valor  presente.
//Leia o tamanho de um vetor de inteiros
//Receba os valores do vetor informados pelo usuário
//Percorra o vetor
//Determine e exiba o maior e o menor valor presente 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    int maior = vetor[0];
    int menor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    
}
