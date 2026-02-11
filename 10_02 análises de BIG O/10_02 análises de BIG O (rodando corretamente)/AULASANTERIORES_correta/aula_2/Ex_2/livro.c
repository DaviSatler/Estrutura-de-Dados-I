#include <stdio.h>
#include <string.h>
#include "livro.h"

void cadastrarLivro(Livro livros[], int *total) {
    if (*total >= MAX_LIVROS) {
        printf("Limite de livros atingido!\n");
        return;
    }

    Livro *l = &livros[*total];

    printf("Codigo: ");
    scanf("%d", &l->codigo);
    getchar();

    printf("Titulo: ");
    fgets(l->titulo, 100, stdin);
    l->titulo[strcspn(l->titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(l->autor, 100, stdin);
    l->autor[strcspn(l->autor, "\n")] = 0;

    l->emprestado = 0;

    (*total)++;
    printf("Livro cadastrado!\n");
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente do número de cadastrados.
