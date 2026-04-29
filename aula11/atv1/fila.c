#include "fila.h"

Fila *cria_fila()
{
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void insere_elemento(Fila *fi)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    printf("\nDigite o numero a ser inserido na fila: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;

    if (fi->inicio == NULL)
    {
        fi->inicio = novo;
        fi->fim = novo;
    }
    else
    {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    printf("\nNumero inserido na fila!\n");
}

void consulta_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("\nFila Vazia!!\n");
    }
    else
    {
        Elemento *aux = fi->inicio;
        do
        {
            printf("\n %d ", aux->num);
            aux = aux->prox;
        } while (aux != NULL);
        printf("\n");
    }
}

void remove_elemento_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("\nFila Vazia!!\n");
    }
    else
    {
        Elemento *aux = fi->inicio;
        printf("\n%d removido!\n", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
}