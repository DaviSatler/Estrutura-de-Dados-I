#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

/* Registro que representa cada elemento da fila */
typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

/* Registro do tipo Fila com ponteiros para início e fim */
typedef struct Fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

/* Protótipos das funções */
Fila *cria_fila();
void insere_elemento(Fila *fi);
void consulta_fila(Fila *fi);
void remove_elemento_fila(Fila *fi);

#endif