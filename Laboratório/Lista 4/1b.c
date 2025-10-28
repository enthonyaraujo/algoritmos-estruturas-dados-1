#include <stdio.h>
#include <stdlib.h>

int main(){

char palavra[100];
FILE *fin;

fin = fopen("intro.txt", "r");

fscanf(fin, "%s", palavra);

printf("a primeira palavra eh: %s\n", palavra);

fclose(fin);
return 0;

}