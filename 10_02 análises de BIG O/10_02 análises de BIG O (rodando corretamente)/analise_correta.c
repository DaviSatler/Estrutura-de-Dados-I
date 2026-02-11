

int buscaBinaria(int v[], int n, int x)
{
    int ini = 0, fim = n - 1;

    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        if (v[meio] == x)
            return meio;
        else if (v[meio] < x)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}//O(log n) Logarítimica- Tempo logarítmico, pois a cada interação o algoritmo reduz pela metade o número de elementos a serem verificados.






int contarDivisoes(int n)
{
    int cont = 0;
    while (n > 1)
    {
        n = n / 2;
        cont++;
    }
    return cont;
}
//O(log n) Logarítmica - número de div proporcional ao logaritmo de n, pois a cada divisão por 2, o valor de n é reduzido pela metade.






void atribuirValor(int *x)
{
    *x = 10;
}
//O(1) Constante - Sempre executa em tempo constante, independentemente do valor de x.

int maiorValor(int v[], int n)
{
    int maior = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maior)
            maior = v[i];
    }
    return maior;
}
//O(n) Linear - Tempo linear, pois percorre todo o vetor para encontrar o maior valor


void imprimirVetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
//O(n) Linear - Tempo linear, pois percorre todo o vetor para imprimir seus elementos

void mergeSort(int v[], int ini, int fim)
{
    if (ini < fim)
    {
        int meio = (ini + fim) / 2;
        mergeSort(v, ini, meio);
        mergeSort(v, meio + 1, fim);
        // ...
    }
}
//O(n log n) Quase Linear- Tempo de execução do Merge Sort, que é um algoritmo de ordenação eficiente. O tempo de execução é O(n log n) porque o algoritmo divide o vetor em duas metades (log n) e depois combina as metades ordenadas (n).

int primeiroElemento(int v[])
{
    return v[0];
}
//O(1) Constante - Tempo constante, pois sempre acessa o primeiro elemento do vetor, independentemente do tamanho do vetor.

void ordenar(int v[], int n)
{
    for (int passo = n; passo > 1; passo /= 2)
    {
        for (int i = 0; i < passo; i++)
        {
            
        }
    }
}
//O(n log n) Quase Linear- Tempo de execução do algoritmo de ordenação.

void imprimirMatriz(int m[][3], int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", m[i][j]);
        }
    }
}
//O(n) Linear - Tempo linear, pois percorre todas as linhas da matriz para imprimir seus elementos.

void bubbleSort(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}
//O(n^2) Quadrático - Tempo quadrático, com dois laços aninhados, cada um percorrendo o vetor, resultando em n * n = n^2 operações.

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
//O(2^n) Exponencial - Tempo exponencial, pois a cada chamada recursiva, o número de chamadas cresce exponencialmente, resultando em 2^n chamadas

void gerarSubconjuntos(int n)
{
    if (n == 0)
        return;
    gerarSubconjuntos(n - 1);
    gerarSubconjuntos(n - 1);
}
//O(2^n) Exponencial - Tempo exponencial




