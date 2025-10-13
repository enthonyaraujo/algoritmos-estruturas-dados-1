/* Defina um registro que descreve um peixe. O registro deve incluir o tipo
(string), o peso (ponto-flutuante) e o comprimento (inteiro) do peixe. Em
seguida mostre:
a) Como criar uma variável de tipo peixe
b) Como criar um ponteiro para uma variável de tipo peixe */

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

int main(){

    peixe p1 = {"Tilapia", 2.8, 25}; // a) criando a variavel do tipo peixe
    
    peixe *ptrPEIXE; // b) criando um ponteiro para a variavel do tipo peixe
    ptrPEIXE = &p1;


    printf("\n");
    printf("Tipo: %s \n", p1.tipo);
    printf("Peso: %.2f kg \n", p1.peso);
    printf("Comprimento: %d cm \n", p1.comprimento);

    printf("\n");
    printf("Tipo: %s (usando ponteiro)\n ", ptrPEIXE->tipo);
    printf("Peso: %.2f kg (usando ponteiro)\n", ptrPEIXE->peso);
    printf("Comprimento: %d cm (usando ponteiro)\n", ptrPEIXE->comprimento);
     
    return 0;
}