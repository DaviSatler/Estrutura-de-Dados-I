#include <stdio.h>

#define MAX 50

int main() {
    float notas[MAX];
    int tamanho = 0;
    int opcao, posicao;
    float valor;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Atualizar nota\n");
        printf("4 - Mostrar notas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if(tamanho < MAX) {
                    printf("Digite a nota: ");
                    scanf("%f", &valor);
                    notas[tamanho] = valor;
                    tamanho++;
                } else {
                    printf("Vetor cheio!\n");
                }
                break;

            case 2: 
                printf("Digite a posição para remover (0 a %d): ", tamanho-1);
                scanf("%d", &posicao);

                if(posicao >= 0 && posicao < tamanho) {
                    for(int i = posicao; i < tamanho-1; i++) {
                        notas[i] = notas[i+1];
                    }
                    tamanho--;
                    printf("Nota removida!\n");
                } else {
                    printf("Posição inválida!\n");
                }
                break;

            case 3:
                printf("Digite a posição para atualizar (0 a %d): ", tamanho-1);
                scanf("%d", &posicao);

                if(posicao >= 0 && posicao < tamanho) {
                    printf("Digite a nova nota: ");
                    scanf("%f", &notas[posicao]);
                } else {
                    printf("Posição inválida!\n");
                }
                break;

            case 4: { 
                if(tamanho == 0) {
                    printf("Nenhuma nota cadastrada.\n");
                } else {
                    float soma = 0, maior = notas[0], menor = notas[0];

                    printf("Notas:\n");
                    for(int i = 0; i < tamanho; i++) {
                        printf("[%d] %.2f\n", i, notas[i]);
                        soma += notas[i];

                        if(notas[i] > maior) maior = notas[i];
                        if(notas[i] < menor) menor = notas[i];
                    }

                    printf("Média: %.2f\n", soma/tamanho);
                    printf("Maior: %.2f\n", maior);
                    printf("Menor: %.2f\n", menor);
                }
                break;
            }
        }

    } while(opcao != 0);

    return 0;
}
