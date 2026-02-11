#include <stdio.h>
#include <string.h>
#include "cliente.h"

void cadastrarCliente(Cliente lista[], int *total) {

    if (*total >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("\n=== Cadastro de Cliente ===\n");

    printf("ID: ");
    scanf("%d", &lista[*total].id);
    getchar();

    printf("Nome: ");
    fgets(lista[*total].nome, 50, stdin);
    lista[*total].nome[strcspn(lista[*total].nome, "\n")] = 0;

    (*total)++;

    printf("Cliente cadastrado!\n");
}
