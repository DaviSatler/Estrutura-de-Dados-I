#include <stdio.h>
#include <string.h>

#define MAX 50

int codigo[MAX];
char nome[MAX][50];
int quantidade[MAX];
int qtd = 0;

int main(){

    int opcao;

    do{

        printf("\nCONTROLE DE ESTOQUE\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Atualizar quantidade\n");
        printf("3 - Remover produto\n");
        printf("4 - Mostrar relatorio\n");
        printf("5 - Sair\n");

        printf("Escolha: ");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:{

                if(qtd >= MAX){

                    printf("Limite de produtos atingido!\n");
                    break;
                }

                int cod,qtd_prod;
                char nome_prod[50];

                printf("Codigo do produto: ");
                scanf("%d",&cod);

                int duplicado = 0;

                for(int i = 0; i < qtd; i++){

                    if(codigo[i] == cod){

                        duplicado = 1;
                        break;
                    }
                }

                if(duplicado){

                    printf("Codigo ja existe!\n");
                    break;
                }

                printf("Nome do produto: ");
                scanf(" %[^\n]",nome_prod);

                printf("Quantidade: ");
                scanf("%d",&qtd_prod);

                if(qtd_prod < 0){

                    printf("Quantidade nao pode ser negativa!\n");
                    break;
                }

                codigo[qtd] = cod;
                strcpy(nome[qtd],nome_prod);
                quantidade[qtd] = qtd_prod;

                qtd++;

                printf("Produto cadastrado com sucesso!\n");

            break;
            }

            case 2:{

                int cod;

                printf("Codigo do produto: ");
                scanf("%d",&cod);

                int encontrado = 0;

                for(int i = 0; i < qtd; i++){

                    if(codigo[i] == cod){

                        encontrado = 1;

                        int nova_qtd;

                        printf("Nova quantidade: ");
                        scanf("%d",&nova_qtd);

                        if(nova_qtd < 0){

                            printf("Quantidade invalida!\n");

                        }else{

                            quantidade[i] = nova_qtd;
                            printf("Atualizado!\n");
                        }

                        break;
                    }
                }

                if(!encontrado)
                    printf("Produto nao encontrado!\n");

            break;
            }

            case 3:{

                int cod;

                printf("Codigo do produto: ");
                scanf("%d",&cod);

                int encontrado = 0;

                for(int i = 0; i < qtd; i++){

                    if(codigo[i] == cod){

                        encontrado = 1;

                        for(int j = i; j < qtd - 1; j++){

                            codigo[j] = codigo[j+1];
                            strcpy(nome[j],nome[j+1]);
                            quantidade[j] = quantidade[j+1];
                        }

                        qtd--;

                        printf("Produto removido!\n");
                        break;
                    }
                }

                if(!encontrado)
                    printf("Produto nao encontrado!\n");

            break;
            }

            case 4:{

                if(qtd == 0){

                    printf("Nenhum produto cadastrado.\n");
                    break;
                }

                printf("\n-- Estoque atual é: --\n");

                for(int i = 0; i < qtd; i++){

                    printf("Codigo: %d | Nome: %s | Quantidade: %d\n",
                           codigo[i],nome[i],quantidade[i]);
                }

            break;
            }

            case 5:

                printf("Encerrando sistema...\n");

            break;

            default:

                printf("Opcao invalida!\n");
        }

    }while(opcao != 5);

    return 0;
}