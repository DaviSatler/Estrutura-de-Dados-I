#ifndef FILA_BANCO_H
#define FILA_BANCO_H

#include <stdio.h>
#include <stdlib.h>

/* Registro que representa cada cliente na fila */
typedef struct Cliente {
    int id;
    int tempo_atendimento;
    struct Cliente *prox;
} Cliente;

/* Registro da fila com ponteiros para início e fim */
typedef struct Fila {
    Cliente *inicio;
    Cliente *fim;
    int total_clientes;
} Fila;

/* Protótipos das funções */
Fila   *cria_fila();
void    insere_cliente(Fila *fi, int id, int tempo);
void    atende_cliente(Fila *fi);
void    consulta_fila(Fila *fi);
int     calcula_tempo_espera(Fila *fi);
void    libera_fila(Fila *fi);

#endif
