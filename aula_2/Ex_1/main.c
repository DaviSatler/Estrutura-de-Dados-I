#include <stdio.h>
#include "turma.h"

#define MAX_TURMAS 5

int main() {

    Turma turmas[MAX_TURMAS];
    int qtdTurmas = 0;
    int op;

    do {
        printf("\n1 - Cadastrar turma");
        printf("\n2 - Adicionar aluno");
        printf("\n3 - Listar alunos");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op == 1 && qtdTurmas < MAX_TURMAS) {
            cadastrarTurma(&turmas[qtdTurmas]);
            qtdTurmas++;
        }

        else if (op == 2) {
            int t;
            printf("Qual turma (indice 0-%d)? ", qtdTurmas - 1);
            scanf("%d", &t);

            if (t >= 0 && t < qtdTurmas)
                adicionarAlunoTurma(&turmas[t]);
        }

        else if (op == 3) {
            int t;
            printf("Qual turma? ");
            scanf("%d", &t);

            if (t >= 0 && t < qtdTurmas)
                listarAlunosTurma(&turmas[t]);
        }

    } while (op != 0);

    return 0;
}
