#include <stdio.h>

int main(){

    FILE *fin; // arquivo de entrada
    FILE *fout; //arquivo de saida
    int numero;

    fin = fopen("2-entrada.txt", "r");
    
    fout = fopen("2-saida.txt","w");

    while (!feof(fin))
    {
        if (fscanf(fin, "%d", &numero) == 1)
        {
            fprintf(fout, "%d\n", numero);
        }
        else 
        {
            fgetc(fin);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}