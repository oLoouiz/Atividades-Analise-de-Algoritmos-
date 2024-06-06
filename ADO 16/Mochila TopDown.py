def knapsack_top_down(weights, values, capacity, n, memo):
    # Caso base: se não há itens ou a capacidade é zero
    if n == 0 or capacity == 0:
        return 0

    # Se já foi calculado, retorna o valor memoizado
    if memo[n][capacity] != -1:
        return memo[n][capacity]

    # Se o peso do item n-ésimo é mais do que a capacidade, ele não pode ser incluído na solução
    if weights[n-1] > capacity:
        memo[n][capacity] = knapsack_top_down(weights, values, capacity, n-1, memo)
    else:
        # Armazena e retorna o máximo de dois casos:
        # 1. n-ésimo item não incluído
        # 2. n-ésimo item incluído
        memo[n][capacity] = max(values[n-1] + knapsack_top_down(weights, values, capacity - weights[n-1], n-1, memo),
                                knapsack_top_down(weights, values, capacity, n-1, memo))

    return memo[n][capacity]

# Exemplo de uso
weights = [1, 2, 3, 4]
values = [10, 20, 30, 40]
capacity = 5
n = len(weights)
memo = [[-1 for _ in range(capacity + 1)] for _ in range(n + 1)]
print(knapsack_top_down(weights, values, capacity, n, memo))
