#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  

int main()
{
    FILE *fin;
    int ch; 

    int total_caracteres = 0;
    int total_vogais = 0;
    int total_consoantes = 0;
    int total_outros = 0;

    fin = fopen("texto.txt", "r");

    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'texto.txt'.\n");
        printf("Por favor, crie este arquivo no mesmo diretorio do programa.\n");
        return 1; 
    }

    printf("Lendo arquivo 'texto.txt'...\n\n");

    while ((ch = fgetc(fin)) != EOF) 
    {
        total_caracteres++;
        
        if (isalpha(ch)) 
        {
            char lower_ch = tolower(ch);

            if (lower_ch == 'a' || lower_ch == 'e' || 
                lower_ch == 'i' || lower_ch == 'o' || lower_ch == 'u') 
            {
                total_vogais++;
            } 
            else 
            {
                total_consoantes++;
            }
        }
        else 
        {
            total_outros++;
        }
    }

    fclose(fin);

    printf("--- Analise Concluida ---\n");
    printf("Total de Caracteres: %d\n", total_caracteres);
    printf("Numero de Vogais:    %d\n", total_vogais);
    printf("Numero de Consoantes: %d\n", total_consoantes);
    printf("Outros Caracteres:   %d\n", total_outros);
    printf("(Outros = pontuacao, numeros, espacos, quebras de linha, etc.)\n");

    return 0; 
}