#include <stdio.h>

int busca_sequencial(int lista[], int tamanho, int elemento){
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == elemento)
        {
            printf("BUSCA SEQUENCIAL: Pos do elemento: %d\n",i);
            return i;
        }
    }
    printf("BUSCA SEQUENCIAL: Elemento nao encontrado\n");
    return -1;
}

