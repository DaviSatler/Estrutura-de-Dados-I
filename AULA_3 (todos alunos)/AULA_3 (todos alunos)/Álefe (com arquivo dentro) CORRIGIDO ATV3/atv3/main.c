#include <stdio.h>
/* Ele está classificado em O(n²) */

int main() {
    int v[50];
    int n, i, j, k;

    printf("Quantidade de elementos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i);
        scanf("%d", &v[i]);
    }

   
    printf("\nVetor original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] == v[j]) {
                for (k = j; k < n - 1; k++) {
                    v[k] = v[k + 1];
                }
                n--;   
                j--;   
            }
        }
    }

    printf("\n\nVetor apos remover repetidos:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}


//comentário de melhoria do código: Pode-se usar uma estrutura de dados como um conjunto (set) para evitar repetições.
// O código não verifica se o número de elementos é válido (n > 0 e n <= 50).
