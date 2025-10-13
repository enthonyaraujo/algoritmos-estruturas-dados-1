#include <stdio.h>

int main(){
    FILE* arquivo = fopen("arquivo_de_texto.txt", "r");

    // fgetc() = ler um caractere por vez
    // fgets() = ler uma string 
    // fscanf = ler dados formatados 
    printf("Conteudo do Arquivo:\n");
    char c;
    while ((c=fgetc(arquivo)) != EOF)
    {
        putchar(c);
    }
    printf("\n");

    fclose(arquivo);
    return 0;

}