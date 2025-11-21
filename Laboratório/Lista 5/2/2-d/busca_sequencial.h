#ifndef BUSCA_SEQUENCIAL_H
#define BUSCA_SEQUENCIAL_H

#include <stdio.h>
#include <string.h>

int busca_sequencial(char **lista, int tamanho, const char *elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(lista[i], elemento) == 0) {
            printf("BUSCA SEQUENCIAL: Pos da palavra: %d \n", i);
            return i;
        }
    }
    printf("BUSCA SEQUENCIAL: Palavra não encontrada\n");
    return -1;
}

#endif
