#include <stdio.h>

// Função para encontrar o k-ésimo menor elemento em um array usando a técnica de mediana das medianas
int kthSmallest(int arr[], int inicio, int fim, int k);

// Função para encontrar a mediana de um array
int encontrarMediana(int arr[], int n);

// Função auxiliar para trocar dois elementos de posição em um array
void trocar(int *a, int *b);

// Função auxiliar para encontrar a posição correta do pivô no array
int particionar(int arr[], int inicio, int fim);

// Função principal para encontrar o k-ésimo menor elemento em um array
int kthSmallest(int arr[], int inicio, int fim, int k) {
    // Se k estiver fora do intervalo do array, retorne -1
    if (k < 0 || k > fim - inicio + 1)
        return -1;

    // Encontre o pivô usando a mediana das medianas
    int mediana = encontrarMediana(arr + inicio, fim - inicio + 1);

    // Coloque o pivô na posição correta no array
    int posicaoPivo = particionar(arr, inicio, fim);
    
    // Se o pivô está na posição k-1, retorne o pivô
    if (posicaoPivo - inicio == k - 1)
        return arr[posicaoPivo];

    // Se a posição do pivô é maior que k-1, busque no lado esquerdo do array
    if (posicaoPivo - inicio > k - 1)
        return kthSmallest(arr, inicio, posicaoPivo - 1, k);

    // Caso contrário, busque no lado direito do array
    return kthSmallest(arr, posicaoPivo + 1, fim, k - posicaoPivo + inicio - 1);
}

// Função para encontrar a mediana de um array
int encontrarMediana(int arr[], int n) {
    // Ordenar o array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
    // Retorna a mediana
    return arr[n / 2];
}

// Função auxiliar para trocar dois elementos de posição em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função auxiliar para encontrar a posição correta do pivô no array
int particionar(int arr[], int inicio, int fim) {
    int pivô = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (arr[j] <= pivô) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printf("O %d-ésimo menor elemento é %d", k, kthSmallest(arr, 0, n - 1, k));
    return 0;
}
