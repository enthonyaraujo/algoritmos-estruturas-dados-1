/*Declare uma variável e “printe” o valor dela e o seu endereço.*/

#include <stdio.h>

int main(){

    int idade = 22;

    printf("%d\n",idade);
    printf("%p\n", &idade);

    return 0;
}