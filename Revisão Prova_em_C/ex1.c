#include <stdio.h>
#include <stdlib.h>

int N, M;
int *vetor;

int main(){

printf("Informe um valor a um número N:");
scanf("%d", &N);


vetor= (int*) malloc(N * sizeof(int));

printf("Digite o novo tamanho: ");
scanf("%d", &M);

vetor = (int*) realloc(vetor, M * sizeof(int));

for(int i = 0; i < M; i++) {
    printf("Digite o valor %d: ", i);
    scanf("%d", &vetor[i]);
}

printf("Valores:\n");

for(int i = 0; i < M; i++) {
    printf("%d ", vetor[i]);
}

free(vetor);



}