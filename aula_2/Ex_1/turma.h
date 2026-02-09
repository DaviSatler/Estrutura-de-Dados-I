#ifndef TURMA_H
#define TURMA_H

#include "aluno.h"

#define MAX_ALUNOS 30

typedef struct {
    int codigo;
    char nome[50];
    int qtdAlunos;
    Aluno alunos[MAX_ALUNOS];
} Turma;

void cadastrarTurma(Turma *t);
void adicionarAlunoTurma(Turma *t);
void listarAlunosTurma(Turma *t);

#endif
