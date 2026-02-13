#include <stdio.h>

#define MAX 100

int main() {
    int vetor[MAX];
    int n;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor original:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; ) {
            if(vetor[i] == vetor[j]) {
                for(int k = j; k < n-1; k++) {
                    vetor[k] = vetor[k+1];
                }
                n--;
            } else {
                j++;
            }
        }
    }

    printf("\n\nVetor após remover repetidos:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
//COMENTÁRIO DE MELHORIA: O código acima é uma implementação simples para remover números repetidos de um vetor. Ele utiliza dois loops aninhados para comparar cada elemento com os demais e, caso encontre um número repetido, ele desloca os elementos subsequentes para a esquerda, reduzindo o tamanho do vetor.
