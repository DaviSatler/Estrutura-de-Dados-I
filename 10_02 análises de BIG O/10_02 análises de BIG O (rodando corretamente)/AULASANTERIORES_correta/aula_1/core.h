#ifndef CORE_H
#define CORE_H

int cadastrar(void *caixa, int tamanho, char *arquivo);
void exibir(char *arquivo, int tamanho, void (*imprimir)(void*));
//O(n) Linear - Tempo linear, pois a função percorre todo o arquivo para listar os dados.
#endif