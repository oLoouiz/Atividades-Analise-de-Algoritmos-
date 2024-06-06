def lcs_top_down(X, Y, m, n, memo):
    if m == 0 or n == 0:
        return 0
    if memo[m][n] != -1:
        return memo[m][n]
    if X[m-1] == Y[n-1]:
        memo[m][n] = 1 + lcs_top_down(X, Y, m-1, n-1, memo)
    else:
        memo[m][n] = max(lcs_top_down(X, Y, m, n-1, memo), lcs_top_down(X, Y, m-1, n, memo))
    return memo[m][n]

# Exemplo de uso
X = "AGGTAB"
Y = "GXTXAYB"
m = len(X)
n = len(Y)
memo = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]
print(lcs_top_down(X, Y, m, n, memo))
