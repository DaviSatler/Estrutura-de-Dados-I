#include "fila_banco.h"

Fila *cria_fila()
{
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->total_clientes = 0;
    }
    return fi;
}

void insere_cliente(Fila *fi, int id, int tempo)
{
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    novo->id = id;
    novo->tempo_atendimento = tempo;
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
    fi->total_clientes++;
    printf("Cliente %d inserido com tempo %d min\n", id, tempo);
}

void atende_cliente(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }
    Cliente *aux = fi->inicio;
    printf("Atendendo cliente %d...\n", aux->id);
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL)
        fi->fim = NULL;
    fi->total_clientes--;
    free(aux);
}

void consulta_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }
    Cliente *aux = fi->inicio;
    while (aux != NULL)
    {
        printf("Cliente %d - tempo: %d min\n", aux->id, aux->tempo_atendimento);
        aux = aux->prox;
    }
}

int calcula_tempo_espera(Fila *fi)
{
    int total = 0;
    Cliente *aux = fi->inicio;
    while (aux != NULL)
    {
        total += aux->tempo_atendimento;
        aux = aux->prox;
    }
    return total;
}

void libera_fila(Fila *fi)
{
    Cliente *aux = fi->inicio;
    while (aux != NULL)
    {
        Cliente *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(fi);
}