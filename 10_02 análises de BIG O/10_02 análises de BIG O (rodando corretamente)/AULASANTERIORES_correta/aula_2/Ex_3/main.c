#include <stdio.h>
#include "produto.h"
#include "cliente.h"
#include "venda.h"

int main() {

    Produto produtos[MAX_PRODUTOS];
    Cliente clientes[MAX_CLIENTES];
    Venda vendas[MAX_VENDAS];

    int totalProdutos = 0;
    int totalClientes = 0;
    int totalVendas = 0;

    int op;

    do {

        printf("\n---- SISTEMA DE VENDAS (Ex3)----\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Criar venda\n");
        printf("4 - Mostrar vendas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {

            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;

            case 2:
                cadastrarCliente(clientes, &totalClientes);
                break;

            case 3:
                criarVenda(vendas, &totalVendas,
                           clientes, totalClientes,
                           produtos, totalProdutos);
                break;

            case 4:
                mostrarVendas(vendas, totalVendas);
                break;
        }

    } while (op != 0);

    return 0;
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente da opção escolhida.
