//Atividade 3 – Complexidade O(2ⁿ)  
//Implementar um algoritmo recursivo em C para calcular o n-ésimo termo da sequência de Fibonacci, sem utilizar otimizações (sem vetores auxiliares, sem memoization).


#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main() {
    int n;

    printf("Digite o termo n para calcular o n-ésimo termo da sequência de Fibonacci: ");
    scanf("%d", &n);
    

    int resultado = fibonacci(n);
    printf("O %d-ésimo termo da sequência de Fibonacci é: %d\n", n, resultado);

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

