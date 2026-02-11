#include <stdio.h>

#define MAX 50

int main() {
    float notas[MAX];
    int qtd = 0; // quantidade atual de notas
    int opcao;

    do {
        printf("\n===== GERENCIAMENTO DE NOTAS =====\n");
        printf("1 - Inserir nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Atualizar nota\n");
        printf("4 - Mostrar relatorio\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

        case 1: { // Inserir
            if (qtd >= MAX) {
                printf("Vetor cheio!\n");
            } else {
                printf("Digite a nota: ");
                scanf("%f", &notas[qtd]);
                qtd++;
                printf("Nota inserida!\n");
            }
            break;
        }

        case 2: { // Remover
            int pos;
            if (qtd == 0) {
                printf("Nenhuma nota cadastrada!\n");
                break;
            }

            printf("Digite a posicao para remover (0 a %d): ", qtd - 1);
            scanf("%d", &pos);

            if (pos < 0 || pos >= qtd) {
                printf("Posicao invalida!\n");
            } else {
                for (int i = pos; i < qtd - 1; i++) {
                    notas[i] = notas[i + 1];
                }
                qtd--;
                printf("Nota removida!\n");
            }
            break;
        }

        case 3: { // Atualizar
            int pos;

            if (qtd == 0) {
                printf("Nenhuma nota cadastrada!\n");
                break;
            }

            printf("Digite a posicao para atualizar (0 a %d): ", qtd - 1);
            scanf("%d", &pos);

            if (pos < 0 || pos >= qtd) {
                printf("Posicao invalida!\n");
            } else {
                printf("Nova nota: ");
                scanf("%f", &notas[pos]);
                printf("Nota atualizada!\n");
            }
            break;
        }

        case 4: { // Relatório
            if (qtd == 0) {
                printf("Nenhuma nota cadastrada!\n");
                break;
            }

            float soma = 0;
            float maior = notas[0];
            float menor = notas[0];

            printf("\nNotas cadastradas:\n");

            for (int i = 0; i < qtd; i++) {
                printf("[%d] %.2f\n", i, notas[i]);

                soma += notas[i];

                if (notas[i] > maior) maior = notas[i];
                if (notas[i] < menor) menor = notas[i];
            }

            printf("\nMedia: %.2f\n", soma / qtd);
            printf("Maior nota: %.2f\n", maior);
            printf("Menor nota: %.2f\n", menor);

            break;
        }

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
