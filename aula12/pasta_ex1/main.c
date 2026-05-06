#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha *pi = cria_pilha();

    insere_elemento(pi, 10);
    insere_elemento(pi, 20);
    insere_elemento(pi, 30);

    printf("\n\nConteúdo da pilha:");
    consulta_pilha(pi);

    remove_elemento_pilha(pi);
    remove_elemento_pilha(pi);

    printf("\n\nApós remoções:");
    consulta_pilha(pi);

    esvazia_pilha(pi);

    return 0;
}