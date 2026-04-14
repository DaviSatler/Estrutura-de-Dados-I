#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
    struct Contato *prox;
};

// Inserir no início
void inserir(struct Contato **lista) {
    struct Contato *novo = (struct Contato*) malloc(sizeof(struct Contato));

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);
    printf("Telefone: ");
    scanf(" %[^\n]", novo->telefone);
    printf("Email: ");
    scanf(" %[^\n]", novo->email);

    novo->prox = *lista;
    *lista = novo;

    printf("Contato inserido!\n");
}

// Remover por nome
void remover(struct Contato **lista, char nome[]) {
    struct Contato *aux = *lista;
    struct Contato *ant = NULL;

    while (aux && strcmp(aux->nome, nome) != 0) {
        ant = aux;
        aux = aux->prox;
    }

    if (!aux) {
        printf("Contato nao encontrado!\n");
        return;
    }

    if (ant == NULL)
        *lista = aux->prox;
    else
        ant->prox = aux->prox;

    free(aux);
    printf("Contato removido!\n");
}

// Buscar contato
void buscar(struct Contato *lista, char nome[]) {
    while (lista) {
        if (strcmp(lista->nome, nome) == 0) {
            printf("\nNome: %s\nTelefone: %s\nEmail: %s\n",
                   lista->nome, lista->telefone, lista->email);
            return;
        }
        lista = lista->prox;
    }
    printf("Contato nao encontrado!\n");
}

// Exibir todos
void exibir(struct Contato *lista) {
    if (!lista) {
        printf("Lista vazia!\n");
        return;
    }

    while (lista) {
        printf("\nNome: %s\nTelefone: %s\nEmail: %s\n",
               lista->nome, lista->telefone, lista->email);
        lista = lista->prox;
    }
}

// Liberar memória
void liberar(struct Contato *lista) {
    struct Contato *aux;
    while (lista) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main() {
    struct Contato *lista = NULL;
    int op;
    char nome[50];

    do {
        printf("\n1 - Inserir\n2 - Remover\n3 - Buscar\n4 - Exibir\n0 - Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserir(&lista);
                break;
            case 2:
                printf("Nome para remover: ");
                scanf(" %[^\n]", nome);
                remover(&lista, nome);
                break;
            case 3:
                printf("Nome para buscar: ");
                scanf(" %[^\n]", nome);
                buscar(lista, nome);
                break;
            case 4:
                exibir(lista);
                break;
        }
    } while(op != 0);

    liberar(lista);
    return 0;
}