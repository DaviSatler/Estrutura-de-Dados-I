
#include <stdio.h>
#include <string.h>
#include "produto.h"

void cadastrarProduto(Produto lista[], int *total) {

    if (*total >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("\n=== Cadastro de Produto ===\n");

    printf("Codigo: ");
    scanf("%d", &lista[*total].codigo);
    getchar();

    printf("Nome: ");
    fgets(lista[*total].nome, 50, stdin);
    lista[*total].nome[strcspn(lista[*total].nome, "\n")] = 0;

    printf("Preco: ");
    scanf("%f", &lista[*total].preco);

    (*total)++;

    printf("Produto cadastrado com sucesso!\n");
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente do número de cadastrados.
