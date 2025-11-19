/*
A ideia desse algoritmo vem da analogia com um duende (gnome) de jardim
arrumando vasos de flores alinhados no chão.

O gnome se comporta assim:

1) Ele olha para o vaso atual e o vaso anterior.
   - Se eles estão na ordem correta, ele anda um passo para a frente.
   - Caso contrário, ele troca os dois vasos e dá um passo para trás.

2) Se ele estiver no início (não existe vaso anterior),
   ele avança.

3) Se ele chegar ao final, a lista está ordenada e o algoritmo termina.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que troca o elemento arr[i] com arr[i-1]
void swap(int arr[], int i) {
    int temp = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = temp;
}

// Implementação do Gnome Sort
void gnomeSort(int arr[], int n) {
    int i = 0;  // posição inicial 

    while (i < n) {

        if ((i == 0) || (arr[i] >= arr[i - 1])) { // Caso esteja no início do array ou arr[i] >= arr[i-1]
            i++;  // avança
        }
        else { // Caso arr[i] < arr[i-1], troca e volta um passo.
            swap(arr, i);  
            i--;
        }
    }
}

void printArray(int arr[], int n) {  // Função auxiliar para imprimir o array
    printf("\nLista organizada com Gnome sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    printf("Gnome Sort\n");

    int arr[] = {-1,28,4,90,-2000,14,18,-20,44,17,22,2,-1,-99,22,-1,0,-4,5,-45,8,-10,2,-9,0,-13,111}; // lista de exemplo
    int n = sizeof(arr) / sizeof(arr[0]); // calcula o tamanho do array

    printf("Lista original: ");  // Imprime a lista original antes da ordenação
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    gnomeSort(arr, n); // Chama o algoritmo de ordenação

    printArray(arr, n);  // Mostra o resultado apos a ordenação
    printf("\n");

    return 0;
}
