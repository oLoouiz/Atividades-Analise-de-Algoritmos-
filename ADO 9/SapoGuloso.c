#include <stdio.h>

// Função que implementa a solução gulosa para o problema do salto do sapo
int saltoDoSapo(int pedras[], int n) {
    int saltos = 0;  // Contador de saltos
    int posicao_atual = 0;  // Posição atual do sapo

    while (posicao_atual < n - 1) {
        int max_salto = 0;
        int melhor_posicao = posicao_atual;

        // Verifica todas as posições alcançáveis a partir da posição atual
        for (int i = posicao_atual + 1; i < n && i <= posicao_atual + pedras[posicao_atual]; i++) {
            if (i >= n - 1) {
                melhor_posicao = n - 1;
                break;
            }
            if (i + pedras[i] > melhor_posicao + pedras[melhor_posicao]) {
                melhor_posicao = i;
            }
        }

        // Move para a melhor posição encontrada
        posicao_atual = melhor_posicao;
        saltos++;

        // Se não foi possível avançar, retorna -1 indicando que o sapo não pode alcançar o destino
        if (posicao_atual == melhor_posicao && pedras[posicao_atual] == 0) {
            return -1;
        }
    }

    return saltos;
}

int main() {
    int pedras[] = {3, 2, 5, 1, 1, 2, 1, 4};  // Exemplo de posições e saltos possíveis
    int n = sizeof(pedras) / sizeof(pedras[0]);

    int resultado = saltoDoSapo(pedras, n);

    if (resultado != -1) {
        printf("Número mínimo de saltos: %d\n", resultado);
    } else {
        printf("O sapo não pode alcançar o destino.\n");
    }

    return 0;
}
