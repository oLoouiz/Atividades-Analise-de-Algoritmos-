#include <stdio.h>
#define N 8

// Função para verificar se uma determinada posição é válida no tabuleiro
int posicaoValida(int x, int y, int tabuleiro[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && tabuleiro[x][y] == -1);
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para resolver o problema do percurso do cavalo
int resolverCavalo(int x, int y, int movimento, int tabuleiro[N][N], int movX[], int movY[]) {
    int proxX, proxY;
    if (movimento == N * N)
        return 1;
    for (int i = 0; i < 8; i++) {
        proxX = x + movX[i];
        proxY = y + movY[i];
        if (posicaoValida(proxX, proxY, tabuleiro)) {
            tabuleiro[proxX][proxY] = movimento;
            if (resolverCavalo(proxX, proxY, movimento + 1, tabuleiro, movX, movY))
                return 1;
            else
                tabuleiro[proxX][proxY] = -1; // Backtrack
        }
    }
    return 0;
}

// Função para resolver o problema do percurso do cavalo no tabuleiro de xadrez
void percursoCavalo() {
    int tabuleiro[N][N];
    // Inicializa o tabuleiro com -1 (nenhuma casa visitada)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = -1;

    // Define os movimentos possíveis do cavalo
    int movX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int movY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Define a posição inicial do cavalo
    int inicioX = 0, inicioY = 0;

    // Marca a posição inicial do cavalo como visitada
    tabuleiro[inicioX][inicioY] = 0;

    // Chama a função recursiva para resolver o problema
    if (resolverCavalo(inicioX, inicioY, 1, tabuleiro, movX, movY)) {
        printf("Solucao do percurso do cavalo:\n");
        imprimirTabuleiro(tabuleiro);
    } else {
        printf("Nao ha solucao para o percurso do cavalo.\n");
    }
}

int main() {
    percursoCavalo();
    return 0;
}
