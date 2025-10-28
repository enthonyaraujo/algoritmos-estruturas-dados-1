#include <stdio.h>
#include <stdlib.h>

int main()
{

FILE *fin;

fin = fopen("intro.txt", "r");

char ch;

fseek(fin, 7, SEEK_SET);

fscanf(fin, "%c", &ch);

printf("O oitavo caractere eh: %c\n", ch);

fclose(fin);

}