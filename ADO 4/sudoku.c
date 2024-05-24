#include <stdio.h>
#define N 9

// Função para verificar se é seguro atribuir um número a uma determinada célula
int seguro(int tabuleiro[N][N], int linha, int coluna, int num) {
    // Verifica se o número já está na linha ou coluna
    for (int i = 0; i < N; i++) {
        if (tabuleiro[linha][i] == num || tabuleiro[i][coluna] == num)
            return 0;
    }
    // Verifica se o número já está no bloco 3x3
    int inicio_linha = linha - linha % 3;
    int inicio_coluna = coluna - coluna % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i + inicio_linha][j + inicio_coluna] == num)
                return 0;
        }
    }
    return 1;
}

// Função para resolver o Sudoku usando backtracking
int resolverSudoku(int tabuleiro[N][N]) {
    int linha, coluna;
    // Verifica se há uma célula vazia
    int vazio = 0;
    for (linha = 0; linha < N; linha++) {
        for (coluna = 0; coluna < N; coluna++) {
            if (tabuleiro[linha][coluna] == 0) {
                vazio = 1;
                break;
            }
        }
        if (vazio == 1)
            break;
    }
    if (vazio == 0) // Se não houver célula vazia, o Sudoku está resolvido
        return 1;
    // Tentar atribuir números de 1 a 9
    for (int num = 1; num <= 9; num++) {
        if (seguro(tabuleiro, linha, coluna, num)) {
            tabuleiro[linha][coluna] = num;
            if (resolverSudoku(tabuleiro)) // Chama recursivamente para a próxima célula
                return 1;
            tabuleiro[linha][coluna] = 0; // Se a atribuição não levar a uma solução, desfaz a atribuição
        }
    }
    return 0; // Retorna 0 se não houver solução
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if (resolverSudoku(tabuleiro) == 1) {
        printf("Solução do Sudoku:\n");
        imprimirTabuleiro(tabuleiro);
    } else {
        printf("Não há solução para o Sudoku.\n");
    }
    return 0;
}
