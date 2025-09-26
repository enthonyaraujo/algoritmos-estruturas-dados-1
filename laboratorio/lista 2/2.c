/* Construa uma função que receba um peixe e exiba o seu conteúdo.
a) Faça uma versão utilizando um parâmetro tipo peixe
b) Faça uma versão utilizando um parâmetro tipo ponteiro para peixe */

#include <stdio.h>
#include <string.h>

#define TAM 50

struct peixe
{
    char tipo[TAM];
    float peso;
    int comprimento;
};

typedef struct peixe peixe;

// a) funcao de exibir parametro peixe

void exibir(peixe p){
    printf("\n");
    printf("Tipo: %s \n", p.tipo);
    printf("Peso: %.2f kg \n", p.peso);
    printf("Comprimento: %d cm \n", p.comprimento);
}

// b) funcao para exibir parametro ponteiro do peixe
void exibirPTR(peixe *ptr){
    printf("\n");
    printf("Tipo: %s \n", ptr->tipo);
    printf("Peso: %.2f kg \n", ptr->peso);
    printf("Comprimento: %d cm \n", ptr->comprimento);
}

int main(){

    peixe p1 = {"Tilapia", 2.8, 25}; 
    
    exibir(p1);
    exibirPTR(&p1);

    return 0;
}