#include <stdio.h>
#include <stdlib.h>

int main(){
    char linha[256]; 

    FILE *fin;
    fin = fopen("intro.txt", "r");

    if (fin == NULL) {
        printf("nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    if (fgets(linha, 256, fin) != NULL) {
        printf("linha: %s \n", linha);
    } else {
        printf("nao deve ter nada ai kkk\n");
    }

    fclose(fin);
    return 0;
}