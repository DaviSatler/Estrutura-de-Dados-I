#ifndef VENDA_H
#define VENDA_H

#include "cliente.h"
#include "produto.h"

#define MAX_VENDAS 50
#define MAX_ITENS 10

typedef struct {
    int idCliente;
    int codigos[MAX_ITENS];
    int qtdItens;
    float total;
} Venda;

void criarVenda(
    Venda vendas[], int *totalVendas,
    Cliente clientes[], int totalClientes,
    Produto produtos[], int totalProdutos
);

void mostrarVendas(Venda vendas[], int totalVendas);

#endif
