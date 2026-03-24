#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *notas;
    float soma = 0, media;
    float maior, menor;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

   
    notas = (float *) malloc(n * sizeof(float));

    if (notas == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);

        soma += notas[i];

        if (i == 0) {
            maior = menor = notas[i];
        } else {
            if (notas[i] > maior) {
                maior = notas[i];
            }
            if (notas[i] < menor) {
                menor = notas[i];
            }
        }
    }
    media = soma / n;

    printf("\nMedia da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);

    free(notas);

    return 0;
}