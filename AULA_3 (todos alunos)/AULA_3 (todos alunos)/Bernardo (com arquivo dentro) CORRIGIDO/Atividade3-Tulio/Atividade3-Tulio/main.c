#include "vetor.h"
#include <stdio.h>

#define MAX_SIZE 100

int main() {
  int n;
  int vet[MAX_SIZE];

  printf("Digite a quantidade de elementos (max %d): ", MAX_SIZE);
  scanf("%d", &n);

  if (n > MAX_SIZE || n <= 0) {
    printf("Quantidade invalida!\n");
    return 1;
  }

  lerVetor(vet, n);

  printf("\nVetor Original:\n");
  imprimirVetor(vet, n);

  int novoN = removerDuplicados(vet, n);

  printf("\nVetor Apos Remocao e Compactacao:\n");
  imprimirVetor(vet, novoN);
  printf("Novo tamanho: %d\n", novoN);

  return 0;
}

//Comentário de melhoria do código - O código não verifica se a quantidade de elementos é válida (n > 0 e n <= MAX_SIZE).