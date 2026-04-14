#include <stdio.h>
#include <stdlib.h>


int N;
int *vetor;
int soma = 0;

int main(){

printf("Diga uma quantidade N de números:");
scanf("%d", &N);


vetor= (int*) malloc(N * sizeof(int));

if (vetor == NULL){
    printf("Erro de memória\n");
    return 1;
    
}

for(int i= 0; i < N ; i++){
    printf("Digite o valor %d: ", i);
    scanf("%d", &vetor[i]);
    
    soma+= vetor[i];
}

float media = (float)soma / N;

printf("\nSoma: %d\n", soma);
printf("Media: %.2f\n", media);

free(vetor);

}