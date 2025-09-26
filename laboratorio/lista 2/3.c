/* Descubra o que acontece ao tentarmos acessar um ponteiro que contém um
endereço inválido. Para isso tente mostrar o conteúdo apontado por um ponteiro
recém-criado: */

#include <stdio.h>

int main(){

    int *ptr; // Ponteiro não inicializado
    printf("%d\n", *ptr); // Comportamento indefinido!
    return 0;
}

// um ponteiro recém-criado contém lixo de memória, ou seja, um endereço aleatório.