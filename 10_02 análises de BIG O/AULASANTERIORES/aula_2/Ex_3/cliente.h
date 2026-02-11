#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 100

typedef struct {
    int id;
    char nome[50];
} Cliente;

void cadastrarCliente(Cliente lista[], int *total);

#endif
