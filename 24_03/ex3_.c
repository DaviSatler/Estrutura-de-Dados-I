#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarefa {
    char descricao[100];
    char prioridade[10];
    char status[15];
    struct Tarefa *ant;
    struct Tarefa *prox;
};

// Inserir no final
void inserirFim(struct Tarefa **lista) {
    struct Tarefa *novo = (struct Tarefa*) malloc(sizeof(struct Tarefa));

    printf("Descricao: ");
    scanf(" %[^\n]", novo->descricao);
    printf("Prioridade (baixa/media/alta): ");
    scanf(" %[^\n]", novo->prioridade);
    printf("Status (pendente/concluida): ");
    scanf(" %[^\n]", novo->status);

    novo->prox = NULL;

    if (*lista == NULL) {
        novo->ant = NULL;
        *lista = novo;
    } else {
        struct Tarefa *aux = *lista;

        while (aux->prox)
            aux = aux->prox;

        aux->prox = novo;
        novo->ant = aux;
    }

    printf("Tarefa inserida!\n");
}

// Remover por descrição
void remover(struct Tarefa **lista, char desc[]) {
    struct Tarefa *aux = *lista;

    while (aux && strcmp(aux->descricao, desc) != 0)
        aux = aux->prox;

    if (!aux) {
        printf("Tarefa nao encontrada!\n");
        return;
    }

    if (aux->ant)
        aux->ant->prox = aux->prox;
    else
        *lista = aux->prox;

    if (aux->prox)
        aux->prox->ant = aux->ant;

    free(aux);
    printf("Tarefa removida!\n");
}

// Exibir início → fim
void exibirInicio(struct Tarefa *lista) {
    if (!lista) {
        printf("Lista vazia!\n");
        return;
    }

    while (lista) {
        printf("\nDescricao: %s\nPrioridade: %s\nStatus: %s\n",
               lista->descricao, lista->prioridade, lista->status);
        lista = lista->prox;
    }
}

// Exibir fim → início
void exibirFim(struct Tarefa *lista) {
    if (!lista) {
        printf("Lista vazia!\n");
        return;
    }

    while (lista->prox)
        lista = lista->prox;

    while (lista) {
        printf("\nDescricao: %s\nPrioridade: %s\nStatus: %s\n",
               lista->descricao, lista->prioridade, lista->status);
        lista = lista->ant;
    }
}

// Liberar memória
void liberar(struct Tarefa *lista) {
    struct Tarefa *aux;
    while (lista) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main() {
    struct Tarefa *lista = NULL;
    int op;
    char desc[100];

    do {
        printf("\n1 - Inserir\n2 - Remover\n3 - Exibir Inicio\n4 - Exibir Fim\n0 - Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserirFim(&lista);
                break;
            case 2:
                printf("Descricao para remover: ");
                scanf(" %[^\n]", desc);
                remover(&lista, desc);
                break;
            case 3:
                exibirInicio(lista);
                break;
            case 4:
                exibirFim(lista);
                break;
        }
    } while(op != 0);

    liberar(lista);
    return 0;
}