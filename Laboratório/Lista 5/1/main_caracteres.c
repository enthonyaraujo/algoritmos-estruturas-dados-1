#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"

void printIntArrayChar(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", (char)arr[i]);
    }
    printf("\n");
}

int* cpArr(int *arr, int n) {
    int *nova = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) nova[i] = arr[i];
    return nova;
}

int main() {
    int n;
    clock_t inicio, final;

    printf("Digite a quantidade de elementos da lista (caracteres, MAX: 26): ");
    scanf("%d", &n);

    char arrChar[n + 1];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arrChar[i] = 'a' + (rand() % 26);
    }
    arrChar[n] = '\0';

    printf("Array de caracteres:\n");
    for (int i = 0; i < n; i++) {
        printf("%c ", arrChar[i]);
    }
    printf("\n");

    // CHAR → INT
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = (int)arrChar[i];
    }

    int *arrBubble    = cpArr(arr, n);
    int *arrInsertion = cpArr(arr, n);
    int *arrMerge     = cpArr(arr, n);
    int *arrQuick     = cpArr(arr, n);

    // BUBBLE
    inicio = clock();
    bubbleSort(arrBubble, n);
    final = clock();
    double tempo_bubble = (double)(final - inicio) / CLOCKS_PER_SEC;

    // INSERTION
    inicio = clock();
    insertionSort(arrInsertion, n);
    final = clock();
    double tempo_insertion = (double)(final - inicio) / CLOCKS_PER_SEC;

    // MERGE
    inicio = clock();
    mergeSort(arrMerge, 0, n - 1);
    final = clock();
    double tempo_merge = (double)(final - inicio) / CLOCKS_PER_SEC;

    // QUICK
    inicio = clock();
    quickSort(arrQuick, 0, n - 1);
    final = clock();
    double tempo_quick = (double)(final - inicio) / CLOCKS_PER_SEC;

    printf("Bubble sort: %f segundos\n", tempo_bubble);
    printIntArrayAsChar(arrBubble, n);

    printf("Insertion sort: %f segundos\n", tempo_insertion);
    printIntArrayAsChar(arrInsertion, n);

    printf("Merge sort: %f segundos\n", tempo_merge);
    printIntArrayAsChar(arrMerge, n);

    printf("Quick sort: %f segundos\n", tempo_quick);
    printIntArrayAsChar(arrQuick, n);

    // liberar memória
    free(arr);
    free(arrBubble);
    free(arrInsertion);
    free(arrMerge);
    free(arrQuick);

    return 0;
}
