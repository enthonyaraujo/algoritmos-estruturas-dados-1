/* Crie uma variável do tipo char inicializada para o caractere 'A' e um ponteiro
que aponte para esta variável. Modifique a variável criada usando o ponteiro, de
forma que seu conteúdo agora seja 'B'. Por fim, mostre o conteúdo da variável e
o conteúdo apontado pelo ponteiro. */

#include <stdio.h>

int main(){

    char c = 'A';
    char *ptr;
    ptr = &c;
    *ptr = 'B';
    
    printf("%c\n", c);
    printf("%c\n", *ptr);
    return 0;
}