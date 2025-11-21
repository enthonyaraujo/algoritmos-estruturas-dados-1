#ifndef BUSCA_BINARIA_H
#define BUSCA_BINARIA_H
#include <string.h>
#include <stdio.h>

int busca_binaria(char **lista, int tamanho, const char *elemento) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(lista[meio], elemento); 

        if (cmp == 0) {
            printf("BUSCA BINARIA: Pos da palavra: %d\n", meio);
            return meio;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    printf("BUSCA BINARIA: Palavra não encontrado\n");
    return -1;    
}

#endif
