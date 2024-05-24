#include <stdio.h>
#include <cstdlib>

int mergeSort(int arr[], int temp[], int esq, int dir);
int merge(int arr[], int temp[], int esq, int meio, int dir);

int contagemInversoes(int arr[], int tamanho) {
    int *temp = (int *)malloc(tamanho * sizeof(int)); // Aloca dinamicamente a memória para temp
    if (temp == NULL) {
        printf("Erro ao alocar memória para temp\n");
        exit(1); // Encerra o programa se a alocação de memória falhar
    }
    int inversoes = mergeSort(arr, temp, 0, tamanho - 1);
    free(temp); // Libera a memória alocada para temp
    return inversoes;
}

int mergeSort(int arr[], int temp[], int esq, int dir) {
    int meio, inversoes = 0;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        inversoes += mergeSort(arr, temp, esq, meio);
        inversoes += mergeSort(arr, temp, meio + 1, dir);
        inversoes += merge(arr, temp, esq, meio + 1, dir);
    }
    return inversoes;
}

int merge(int arr[], int temp[], int esq, int meio, int dir) {
    int i, j, k;
    int inversoes = 0;
    i = esq;
    j = meio;
    k = esq;
    while ((i <= meio - 1) && (j <= dir)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversoes += (meio - i);
        }
    }
    while (i <= meio - 1)
        temp[k++] = arr[i++];
    while (j <= dir)
        temp[k++] = arr[j++];
    for (i = esq; i <= dir; i++)
        arr[i] = temp[i];
    return inversoes;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int inversoes = contagemInversoes(arr, tamanho);
    printf("O número de inversões é %d\n", inversoes);
    return 0;
}
