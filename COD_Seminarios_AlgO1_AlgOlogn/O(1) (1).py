import time

# Criando array 
n = 150_000_000
array = list(range(n))

indice = n - 1  

inicio = time.perf_counter()#incio do timer

valor = array[indice]  #acesso direto

fim = time.perf_counter()#fim do timer

print("Valor encontrado:", valor)
print(f"Tempo: {fim - inicio:.6f} segundos")#tempo de busca

#Apenas 1 passo