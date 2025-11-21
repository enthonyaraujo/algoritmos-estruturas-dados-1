#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"

int* cpArr(int *arr, int n) {
    int *nova = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) nova[i] = arr[i];
    return nova;
}


void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }   
    printf("\n");
}

int main(){
    int n;
    clock_t inicio, final;
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d",&n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }  

    int *arrBubble = cpArr(arr, n);
    int *arrInsertion = cpArr(arr, n);
    int *arrMerge = cpArr(arr, n);
    int *arrQuick = cpArr(arr, n);

    // BUBBLE SORT 
    inicio = clock();
    bubbleSort(arrBubble, n);
    final = clock();
    double tempo_bubble = (double)(final - inicio) / CLOCKS_PER_SEC;

    //INSERTION SORT
    inicio = clock();
    insertionSort(arrInsertion, n);
    final = clock();
    double tempo_insertion = (double)(final - inicio) / CLOCKS_PER_SEC;

    //MERGE SORT
    inicio = clock();
    mergeSort(arrMerge,0,n-1);
    final = clock();
    double tempo_merge = (double)(final - inicio) / CLOCKS_PER_SEC;

    //QUICK SORT
    inicio = clock();
    quickSort(arrQuick,0,n-1);
    final = clock();
    double tempo_quick = (double)(final - inicio) / CLOCKS_PER_SEC;
    
    printf("Bubble sort: %f segundos\n", tempo_bubble);
    printf("Insertion sort: %f segundos\n", tempo_insertion);
    printf("Merge sort: %f segundos\n", tempo_merge);
    printf("Quick sort: %f segundos\n", tempo_quick);
    return 0; 
}