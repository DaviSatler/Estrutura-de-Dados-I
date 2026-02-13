#include <stdio.h>
#include <string.h>

#define MAX 50
#define TAM_NOME 50

int main() {
    int codigo[MAX], quantidade[MAX];
    char nome[MAX][TAM_NOME];
    int tamanho = 0;
    int opcao, cod, i, pos;
    int novaQtd;

    do {
        printf("\n===== ESTOQUE =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Atualizar quantidade\n");
        printf("3 - Remover produto\n");
        printf("4 - Listar produtos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if(tamanho >= MAX) {
                    printf("Estoque cheio!\n");
                    break;
                }

                printf("Digite o código: ");
                scanf("%d", &cod);

                int duplicado = 0;
                for(i = 0; i < tamanho; i++) {
                    if(codigo[i] == cod) {
                        duplicado = 1;
                        break;
                    }
                }

                if(duplicado) {
                    printf("Código já existe!\n");
                    break;
                }

                codigo[tamanho] = cod;

                printf("Digite o nome: ");
                scanf(" %[^\n]", nome[tamanho]);

                printf("Digite a quantidade: ");
                scanf("%d", &quantidade[tamanho]);

                if(quantidade[tamanho] < 0) {
                    printf("Quantidade não pode ser negativa!\n");
                    break;
                }

                tamanho++;
                break;

            case 2:
                printf("Digite o código do produto: ");
                scanf("%d", &cod);

                pos = -1;
                for(i = 0; i < tamanho; i++) {
                    if(codigo[i] == cod) {
                        pos = i;
                        break;
                    }
                }

                if(pos == -1) {
                    printf("Produto não encontrado!\n");
                } else {
                    printf("Nova quantidade: ");
                    scanf("%d", &novaQtd);

                    if(novaQtd >= 0)
                        quantidade[pos] = novaQtd;
                    else
                        printf("Quantidade inválida!\n");
                }
                break;

            case 3:
                printf("Digite o código para remover: ");
                scanf("%d", &cod);

                pos = -1;
                for(i = 0; i < tamanho; i++) {
                    if(codigo[i] == cod) {
                        pos = i;
                        break;
                    }
                }

                if(pos == -1) {
                    printf("Produto não encontrado!\n");
                } else {
                    for(i = pos; i < tamanho-1; i++) {
                        codigo[i] = codigo[i+1];
                        strcpy(nome[i], nome[i+1]);
                        quantidade[i] = quantidade[i+1];
                    }
                    tamanho--;
                    printf("Produto removido!\n");
                }
                break;

            case 4:
                printf("\nLista de Produtos:\n");
                for(i = 0; i < tamanho; i++) {
                    printf("Código: %d | Nome: %s | Quantidade: %d\n",
                           codigo[i], nome[i], quantidade[i]);
                }
                break;
        }

    } while(opcao != 0);

    return 0;
}
