#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

void cadastrarProduto(Produto lista[], int *total);

#endif
