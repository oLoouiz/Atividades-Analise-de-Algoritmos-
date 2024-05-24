#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

void Desordenado(int numeros[]){
    int i;
  printf("Ordem atual dos itens no array:\n");
    for (i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }
}

void BubbleSort(int numeros[]) {
    int i, j, aux;

    for (i = 0; i < TAM - 1; i++) {
        for (j = 0; j < TAM - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
    printf("\n\nBubblesort:\n");
    for (i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }
    printf("\n");
}

void InsertionSort(int numeros[]) {
    int i, j, chave;
    for (i = 1; i < TAM; i++) {
        chave = numeros[i];
        j = i - 1;

        while (j >= 0 && numeros[j] > chave) {
            numeros[j + 1] = numeros[j];
            j = j - 1;
        }
        numeros[j + 1] = chave;
    }

    printf("Insertion Sort:\n");
    for (i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }
    printf("\n");
}

void SelectionSort(int numeros[]) {
    int i, j, min_index, temp;

    for (i = 0; i < TAM - 1; i++) {
        min_index = i;
        for (j = i + 1; j < TAM; j++) {
            if (numeros[j] < numeros[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = numeros[i];
            numeros[i] = numeros[min_index];
            numeros[min_index] = temp;
        }
        printf("Selection Sort:\n");
        for (i = 0; i < TAM; i++) {
            printf("%4d", numeros[i]);
        }
        printf("\n");
    }
}

void ShellSort(int numeros[]) {
    int i, j, lacuna, temp;

    for (lacuna = TAM / 2; lacuna > 0; lacuna /= 2) {
        for (i = lacuna; i < TAM; i++) {
            temp = numeros[i];
            for (j = i; j >= lacuna && numeros[j - lacuna] > temp; j -= lacuna) {
                numeros[j] = numeros[j - lacuna];
            }
            numeros[j] = temp;
        }
        
        }
        printf("Shell Sort:\n");
        for (i = 0; i < TAM; i++) {
            printf("%4d", numeros[i]);}
        printf("\n");
        
    }

//HeapSort
void heapify(int numeros[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int temp;

    if (esq < n && numeros[esq] > numeros[maior])
        maior = esq;

    if (dir < n && numeros[dir] > numeros[maior])
        maior = dir;

    if (maior != i) {
        temp = numeros[i];
        numeros[i] = numeros[maior];
        numeros[maior] = temp;
        heapify(numeros, n, maior);
    }
}

void heapSort(int numeros[]) {
    int i, temp;

    // construindo o heap
    for (i = TAM / 2 - 1; i >= 0; i--) {
        heapify(numeros, TAM, i);
    }

    for (i = TAM - 1; i > 0; i--) {
        temp = numeros[0];
        numeros[0] = numeros[i];
        numeros[i] = temp;
        heapify(numeros, i, 0);
    }

    printf("Heap Sort:\n");
    for (i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }
    printf("\n");
}

//MergeSort
void merge(int numeros[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int L[n1], R[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = numeros[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = numeros[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            numeros[k] = L[i];
            i++;
        } else {
            numeros[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numeros[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        numeros[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int numeros[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergeSort(numeros, esq, meio);
        mergeSort(numeros, meio + 1, dir);

        merge(numeros, esq, meio, dir);
    }
    if (esq == 0 && dir == TAM - 1) {
        printf("Merge Sort:\n");
        for (int i = 0; i < TAM; i++) {
            printf("%4d", numeros[i]);
        }
        printf("\n");
    }
}

//QuickSort
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int numeros[], int inicio, int fim) {
    int pivo = numeros[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (numeros[j] < pivo) {
            i++;
            trocar(&numeros[i], &numeros[j]);
        }
    }
    trocar(&numeros[i + 1], &numeros[fim]);
    return (i + 1);
}

void quickSort(int numeros[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particionar(numeros, inicio, fim);

        quickSort(numeros, inicio, indice_pivo - 1);
        quickSort(numeros, indice_pivo + 1, fim);

        if (inicio == 0 && fim == TAM - 1) {
            printf("Quick Sort:\n");
            for (int i = 0; i < TAM; i++) {
                printf("%4d", numeros[i]);
            }
            printf("\n");
        }
    }
}

//CountingSort
void countingSort(int numeros[], int tamanho) {

    //encontrar o maior elemento 
    int max = numeros[0];
    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] > max) {
            max = numeros[i];
        }
    }

    //array de zeros
    int *contagem = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        contagem[numeros[i]]++;
    }

    int indice = 0;
    for (int i = 0; i <= max; i++) {
        while (contagem[i] > 0) {
            numeros[indice++] = i;
            contagem[i]--;
        }
    }

    printf("Counting Sort:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%4d", numeros[i]);
    }
    printf("\n");

    free(contagem);
}


//BucketSort
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void inserir(Node **cabeca, int valor) {
    Node *novo_no = (Node *)malloc(sizeof(Node));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    Node *atual = *cabeca;
    if (atual == NULL)
        *cabeca = novo_no;
    else {
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo_no;
    }
}

void liberar_lista(Node *cabeca) {
    Node *temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }
}

void bucketSort(int numeros[], int tamanho) {
    const int num_buckets = 5;
    Node *buckets[num_buckets];

    for (int i = 0; i < num_buckets; i++)
        buckets[i] = NULL;

    for (int i = 0; i < tamanho; i++) {
        int indice = numeros[i] / (tamanho / num_buckets);
        inserir(&buckets[indice], numeros[i]);
    }

    int indice = 0;
    for (int i = 0; i < num_buckets; i++) {
        Node *cabeca = buckets[i];
        int bucket_size = 0;
        while (cabeca != NULL) {
            bucket_size++;
            cabeca = cabeca->proximo;
        }

        int elementos[bucket_size];
        cabeca = buckets[i];
        for (int j = 0; j < bucket_size; j++) {
            elementos[j] = cabeca->valor;
            cabeca = cabeca->proximo;
        }
        qsort(elementos, bucket_size, sizeof(int), comparar);

        for (int j = 0; j < bucket_size; j++)
            numeros[indice++] = elementos[j];

        liberar_lista(buckets[i]);
    }

    // Imprimir o array ordenado
    printf("Bucket Sort:\n");
    for (int i = 0; i < tamanho; i++)
        printf("%4d", numeros[i]);
    printf("\n");
}

//RadixSort
int encontrar_maximo(int numeros[], int tamanho) {
    int max = numeros[0];
    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] > max) {
            max = numeros[i];
        }
    }
    return max;
}

void contar_digitos(int numeros[], int tamanho, int exp) {
    int output[tamanho];
    int contagem[10] = {0};

    for (int i = 0; i < tamanho; i++) {
        contagem[(numeros[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        output[contagem[(numeros[i] / exp) % 10] - 1] = numeros[i];
        contagem[(numeros[i] / exp) % 10]--;
    }

    for (int i = 0; i < tamanho; i++) {
        numeros[i] = output[i];
    }
}

void radixSort(int numeros[], int tamanho) {
    int max = encontrar_maximo(numeros, tamanho);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        contar_digitos(numeros, tamanho, exp);
    }

    // Imprimir o array ordenado
    printf("Radix Sort:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%4d", numeros[i]);
    }
    printf("\n");
}

int main() {
    int i = 0;
    int numeros[TAM];

    printf("Digite 10 numeros:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &numeros[i]);
    }
     
    Desordenado(numeros);
    BubbleSort(numeros);
    InsertionSort(numeros);
    SelectionSort(numeros);
    ShellSort(numeros);
    heapSort(numeros);
    mergeSort(numeros, 0, TAM - 1);
    quickSort(numeros, 0, TAM - 1);
    countingSort(numeros, TAM);
    bucketSort(numeros, TAM);
    radixSort(numeros, TAM);


    return 0;
}
