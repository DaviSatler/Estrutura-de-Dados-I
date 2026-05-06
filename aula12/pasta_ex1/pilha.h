#ifndef PILHA_H
#define PILHA_H

/* Estrutura do elemento */
typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

/* Estrutura da pilha */
typedef struct {
    Elemento *topo;
} Pilha;

/* Protótipos */
Pilha* cria_pilha();
void insere_elemento(Pilha *pi, int valor);
void consulta_pilha(Pilha *pi);
void remove_elemento_pilha(Pilha *pi);
void esvazia_pilha(Pilha *pi);

#endif