#include <stdio.h>
#include "turma.h"

void cadastrarTurma(Turma *t) {
    printf("Codigo da turma: ");
    scanf("%d", &t->codigo);

    printf("Nome da turma: ");
    scanf(" %[^\n]", t->nome);

    t->qtdAlunos = 0;
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante

void adicionarAlunoTurma(Turma *t) {
    if (t->qtdAlunos >= MAX_ALUNOS) {
        printf("Turma cheia!\n");
        return;
    }

    cadastrarAluno(&t->alunos[t->qtdAlunos]);
    t->qtdAlunos++;
}
//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante

void listarAlunosTurma(Turma *t) {
    printf("\nTurma: %s\n", t->nome);

    for (int i = 0; i < t->qtdAlunos; i++) {
        printf("\nAluno %d", i + 1);
        printf("\nID: %d", t->alunos[i].id);
        printf("\nNome: %s", t->alunos[i].nome);
        printf("\nNota: %.2f\n", t->alunos[i].nota);
    }
}
//O(n) Linear - Tempo linear, pois a função percorre todos os alunos cadastrados na turma para listá-los.
