#include <stdio.h>

int busca_binaria(int lista[], int tamanho, int elemento){
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = (esquerda + direita)/2;
        if (lista[meio] == elemento)
        {
            printf("BUSCA BINARIA: Pos do elemento: %d\n",meio);
            return meio;
        }
        else if (lista[meio] < elemento)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio -1;
        }
    }
    printf("BUSCA BINARIA: Elemento não encontado\n");
    return -1;    
}
