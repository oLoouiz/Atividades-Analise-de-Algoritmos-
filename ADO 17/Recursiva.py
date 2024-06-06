import sys

def matrix_chain_recursive(p, i, j):
    if i == j:
        return 0
    min_cost = sys.maxsize
    for k in range(i, j):
        cost = (matrix_chain_recursive(p, i, k)
                + matrix_chain_recursive(p, k + 1, j)
                + p[i-1] * p[k] * p[j])
        if cost < min_cost:
            min_cost = cost
    return min_cost

# Exemplo de uso
p = [1, 2, 3, 4]
n = len(p) - 1
print(matrix_chain_recursive(p, 1, n))
