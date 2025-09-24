#include <stdio.h>

int main(){
    char nome[20] = "Lilith";
    printf("%s\n",nome);

    char* ptr = &nome[1];
    *ptr = 'y';
    printf("%s\n",ptr);

    nome[3] = 'y';
    printf("%s\n",nome);

    *ptr = 'i';
    printf("%s\n",nome);

    return 0;

}