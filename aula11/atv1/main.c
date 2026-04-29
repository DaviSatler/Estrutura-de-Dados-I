#include "fila.h"

int main()
{
    Fila *fi = cria_fila();

    insere_elemento(fi);
    insere_elemento(fi);
    insere_elemento(fi);
    remove_elemento_fila(fi);
    consulta_fila(fi);

    return 0;
}