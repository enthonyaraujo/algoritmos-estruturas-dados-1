#include <stdio.h>

int busca_linear(int lista[], int tamanho, int elemento){
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == elemento)
        {
            printf("Posicao do elemento: %d\n",i);
            return i;
        }
    }
    printf("Elemento nao encontrado\n");
    return -1;
}

int main(){
    int lista[] = {2,11,5,1,15,4,9,7};
    int elemento = 4;
    int tamanho = sizeof(lista);

    busca_linear(lista, tamanho, elemento);
    return 0;
}