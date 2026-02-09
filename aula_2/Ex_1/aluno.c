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
