#include "busca_binaria.h"
#include "busca_sequencial.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRAS 2000000
#define MAX_TAM 128

int compare_strings(const void *a, const void *b) {
    char *const *pa = a;
    char *const *pb = b;
    return strcmp(*pa, *pb);
}

int main() {
    FILE *f = fopen("texto.txt", "r");
    if (!f) {
        printf("Erro ao abrir texto.txt\n");
        return 1;
    }

    char **lista = malloc(MAX_PALAVRAS * sizeof(char *));
    char **lista_ordenada = malloc(MAX_PALAVRAS * sizeof(char *));
    if (lista == NULL || lista_ordenada == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    int tamanho = 0;
    char buffer[MAX_TAM];

    while (fscanf(f, "%127s", buffer) == 1) {
        lista[tamanho] = strdup(buffer);
        lista_ordenada[tamanho] = strdup(buffer);
        tamanho++;
    }
    fclose(f);

    char elemento[MAX_TAM];
    printf("Digite a palavra que deseja procurar: ");
    scanf("%s", elemento);

    qsort(lista_ordenada, tamanho, sizeof(char *), compare_strings);

    clock_t inicio = clock();
    busca_sequencial(lista, tamanho, elemento);
    clock_t final = clock();
    double tempo_sequencial = (double)(final - inicio) / CLOCKS_PER_SEC;

    inicio = clock();
    busca_binaria(lista_ordenada, tamanho, elemento);
    final = clock();
    double tempo_binaria = (double)(final - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de palavras: %d\n", tamanho);
    printf("Tempo da busca sequencial: %f s\n", tempo_sequencial);
    printf("Tempo da busca binaria: %f s\n", tempo_binaria);


    for (int i = 0; i < tamanho; i++) {
        free(lista[i]);
        free(lista_ordenada[i]);
    }
    free(lista);
    free(lista_ordenada);

    return 0;
}
