#include <stdio.h>
#include <stdlib.h>

// Nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Fila
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

// Verificar se vazia
int estaVazia(Fila* f) {
    return (f->inicio == NULL);
}

// =============================
// 🔹 ENQUEUE NORMAL (apoio)
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

// 🔹 DEQUEUE
int dequeue(Fila* f) {
    if (estaVazia(f)) return -1;

    No* temp = f->inicio;
    int valor = temp->valor;

    f->inicio = temp->prox;
    if (f->inicio == NULL) f->fim = NULL;

    free(temp);
    return valor;
}

// =============================
// 1️⃣ FILA COM PRIORIDADE (crescente)
void enqueuePrioridade(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    // inserir no início
    if (estaVazia(f) || valor < f->inicio->valor) {
        novo->prox = f->inicio;
        f->inicio = novo;
        if (f->fim == NULL) f->fim = novo;
        return;
    }

    // percorrer para achar posição
    No* atual = f->inicio;
    while (atual->prox != NULL && atual->prox->valor <= valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    if (novo->prox == NULL) {
        f->fim = novo;
    }
}

// =============================
// 2️⃣ INVERTER FILA (usando apenas filas)
Fila* inverterFila(Fila* f) {
    Fila* temp = criarFila();
    Fila* invertida = criarFila();

    // Copia tudo para temp
    while (!estaVazia(f)) {
        enqueue(temp, dequeue(f));
    }

    // Reorganiza invertendo
    while (!estaVazia(temp)) {
        int tamanho = 0;
        Fila* aux = criarFila();

        // conta e move
        while (!estaVazia(temp)) {
            enqueue(aux, dequeue(temp));
            tamanho++;
        }

        // pega último elemento
        for (int i = 0; i < tamanho - 1; i++) {
            enqueue(temp, dequeue(aux));
        }

        enqueue(invertida, dequeue(aux));

        // devolve o resto
        while (!estaVazia(aux)) {
            enqueue(temp, dequeue(aux));
        }

        free(aux);
    }

    return invertida;
}

// =============================
// 3️⃣ COPIAR FILA
Fila* copiarFila(Fila* f) {
    Fila* copia = criarFila();
    Fila* aux = criarFila();

    // copiar mantendo ordem
    while (!estaVazia(f)) {
        int val = dequeue(f);
        enqueue(copia, val);
        enqueue(aux, val);
    }

    // restaurar original
    while (!estaVazia(aux)) {
        enqueue(f, dequeue(aux));
    }

    return copia;
}

// =============================
// 4️⃣ CONCATENAR FILAS
Fila* concatenarFilas(Fila* f1, Fila* f2) {
    Fila* nova = criarFila();

    No* atual = f1->inicio;
    while (atual != NULL) {
        enqueue(nova, atual->valor);
        atual = atual->prox;
    }

    atual = f2->inicio;
    while (atual != NULL) {
        enqueue(nova, atual->valor);
        atual = atual->prox;
    }

    return nova;
}

// =============================
// EXIBIR
void exibirFila(Fila* f) {
    No* atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// =============================
// MAIN TESTE
int main() {
    Fila* f = criarFila();

    // prioridade
    enqueuePrioridade(f, 30);
    enqueuePrioridade(f, 10);
    enqueuePrioridade(f, 20);

    printf("Fila com prioridade:\n");
    exibirFila(f);

    // copiar
    Fila* copia = copiarFila(f);
    printf("Copia:\n");
    exibirFila(copia);

    // inverter
    Fila* invertida = inverterFila(copia);
    printf("Invertida:\n");
    exibirFila(invertida);

    // concatenar
    Fila* f2 = criarFila();
    enqueue(f2, 100);
    enqueue(f2, 200);

    Fila* concat = concatenarFilas(f, f2);
    printf("Concatenada:\n");
    exibirFila(concat);

    return 0;
}