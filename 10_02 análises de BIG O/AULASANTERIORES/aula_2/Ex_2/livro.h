#ifndef LIVRO_H
#define LIVRO_H

#define MAX_LIVROS 100

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int emprestado;
} Livro;

void cadastrarLivro(Livro livros[], int *total);

#endif
