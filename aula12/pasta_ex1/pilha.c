#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* cria_pilha() {
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi->topo = NULL;
    }
    return pi;
}

void insere_elemento(Pilha *pi, int valor) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    if (novo == NULL) {
        printf("\nErro de alocação!");
        return;
    }

    novo->num = valor;
    novo->prox = pi->topo;
    pi->topo = novo;

    printf("\n%d inserido na pilha!", valor);
}

void consulta_pilha(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nPilha Vazia!!");
        return;
    }

    Elemento *aux = pi->topo;

    while (aux != NULL) {
        printf("\n%d", aux->num);
        aux = aux->prox;
    }
}

void remove_elemento_pilha(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nPilha Vazia!!");
        return;
    }

    Elemento *aux = pi->topo;
    printf("\n%d removido!", aux->num);

    pi->topo = aux->prox;
    free(aux);
}

void esvazia_pilha(Pilha *pi) {
    Elemento *aux;

    while (pi->topo != NULL) {
        aux = pi->topo;
        pi->topo = pi->topo->prox;
        free(aux);
    }

    printf("\nPilha esvaziada!");
}