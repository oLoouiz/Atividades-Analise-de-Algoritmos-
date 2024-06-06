def lcs_recursive(X, Y, m, n):
    if m == 0 or n == 0:
        return 0
    elif X[m-1] == Y[n-1]:
        return 1 + lcs_recursive(X, Y, m-1, n-1)
    else:
        return max(lcs_recursive(X, Y, m, n-1), lcs_recursive(X, Y, m-1, n))

# Exemplo de uso
X = "AGGTAB"
Y = "GXTXAYB"
m = len(X)
n = len(Y)
print(lcs_recursive(X, Y, m, n))
