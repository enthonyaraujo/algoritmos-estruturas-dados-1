#include <stdio.h>
#include <stdlib.h>

struct peixe {
    char nome[20];
    unsigned peso;
    float comp;
};

int main()
{
    FILE *fin_texto, *fout_binario;
    struct peixe p;

    fin_texto = fopen("pescado.txt", "r");
    if (fin_texto == NULL) {
        printf("Erro: Nao foi possivel abrir 'pescado.txt'.\n");
        printf("Por favor, crie este arquivo com o texto de exemplo.\n");
        return 1;
    }

    fout_binario = fopen("peixes.dat", "wb");
    if (fout_binario == NULL) {
        printf("Erro: Nao foi possivel criar 'peixes.dat'.\n");
        fclose(fin_texto);
        return 1;
    }

    printf("Iniciando conversao de 'pescado.txt' para 'peixes.dat'...\n");

    while(fscanf(fin_texto, "%s %u %f", p.nome, &p.peso, &p.comp) == 3) 
    {
        fwrite(&p, sizeof(struct peixe), 1, fout_binario);
    }

    fclose(fin_texto);
    fclose(fout_binario);

    printf("Conversao concluida com sucesso!\n");

    return 0;
}