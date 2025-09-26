/*Declare um registro "Tigela" com os campos estado (cheia ou vazia) e tipo de
alimento (sopa ou canja). Crie uma função "Fome" que recebe um ponteiro para
uma Tigela e altera o seu estado para "vazia". Na função principal crie uma
tigela cheia, crie um ponteiro que aponta para essa tigela e então mostre como a
tigela estava antes da janta. Depois chame a função Fome com o ponteiro que
aponta para a tigela e ao fim mostre a tigela depois da janta.*/

#include <stdio.h>
#include <string.h>

struct Tijela {
    char estados[10];
    char tipo[10];
};

typedef struct Tijela Tijela;

void Fome(char *estado_tijela) {
    strcpy(estado_tijela, "vazia");
}

int main() {
    Tijela minha_tijela = {"cheia", "canja"};
    Tijela *TijelaPtr = &minha_tijela;

    printf("Antes da janta - Estado: %s, Tipo: %s\n", TijelaPtr->estados, TijelaPtr->tipo);

    // Chama a função que altera o estado para "vazia"
    Fome(TijelaPtr->estados);

    printf("Depois da janta - Estado: %s, Tipo: %s\n", TijelaPtr->estados, TijelaPtr->tipo);

    return 0;
}
