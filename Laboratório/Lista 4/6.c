#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fin;
    char nome_arquivo[100];
    char palavra_procurada[100];
    char palavra_lida[100];
    int encontrada = 0;

    printf("Nome do arquivo: ");
    scanf("%99s", nome_arquivo);

    printf("Palavra: ");
    scanf("%99s", palavra_procurada);

    fin = fopen(nome_arquivo, "r");

    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo '%s'.\n", nome_arquivo);
        return 1;
    }

    while (fscanf(fin, "%s", palavra_lida) == 1) 
    {
        if (strcmp(palavra_lida, palavra_procurada) == 0) 
        {
            encontrada = 1;
            break; 
        }
    }

    fclose(fin);

    if (encontrada == 1) {
        printf("A palavra \"%s\" esta presente no texto.\n", palavra_procurada);
    } else {
        printf("A palavra \"%s\" nao esta presente no texto.\n", palavra_procurada);
    }

    return 0;
}