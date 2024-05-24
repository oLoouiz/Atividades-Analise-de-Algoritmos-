#include <stdio.h>

int buscaBinaria(int arr[], int inicio, int fim, int chave) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;
        if (arr[meio] == chave)
            return meio;
        if (arr[meio] > chave)
            return buscaBinaria(arr, inicio, meio - 1, chave);
        return buscaBinaria(arr, meio + 1, fim, chave);
    }
    return -1;
}

int main() {
    // POSIÇÕES:{0, 1, 2, 3,  4}
    int arr[] = {2, 3, 4, 10, 40};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int chave = 3;
    int resultado = buscaBinaria(arr, 0, tamanho - 1, chave);
    (resultado == -1) ? printf("Elemento não encontrado")
                      : printf("Elemento encontrado na posição %d", resultado);
    return 0;
}
