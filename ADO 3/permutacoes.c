#include <stdio.h>

// Função para trocar dois elementos de posição em um array
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Função recursiva para gerar todas as permutações
void permutacoes(char *sequencia, int inicio, int tamanho) {
    if (inicio == tamanho - 1) {
        printf("%s\n", sequencia); // Imprime a permutação atual
    } else {
        for (int i = inicio; i < tamanho; i++) {
            trocar(&sequencia[inicio], &sequencia[i]); // Troca os elementos
            permutacoes(sequencia, inicio + 1, tamanho); // Chamada recursiva para o próximo elemento
            trocar(&sequencia[inicio], &sequencia[i]); // Desfaz a troca para voltar ao estado original
        }
    }
}

int main() {
    char sequencia[] = "123456";
    int tamanho = sizeof(sequencia) - 1; // Tamanho da sequência excluindo o caractere nulo
    printf("Permutações da sequência '%s':\n", sequencia);
    permutacoes(sequencia, 0, tamanho); // Chama a função para gerar as permutações
    return 0;
}
