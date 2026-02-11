#include <stdio.h>
#include "venda.h"

void criarVenda(
    Venda vendas[], int *totalVendas,
    Cliente clientes[], int totalClientes,
    Produto produtos[], int totalProdutos
) {

    if (*totalVendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    int id;
    printf("\nID do cliente: ");
    scanf("%d", &id);

    int clienteValido = 0;

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id)
            clienteValido = 1;
    }

    if (!clienteValido) {
        printf("Cliente nao encontrado!\n");
        return;
    }

    Venda *v = &vendas[*totalVendas];

    v->idCliente = id;
    v->qtdItens = 0;
    v->total = 0;

    printf("\nDigite os codigos dos produtos (0 para encerrar)\n");

    while (1) {

        int codigo;
        printf("Produto: ");
        scanf("%d", &codigo);

        if (codigo == 0)
            break;

        // Procura o produto
        int achou = -1;

        for (int i = 0; i < totalProdutos; i++) {
            if (produtos[i].codigo == codigo)
                achou = i;
        }

        if (achou != -1 && v->qtdItens < MAX_ITENS) {

            v->codigos[v->qtdItens++] = codigo;
            v->total += produtos[achou].preco;

            printf("Produto adicionado!\n");

        } else {
            printf("Produto invalido!\n");
        }
    }

    (*totalVendas)++;

    printf("Venda finalizada! Total = R$ %.2f\n", v->total);
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente do número de clientes ou produtos cadastrados.

void mostrarVendas(Venda vendas[], int totalVendas) {

    if (totalVendas == 0) {
        printf("\nNenhuma venda registrada.\n");
        return;
    }

    printf("\n=== Vendas Registradas ===\n");

    for (int i = 0; i < totalVendas; i++) {

        printf("\nVenda %d\n", i + 1);
        printf("Cliente ID: %d\n", vendas[i].idCliente);
        printf("Itens: %d\n", vendas[i].qtdItens);
        printf("Total: R$ %.2f\n", vendas[i].total);
    }
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante