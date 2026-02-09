#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "livro.h"
#include "usuario.h"

#define MAX_EMPRESTIMOS 100

typedef struct {
    int idUsuario;
    int codigoLivro;
    char data[20];
} Emprestimo;

void registrarEmprestimo(
    Emprestimo emprestimos[], int *totalEmp,
    Usuario usuarios[], int totalUsu,
    Livro livros[], int totalLiv
);

void listarEmprestimosUsuario(
    Emprestimo emprestimos[], int totalEmp,
    Usuario usuarios[], int totalUsu,
    Livro livros[], int totalLiv
);

#endif
