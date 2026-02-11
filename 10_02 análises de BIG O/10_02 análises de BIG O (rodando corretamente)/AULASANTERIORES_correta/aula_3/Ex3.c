//Atividade 3 – Compactação e Ordenação de Vetor
//Desenvolva um programa em C que manipule um array de inteiros. Leia N valores inteiros e
//armazene em um vetor. Remova todos os valores repetidos, mantendo apenas a primeira
//ocorrência. Após a remoção, compacte o vetor ajustando corretamente o tamanho. Mostre o vetor antes da remoção, após a compactação.

#include <stdio.h>
#define MAX 50

int main() {
    int vetor[MAX];
    int qtd = 0; // quantidade atual de elementos

    printf("Quantos numeros deseja inserir (max %d)? ", MAX);
    scanf("%d", &qtd);

    if (qtd < 1 || qtd > MAX) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    // Leitura dos valores
    for (int i = 0; i < qtd; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Mostrar vetor antes da remoção
    printf("\nVetor antes da remoção:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Remover valores repetidos
    int novo_qtd = 0; // nova quantidade após remoção
    for (int i = 0; i < qtd; i++) {
        int repetido = 0;
        for (int j = 0; j < novo_qtd; j++) {
            if (vetor[i] == vetor[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            vetor[novo_qtd] = vetor[i];
            novo_qtd++;
        }
    }

    // Mostrar vetor após a compactação
    printf("\nVetor apos a compactacao:\n");
    for (int i = 0; i < novo_qtd; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente da opção escolhida.