#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os itens
typedef struct {
    int peso;
    int valor;
} Item;

// Função para comparar dois itens com base na razão valor/peso
int comparar(const void *a, const void *b) {
    double r1 = (double)((Item*)a)->valor / ((Item*)a)->peso;
    double r2 = (double)((Item*)b)->valor / ((Item*)b)->peso;
    return (r2 > r1) - (r2 < r1); // Ordenação decrescente
}

// Função para resolver o problema da mochila fracionária usando a estratégia gulosa
double mochilaFracionaria(Item itens[], int n, int capacidade) {
    // Ordena os itens com base na razão valor/peso
    qsort(itens, n, sizeof(Item), comparar);

    int peso_atual = 0; // Peso atual da mochila
    double valor_total = 0.0; // Valor total acumulado

    for (int i = 0; i < n; i++) {
        // Se adicionar o item inteiro não ultrapassa a capacidade, adiciona o item inteiro
        if (peso_atual + itens[i].peso <= capacidade) {
            peso_atual += itens[i].peso;
            valor_total += itens[i].valor;
        } else {
            // Caso contrário, adiciona a fração do item que cabe na mochila
            int peso_restante = capacidade - peso_atual;
            valor_total += itens[i].valor * ((double)peso_restante / itens[i].peso);
            break; // A mochila está cheia
        }
    }

    return valor_total;
}

int main() {
    int capacidade = 50; // Capacidade da mochila
    Item itens[] = {{10, 60}, {20, 100}, {30, 120}}; // Itens (peso, valor)
    int n = sizeof(itens) / sizeof(itens[0]);

    double valor_maximo = mochilaFracionaria(itens, n, capacidade);
    printf("Valor máximo na mochila = %.2f\n", valor_maximo);

    return 0;
}
