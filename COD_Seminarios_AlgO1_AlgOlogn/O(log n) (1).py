import time
import timeit
def busca_binaria(arr, alvo): #busca binária
    inicio = 0
    fim = len(arr) - 1

    while inicio <= fim:
        meio = (inicio + fim) // 2

        if arr[meio] == alvo:
            return meio
        elif arr[meio] < alvo:
            inicio = meio + 1
        else:
            fim = meio - 1

    return -1


# Criando array
n = 150_000_000
array = list(range(n))

alvo = n - 1  

inicio = time.perf_counter() #Início da medição de tempo

posicao = busca_binaria(array, alvo)

fim = time.perf_counter()#fim da medição de tempo

print("Posição encontrada:", posicao)
print(f"Tempo O(log n): {fim - inicio:.6f} segundos")#tempo de busca

#27 passos