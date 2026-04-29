#include "fila_banco.h"

int main()
{
    Fila *fi = cria_fila();
    int opcao = -1;
    int proximo_id = 1;

    insere_cliente(fi, proximo_id++, 5);
    insere_cliente(fi, proximo_id++, 3);
    insere_cliente(fi, proximo_id++, 8);

    while (opcao != 0)
    {
        printf("\n1. Inserir cliente\n");
        printf("2. Atender proximo cliente\n");
        printf("3. Exibir fila\n");
        printf("4. Tempo total de espera\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            int tempo;
            printf("Tempo de atendimento (min): ");
            scanf("%d", &tempo);
            insere_cliente(fi, proximo_id++, tempo);
        }
        else if (opcao == 2)
        {
            atende_cliente(fi);
        }
        else if (opcao == 3)
        {
            consulta_fila(fi);
        }
        else if (opcao == 4)
        {
            printf("Tempo total de espera: %d min\n", calcula_tempo_espera(fi));
        }
        else if (opcao != 0)
        {
            printf("Opcao invalida!\n");
        }
    }

    libera_fila(fi);
    return 0;
}