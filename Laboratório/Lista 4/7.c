#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ehPalindromo(char *palavra) {
    int i = 0;
    int j = strlen(palavra) - 1;

    while (i < j) {
        if (tolower(palavra[i]) != tolower(palavra[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    FILE *fin, *fout;
    char palavra_lida[100];
    int contador_palindromos = 0;

    fin = fopen("palindromos-entrada.txt", "r");
    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir 'texto_entrada.txt'.\n");
        printf("Por favor, crie este arquivo com o texto de exemplo.\n");
        return 1;
    }

    fout = fopen("palindromos.txt", "w");
    if (fout == NULL) {
        printf("Erro: Nao foi possivel criar 'palindromos.txt'.\n");
        fclose(fin);
        return 1;
    }

    fprintf(fout, "Arquivo: palindromos.txt\n");

    while (fscanf(fin, "%s", palavra_lida) == 1) {
        if (ehPalindromo(palavra_lida)) {
            fprintf(fout, "%s\n", palavra_lida);
            contador_palindromos++;
        }
    }

    fprintf(fout, "Foram encontrados %d palindromos neste arquivo.\n", contador_palindromos);

    fclose(fin);
    fclose(fout);

    return 0;
}