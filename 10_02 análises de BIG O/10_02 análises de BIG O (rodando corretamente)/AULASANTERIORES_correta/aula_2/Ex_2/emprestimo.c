#include <stdio.h>
#include <string.h>
#include "emprestimo.h"

void registrarEmprestimo(
    Emprestimo emprestimos[], int *totalEmp,
    Usuario usuarios[], int totalUsu,
    Livro livros[], int totalLiv
) {
    if (*totalEmp >= MAX_EMPRESTIMOS) {
        printf("Limite de emprestimos atingido!\n");
        return;
    }
    

    int idU, codL;
    printf("ID do usuario: ");
    scanf("%d", &idU);

    printf("Codigo do livro: ");
    scanf("%d", &codL);
    getchar();

    int uIndex = -1, lIndex = -1;

    for (int i = 0; i < totalUsu; i++)
        if (usuarios[i].id == idU) uIndex = i;

    for (int i = 0; i < totalLiv; i++)
        if (livros[i].codigo == codL) lIndex = i;

    if (uIndex == -1 || lIndex == -1 || livros[lIndex].emprestado) {
        printf("Usuario/Livro invalido ou livro indisponivel!\n");
        return;
    }

    Emprestimo *e = &emprestimos[*totalEmp];

    e->idUsuario = idU;
    e->codigoLivro = codL;

    printf("Data do emprestimo: ");
    fgets(e->data, 20, stdin);
    e->data[strcspn(e->data, "\n")] = 0;

    livros[lIndex].emprestado = 1;

    (*totalEmp)++;
    printf("Emprestimo registrado!\n");
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente do número de usuários ou livros cadastrados.

void listarEmprestimosUsuario(
    Emprestimo emprestimos[], int totalEmp,
    Usuario usuarios[], int totalUsu,
    Livro livros[], int totalLiv
) {
    int idU;
    printf("ID do usuario: ");
    scanf("%d", &idU);

    printf("\nLivros emprestados:\n");

    for (int i = 0; i < totalEmp; i++) {
        if (emprestimos[i].idUsuario == idU) {
            for (int j = 0; j < totalLiv; j++) {
                if (livros[j].codigo == emprestimos[i].codigoLivro) {
                    printf("Titulo: %s | Data: %s\n",
                           livros[j].titulo,
                           emprestimos[i].data);
                }
            }
        }
    }
}
//O(n^2) Quadrático - Tempo quadrático, pois a função possui dois laços aninhados.