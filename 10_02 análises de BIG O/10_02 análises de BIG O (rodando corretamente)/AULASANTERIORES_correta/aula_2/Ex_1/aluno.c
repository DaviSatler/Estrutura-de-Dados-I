#include <stdio.h>
#include "aluno.h"

void cadastrarAluno(Aluno *a) {
    printf("ID: ");
    scanf("%d", &a->id);

    printf("Nome: ");
    scanf(" %[^\n]", a->nome);

    printf("Nota: ");
    scanf("%f", &a->nota);
}

//O(1) Constante - Tempo constante, pois a função sempre executa em tempo constante, independentemente do número de alunos cadastrados.
