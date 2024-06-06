def matrix_chain_bottom_up(p):
    n = len(p) - 1
    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    for l in range(2, n + 1):  # l é o comprimento da cadeia
        for i in range(1, n - l + 2):
            j = i + l - 1
            dp[i][j] = sys.maxsize
            for k in range(i, j):
                cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]
                if cost < dp[i][j]:
                    dp[i][j] = cost

    return dp[1][n]

# Exemplo de uso
p = [1, 2, 3, 4]
print(matrix_chain_bottom_up(p))
