#include "vetor.h"
#include <stdio.h>

void lerVetor(int *vet, int n) {
  for (int i = 0; i < n; i++) {
    printf("Digite o valor para a posicao %d: ", i);
    scanf("%d", &vet[i]);
  }
}

void imprimirVetor(int *vet, int n) {
  if (n == 0) {
    printf("Vetor vazio\n");
    return;
  }
  printf("[ ");
  for (int i = 0; i < n; i++) {
    printf("%d ", vet[i]);
  }
  printf("]\n");
}

int removerDuplicados(int *vet, int n) {
  if (n <= 1)
    return n;

  int novoN = 0;

  for (int i = 0; i < n; i++) {
    int duplicado = 0;
    // Check if current element already exists in the "kept" part of the array
    for (int j = 0; j < novoN; j++) {
      if (vet[i] == vet[j]) {
        duplicado = 1;
        break;
      }
    }

    // If not a duplicate, add it to the "kept" part
    if (!duplicado) {
      vet[novoN] = vet[i];
      novoN++;
    }
  }

  return novoN;
}
//comentário de melhoria do código - A função removerDuplicados tem complexidade O(n^2) devido ao uso de dois loops aninhados. 
// Para melhorar a eficiência, pode usar uma estrutura de dados como um conjunto (set).