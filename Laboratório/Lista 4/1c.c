#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palavra[100];
    int i;

    FILE *fin;
    fin = fopen("intro.txt", "r");

    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {

        if (fscanf(fin, "%s", palavra) != 1) {
            printf("Erro: O arquivo tem menos de 5 palavras.\n");
            fclose(fin);
            return 1;
        }
    }

    printf("A quinta palavra eh: %s\n", palavra);

    fclose(fin);
    return 0;
}