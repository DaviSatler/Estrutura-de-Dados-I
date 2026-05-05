#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

// Criar fila
Fila* criarFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Verificar se está vazia
int estaVazia(Fila* f) {
    return (f->inicio == NULL);
}

// Inserir (enqueue)
void enqueue(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (estaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
}

// Remover (dequeue)
int dequeue(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    No* temp = f->inicio;
    int valor = temp->valor;

    f->inicio = temp->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    return valor;
}

// Exibir elementos
void exibirFila(Fila* f) {
    No* atual = f->inicio;

    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Contar elementos
int contarElementos(Fila* f) {
    int count = 0;
    No* atual = f->inicio;

    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    return count;
}

// Consultar primeiro elemento
int primeiroElemento(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    return f->inicio->valor;
}

// Programa principal para teste
int main() {
    Fila* fila = criarFila();

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);

    exibirFila(fila);

    printf("Quantidade: %d\n", contarElementos(fila));

    printf("Primeiro elemento: %d\n", primeiroElemento(fila));

    printf("Removido: %d\n", dequeue(fila));

    exibirFila(fila);

    return 0;
}