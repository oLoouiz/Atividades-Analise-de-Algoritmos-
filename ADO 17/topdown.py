import sys

def matrix_chain_top_down(p, i, j, memo):
    if i == j:
        return 0
    if memo[i][j] != -1:
        return memo[i][j]
    min_cost = sys.maxsize
    for k in range(i, j):
        cost = (matrix_chain_top_down(p, i, k, memo)
                + matrix_chain_top_down(p, k + 1, j, memo)
                + p[i-1] * p[k] * p[j])
        if cost < min_cost:
            min_cost = cost
    memo[i][j] = min_cost
    return memo[i][j]

# Exemplo de uso
p = [1, 2, 3, 4]
n = len(p) - 1
memo = [[-1 for _ in range(n + 1)] for _ in range(n + 1)]
print(matrix_chain_top_down(p, 1, n, memo))
