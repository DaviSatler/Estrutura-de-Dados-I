#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

/* Estrutura do container */
typedef struct Container {
    char nome[TAM];
    int id;
    char destino[TAM];
    struct Container *prox;
} Container;

/* Estrutura da pilha */
typedef struct {
    Container *topo;
} Pilha;

/* Criar pilha */
Pilha* cria_pilha() {
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi->topo = NULL;
    }
    return pi;
}

/* Inserir container (empilhar) */
void inserir_container(Pilha *pi) {
    Container *novo = (Container*) malloc(sizeof(Container));

    if (novo == NULL) {
        printf("\nErro de alocação!");
        return;
    }

    printf("\nNome do container: ");
    getchar();
    fgets(novo->nome, TAM, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("ID do container: ");
    scanf("%d", &novo->id);

    printf("Destino: ");
    getchar();
    fgets(novo->destino, TAM, stdin);
    novo->destino[strcspn(novo->destino, "\n")] = '\0';

    novo->prox = pi->topo;
    pi->topo = novo;

    printf("\nContainer inserido com sucesso!");
}

/* Remover container (desempilhar) */
void remover_container(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nNenhum container na pilha!");
        return;
    }

    Container *aux = pi->topo;

    printf("\nContainer removido:");
    printf("\nNome: %s", aux->nome);
    printf("\nID: %d", aux->id);
    printf("\nDestino: %s", aux->destino);

    pi->topo = aux->prox;
    free(aux);
}

/* Exibir todos os containers */
void exibir_containers(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nPilha vazia!");
        return;
    }

    Container *aux = pi->topo;

    printf("\n\n--- Containers na pilha ---");

    while (aux != NULL) {
        printf("\nNome: %s", aux->nome);
        printf("\nID: %d", aux->id);
        printf("\nDestino: %s", aux->destino);
        printf("\n--------------------------");
        aux = aux->prox;
    }
}

/* Mostrar próximo container (topo) */
void proximo_container(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("\nPilha vazia!");
        return;
    }

    Container *aux = pi->topo;

    printf("\n\nPróximo container a ser removido:");
    printf("\nNome: %s", aux->nome);
    printf("\nID: %d", aux->id);
    printf("\nDestino: %s", aux->destino);
}

/* Liberar memória */
void liberar_pilha(Pilha *pi) {
    Container *aux;

    while (pi->topo != NULL) {
        aux = pi->topo;
        pi->topo = pi->topo->prox;
        free(aux);
    }

    free(pi);
    printf("\nMemória liberada!");
}

/* Menu principal */
int main() {
    Pilha *pi = cria_pilha();
    int opcao;

    do {
        printf("\n\n===== PORTO - PILHA DE CONTAINERS =====");
        printf("\n1 - Inserir container");
        printf("\n2 - Desembarcar container");
        printf("\n3 - Exibir containers");
        printf("\n4 - Ver proximo container");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserir_container(pi);
                break;
            case 2:
                remover_container(pi);
                break;
            case 3:
                exibir_containers(pi);
                break;
            case 4:
                proximo_container(pi);
                break;
            case 0:
                liberar_pilha(pi);
                printf("\nEncerrando...");
                break;
            default:
                printf("\nOpcao invalida!");
        }

    } while(opcao != 0);

    return 0;
}