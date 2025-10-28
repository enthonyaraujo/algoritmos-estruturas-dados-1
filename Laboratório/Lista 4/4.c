#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    char nome[100];
    double n1, n2, n3;
    double media;

    fin = fopen("notas.txt", "r");
    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'notas.txt'.\n");
        return 1;
    }

    fout = fopen("situacao.txt", "w");
    if (fout == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo 'situacao.txt'.\n");
        fclose(fin);
        return 1;
    }

    while (fscanf(fin, "%s %lf %lf %lf", nome, &n1, &n2, &n3) == 4) 
    {
        media = (n1 + n2 + n3) / 3.0;

        if (media >= 7.0) {
            fprintf(fout, "%s Aprovado\n", nome);
        }
        else if (media >= 4.0) {
            fprintf(fout, "%s Quarta Prova\n", nome);
        }
        else {
            fprintf(fout, "%s Reprovado\n", nome);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}