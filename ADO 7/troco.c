#include <stdio.h>
#include <limits.h>

// Define o número de tipos de moedas disponíveis
#define NUM_MOEDAS 6

// Define os valores de cada tipo de moeda
int valores_moedas[NUM_MOEDAS] = {100, 50, 25, 10, 5, 1};

// Variáveis globais para armazenar a melhor solução encontrada
int melhor_solucao[NUM_MOEDAS];
int menor_quantidade_moedas = INT_MAX;

// Função recursiva para resolver o problema do troco utilizando backtracking
void troco_backtracking(int troco, int index, int solucao_atual[NUM_MOEDAS], int quantidade_moedas_atual) {
    // Se o troco for zero, verificamos se a solução atual é a melhor encontrada até agora
    if (troco == 0) {
        if (quantidade_moedas_atual < menor_quantidade_moedas) {
            menor_quantidade_moedas = quantidade_moedas_atual;
            for (int i = 0; i < NUM_MOEDAS; i++) {
                melhor_solucao[i] = solucao_atual[i];
            }
        }
        return;
    }

    // Se não houver mais tipos de moedas para considerar ou se a quantidade atual de moedas já for maior ou igual à menor encontrada, retorna
    if (index >= NUM_MOEDAS || quantidade_moedas_atual >= menor_quantidade_moedas) {
        return;
    }

    // Loop para tentar usar diferentes quantidades da moeda atual
    for (int i = 0; i <= troco / valores_moedas[index]; i++) {
        solucao_atual[index] = i;
        troco_backtracking(troco - i * valores_moedas[index], index + 1, solucao_atual, quantidade_moedas_atual + i);
    }

    // Reseta a quantidade de moedas atual para o próximo ciclo de backtracking
    solucao_atual[index] = 0;
}

void resolverTroco(int troco) {
    int solucao_atual[NUM_MOEDAS] = {0};

    troco_backtracking(troco, 0, solucao_atual, 0);

    if (menor_quantidade_moedas == INT_MAX) {
        printf("Nao ha solucao para o troco.\n");
    } else {
        printf("Melhor solucao para o troco de %d centavos:\n", troco);
        for (int i = 0; i < NUM_MOEDAS; i++) {
            if (melhor_solucao[i] > 0) {
                printf("%d moedas de %d centavos\n", melhor_solucao[i], valores_moedas[i]);
            }
        }
    }
}

int main() {
    int troco;
    printf("Digite o valor do troco: ");
    scanf("%d", &troco);
    resolverTroco(troco);
    return 0;
}
