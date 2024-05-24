#include <stdio.h>
#define N 8

// Função para verificar se é seguro colocar uma rainha em uma determinada posição
int seguro(int tabuleiro[N][N], int linha, int coluna) {
    // Verifica se há uma rainha na mesma coluna
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i][coluna])
            return 0;
    }
    // Verifica a diagonal superior esquerda
    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j])
            return 0;
    }
    // Verifica a diagonal superior direita
    for (int i = linha, j = coluna; i >= 0 && j < N; i--, j++) {
        if (tabuleiro[i][j])
            return 0;
    }
    return 1;
}

// Função recursiva para resolver o Problema das 8 Rainhas
int resolver8Rainhas(int tabuleiro[N][N], int linha) {
    if (linha >= N) // Todas as rainhas foram colocadas
        return 1;
    // Tenta colocar uma rainha em cada coluna na linha atual
    for (int i = 0; i < N; i++) {
        if (seguro(tabuleiro, linha, i)) {
            tabuleiro[linha][i] = 1; // Coloca a rainha na posição atual
            if (resolver8Rainhas(tabuleiro, linha + 1)) // Chama recursivamente para a próxima linha
                return 1;
            tabuleiro[linha][i] = 0; // Se não for possível, desfaz a atribuição
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
    int tabuleiro[N][N] = {0}; // Inicializa o tabuleiro com 0 (sem rainhas)
    if (resolver8Rainhas(tabuleiro, 0)) { // Se houver solução, imprime o tabuleiro
        printf("Solucao do Problema das 8 Rainhas:\n");
        imprimirTabuleiro(tabuleiro);
    } else {
        printf("Nao ha solucao para o Problema das 8 Rainhas.\n");
    }
    return 0;
}
