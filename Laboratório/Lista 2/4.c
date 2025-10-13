/* Construa duas funções que realizem o incremento de um número em uma
unidade. A função Mais deve receber um número inteiro através de um
ponteiro. A função Incrementa deve receber um valor inteiro, sem usar
ponteiros, e retornar o valor incrementado em uma unidade. Utilize as duas
funções como no exemplo abaixo: */

#include <stdio.h>

void Mais(int *nPtr){
    (*nPtr)++;
    printf("Resultado apos Mais: %d\n", *nPtr);
}

void Incrementa(int n){
    n++;
    printf("Resultado apos Incrementa: %d\n", n);
}

int main(){

    int num;

    printf("Digite um valor: ");
    scanf("%d",&num);
    printf("\n");

    Mais(&num);
    Incrementa(num);
    return 0;
}