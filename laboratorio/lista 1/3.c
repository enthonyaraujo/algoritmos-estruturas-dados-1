/*Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch
foi atribuído ao ponteiro indica?*/

#include <stdio.h>

int main(){
    
    char ch = 'A';
    char* indica;
    indica = &ch;

    printf("Valor de ch direto: %c\n", ch);
    printf("Valor de ch pelo ponteiro: %c\n",*indica);

    return 0;
}
