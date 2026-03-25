#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lista de compras
typedef struct Produto{
    char nome[50]; //NOME DO PRODUTO
    int quantidade; // Quantidade
    float preco; // PREÇO
    struct Produto *prox; //PRODUTO
} Produto;  


// Adicionar produto
Produto* adicionar(Produto *lista) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));

    printf("Nome do produto: ");
    scanf(" %[^\n]", novo->nome);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    printf("Preco unico: ");
    scanf("%f", &novo->preco);

    novo->prox = lista;
    return novo;
}

// Remover produto
Produto* removerProduto(Produto *lista) {
    char nome[50];
    printf("Digite o nome do produto que será removido: ");
    scanf(" %[^\n]", nome);

    Produto *atual = lista;
    Produto *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto não encontrado!\n");
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Produto removido!\n");

    return lista;
}

// Atualizar quantidade
void atualizarQuantidade(Produto *lista) {
    char nome[50];
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);

    Produto *atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Nova quantidade: ");
            scanf("%d", &atual->quantidade);
            printf("Quantidade atualizada!\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Produto não encontrado!\n");
}

// Calcular total
void calcularTotalCompras(Produto *lista) {
    float total = 0;
    Produto *atual = lista;

    while (atual != NULL) {
        total += atual->quantidade * atual->preco;
        atual = atual->prox;
    }

    printf("Valor total da compra: R$ %.2f\n", total);
}

// Listar produtos
void listarProdutos(Produto *lista) {
    Produto *atual = lista;

    if (atual == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (atual != NULL) {
        printf("Produto: %s | Quantidade: %d | Preco: R$ %.2f\n",
               atual->nome, atual->quantidade, atual->preco);
        atual = atual->prox;
    }
}

// Main
int main() {
    Produto *lista = NULL;
    int opcao;

    do {
        printf("\n--- LISTA DE COMPRAS ---\n");
        printf("1. Adicionar produto\n");
        printf("2. Remover produto\n");
        printf("3. Atualizar quantidade\n");
        printf("4. Calcular total das compras\n");
        printf("5. Listar produtos\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                lista = adicionar(lista);
                break;
            case 2:
                lista = removerProduto(lista);
                break;
            case 3:
                atualizarQuantidade(lista);
                break;
            case 4:
                calcularTotalCompras(lista);
                break;
            case 5:
                listarProdutos(lista);
                break;
            case 0:
                printf("Codigo Encerrado.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}