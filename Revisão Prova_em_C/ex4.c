#include <stdio.h>
#include <stdlib.h>

struct No{
int valor;
struct No *prox;

};

void inserirNoInicio(struct No **lista, int valor){
    
 struct No *novo = (struct No*) malloc(sizeof(struct No));

novo->valor = valor;
novo->prox= *lista;

*lista = novo;

}

void removerPrimeiro(struct No **lista){

    if(*lista == NULL){
        printf("Lista vazia!\n");
        return;
    }

    struct No *temp = *lista;
    *lista = (*lista)->prox;

    free(temp);
}

void exibirLista(struct No *lista){

    struct No *atual = lista;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }

    printf("\n");
}

int main(){

    struct No *lista = NULL;
    int valor;

    for(int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%d", &valor);

        inserirNoInicio(&lista, valor);
    }

    printf("\nLista original:\n");
    exibirLista(lista);

    removerPrimeiro(&lista);

    printf("\nLista apos remover o primeiro:\n");
    exibirLista(lista);

    return 0;
}