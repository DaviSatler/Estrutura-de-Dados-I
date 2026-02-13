#include <stdio.h>

#define MAX 50

int main() {

    float notas[MAX];
    int quantidade = 0;
    int op;
    int posicao;
    float novaNota;
    int i = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir Nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Atualizar nota\n");
        printf("4 - Exibir notas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &op);

        switch(op) {
            
            case 1:
                if (quantidade < MAX) {
                    printf("Digite a nota :");
                    scanf("%f", &notas[quantidade]);
                    quantidade++;
                } else {
                    printf("Vetor cheio");
                }
                break;
        
            case 2: 
                if (quantidade > 0) {
                    printf("Qual o índice da nota que desekja remover? ");
                    scanf("%d", &posicao);

                    if (posicao >= 0 && posicao <quantidade) {
                        
                        for (i = posicao; i < quantidade - 1; i++) {
                            notas[i] = notas[i+1];
                        }

                        quantidade--;
                        printf("Nota removida.\n");
                    } else {
                        printf("Posição Inválida.\n");
                    }
                } else {
                    printf("Não existe nenhuma nota registrada.\n");
                }
                break;

            case 3: 
                if (quantidade > 0) {
                    printf("Qual o índice da nota que deseja atualizar? \n");
                    scanf("%d", &posicao);

                    if (posicao >= 0 && posicao < quantidade) {
                        printf("Nova nota: \n");
                        scanf("%f", &novaNota);
                        notas[posicao] = novaNota;
                        printf("Nota atualizada.\n");
                    } else {
                        printf("Índice inválido.\n");
                    }

                } else {
                    printf("Não há notas para remover.\n");
                }
                break;
            case 4:
                if(quantidade > 0){
                    
                    float soma = 0;
                    float maior = notas[0];
                    float menor = notas[0];

                    printf("Notas cadastradas:\n");

                    for (i = 0; i < quantidade; i++){
                        printf("Posição %d: %.2f\n", i, notas[i]);
                        soma += notas[i];

                        if(notas[i] > maior){
                            maior = notas[i];
                        }

                        if(notas[i] < menor){
                            menor = notas[i];
                        }
                    }

                    printf("Media: %.2f\n", soma/quantidade);
                    printf("Maior: %.2f\n", maior);
                    printf("Menor: %.2f\n", menor);
                } else {
                    printf("Nenhuma nota cadastrada.\n");
                }
                break;
            case 0:
                printf("Encerrando programa.");
                break;
            
            default: 
                printf("Inválido!");
        } 
    } while(op != 0);

    return 0;
}
//COMENTÁRIO DE MELHORIA: O código está bem estruturado e funcional, mas poderia ser melhorado com a adição de funções para cada operação (inserir, remover, atualizar, exibir) para tornar o código mais modular e fácil de ler. Além disso, seria interessante adicionar validação de entrada para garantir que as notas inseridas estejam dentro de um intervalo válido (por exemplo, entre 0 e 10).
