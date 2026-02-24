//Implemente, em linguagem C, um algoritmo que receba um vetor de inteiros e retorne o valor armazenado em uma posição específica informada pelo usuário.
//Solicite ao usuário o tamanho do vetor
//Preencha o vetor com valores inteiros informados pelo usuário
//Solicite uma posição (índice) para consulta
//Exiba o valor armazenado nessa posição
//Faça validação para impedir acesso a posições inválidas

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    int posicao;

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

    printf("Digite a posição (índice) para consulta: ");
    scanf("%d", &posicao);

    if (posicao >= 0 && posicao < tamanho) {
        printf("Valor na posição %d: %d\n", posicao, vetor[posicao]);
    } else {
        printf("Posição inválida. Por favor, insira um índice entre 0 e %d.\n", tamanho - 1);
    }

    
    return 0;
}