#include "busca_binaria.h"
#include "busca_sequencial.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copiar_lista(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main(){
    clock_t inicio, final;
    int tamanho, elemento;
    printf("Digite a quantidade de elementos da lista: ");
    scanf("%d",&tamanho);

    printf("Digite o elemento que deseja encontrar:\n");
    scanf("%d",&elemento);

    int *lista = malloc(tamanho * sizeof(int));
    int *lista_ordenada = malloc(tamanho * sizeof(int));

    if (lista == NULL || lista_ordenada == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        lista[i] = rand() % 100;
    } 

    copiar_lista(lista, lista_ordenada, tamanho);

    qsort(lista_ordenada, tamanho, sizeof(int), compare_ints);

    // BUSCA SEQUENCIAL
    inicio = clock();
    busca_sequencial(lista, tamanho, elemento);
    final = clock();
    double tempo_sequencial = (double)(final - inicio) / CLOCKS_PER_SEC;

    // BUSCA BINÁRIA 
    inicio = clock();
    busca_binaria(lista_ordenada, tamanho, elemento);
    final = clock();
    double tempo_binaria= (double)(final - inicio) / CLOCKS_PER_SEC;

    printf("Tempo da busca sequencial: %f \n", tempo_sequencial);
    printf("Tempo da busca binaria: %f \n", tempo_binaria);

    free(lista);
    free(lista_ordenada);

    return 0;
}
