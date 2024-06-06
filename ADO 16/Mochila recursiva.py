def knapsack_recursive(weights, values, capacity, n):
    # Caso base: se não há itens ou a capacidade é zero
    if n == 0 or capacity == 0:
        return 0

    # Se o peso do item n-ésimo é mais do que a capacidade, ele não pode ser incluído na solução
    if weights[n-1] > capacity:
        return knapsack_recursive(weights, values, capacity, n-1)

    # Retorna o máximo de dois casos:
    # 1. n-ésimo item não incluído
    # 2. n-ésimo item incluído
    else:
        return max(values[n-1] + knapsack_recursive(weights, values, capacity - weights[n-1], n-1),
                   knapsack_recursive(weights, values, capacity, n-1))

# Exemplo de uso
weights = [1, 2, 3, 4]
values = [10, 20, 30, 40]
capacity = 5
n = len(weights)
print(knapsack_recursive(weights, values, capacity, n))
