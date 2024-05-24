#include <stdio.h>

// Define o número de tipos de moedas disponíveis
#define NUM_MOEDAS 6

// Define os valores de cada tipo de moeda
int valores_moedas[NUM_MOEDAS] = {100, 50, 25, 10, 5, 1};

// Função para calcular o troco utilizando a estratégia gulosa
void troco_guloso(int troco) {
    printf("Troco a ser dado: %d\n", troco);
    printf("Moedas a serem utilizadas:\n");

    // Loop através de cada tipo de moeda
    for (int i = 0; i < NUM_MOEDAS; i++) {
        // Determina a quantidade de moedas de cada tipo que podem ser utilizadas
        int qtd_moedas = troco / valores_moedas[i];
        if (qtd_moedas > 0) {
            printf("%d moedas de %d centavos\n", qtd_moedas, valores_moedas[i]);
            // Reduz o troco restante subtraindo o valor das moedas utilizadas
            troco -= qtd_moedas * valores_moedas[i];
        }
    }
}

int main() {
    int troco;
    printf("Digite o valor do troco: ");
    scanf("%d", &troco);
    troco_guloso(troco);
    return 0;
}
