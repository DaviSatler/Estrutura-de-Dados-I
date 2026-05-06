#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

/* Estrutura do elemento */
typedef struct Elemento {
    char tarefa[TAM];
    struct Elemento *prox;
} Elemento;

/* Estrutura da pilha */
typedef struct {
    Elemento *topo;
} Pilha;

/* Criar pilha */
Pilha* cria_pilha() {
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi->topo = NULL;
    }
    return pi;
}

/* Inserir tarefa */
void inserir_tarefa(Pilha *pi) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    if (novo == NULL) {
        printf("\nErro de alocação!");
        return;
    }

    printf("\nDigite a tarefa: ");
    getchar(); // limpar buffer
    fgets(novo->tarefa, TAM, stdin);

    /* remover \n do fgets */
    novo->tarefa[strcspn(novo->tarefa, "\n")] = '\0';

    novo->prox = pi->topo;
    pi->topo = novo;

    printf("\nTarefa adicionada!");
}

/* Obter próxima tarefa (remover do topo) */
void obter_tarefa(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nNenhuma tarefa na pilha!");
        return;
    }

    Elemento *aux = pi->topo;

    printf("\nExecutando tarefa: %s", aux->tarefa);

    pi->topo = aux->prox;
    free(aux);
}

/* Menu */
int main() {
    Pilha *pi = cria_pilha();
    int opcao;

    do {
        printf("\n\n===== PILHA DE TAREFAS =====");
        printf("\n1 - Inserir tarefa");
        printf("\n2 - Obter próxima tarefa");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserir_tarefa(pi);
                break;
            case 2:
                obter_tarefa(pi);
                break;
            case 0:
                printf("\nEncerrando...");
                break;
            default:
                printf("\nOpcao invalida!");
        }

    } while(opcao != 0);

    return 0;
}