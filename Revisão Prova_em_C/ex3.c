#include <stdio.h>
#include <stdlib.h>


struct No{
    int valor;
    struct No *prox;

};

void inserirNoFinal(struct No **lista, int valor){

    struct No *novo = (struct No*) malloc(sizeof(struct No));

    novo->valor = valor;
    novo->prox = NULL;

    if(*lista == NULL){
        *lista = novo;
    } else {
        struct No *atual = *lista;

        while(atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novo;
    }
}

void exibirLista(struct No *lista){

    struct No *atual = lista;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }

    printf("\n");
}

int contarElementos(struct No *lista){

    int contador = 0;
    struct No *atual = lista;

    while(atual != NULL){
        contador++;
        atual = atual->prox;
    }

    return contador;
}


int main(){

    struct No *lista = NULL;
    int valor;

    for(int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserirNoFinal(&lista, valor);
    }

    printf("\nLista:\n");
    exibirLista(lista);

    int total = contarElementos(lista);
    printf("Quantidade de elementos: %d\n", total);

    return 0;
}