#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
};

// inserir no final
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

// exibir lista
void exibirLista(struct No *lista){

    struct No *atual = lista;

    while(atual != NULL){
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }

    printf("NULL\n");
}

// buscar elemento
int buscarElemento(struct No *lista, int valor){

    struct No *atual = lista;

    while(atual != NULL){

        if(atual->valor == valor){
            return 1; // encontrou
        }

        atual = atual->prox;
    }

    return 0; // não encontrou
}

int main(){

    struct No *lista = NULL;
    int valor;

    // inserir 5 números
    for(int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserirNoFinal(&lista, valor);
    }

    printf("\nLista:\n");
    exibirLista(lista);

    // buscar número
    int busca;
    printf("\nDigite um numero para buscar: ");
    scanf("%d", &busca);

    if(buscarElemento(lista, busca)){
        printf("Numero encontrado!\n");
    } else {
        printf("Numero NAO encontrado!\n");
    }

    return 0;
}