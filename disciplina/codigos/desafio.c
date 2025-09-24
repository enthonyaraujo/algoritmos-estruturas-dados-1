#include <stdio.h>
#include <string.h> 

/*  Faca um codigo que crie um arquivo e preencham com informacoes.
    Em seguida leiam as informacoes que voces preencheram no arquivo.
    Em seguida altera alguma informacao que voces preencheram anteriormente.
    Leia novamente o arquivo atualizado. */

int main()
{   
    char nome[50] = "Enthony Araujo";
    int idade = 21;
    char cidade[50] = "Pau dos Ferros";

    //"w": Abre para escrita. Cria um arquivo vazio ou trunca um arquivo existente.   
    FILE* wFile = fopen("arquivo.txt", "w");  //wFile = write file

    fprintf(wFile, "Nome: %s\n",nome); // linha 1
    fprintf(wFile, "Idade: %d\n",idade); // linha 2
    fprintf(wFile,"Cidade: %s\n",cidade); // linha 3
    fclose(wFile); // fecha o arquivo de escrita

    FILE* rFile = fopen("arquivo.txt", "r");
    printf("\n");
    printf("Conteudo do Arquivo:\n");
    char c;
    while ((c=fgetc(rFile)) != EOF) // EOF = end for file ; rFile = Read File
    {
        putchar(c); // Esta função é uma maneira simplificada de se mostrar um único caractere na tela
    }
    printf("\n");
    fclose(rFile); // fecha o arquivo de leitura

    idade = 22;
    strcpy(cidade, "Lucrecia RN"); 

    FILE* wFile2 = fopen("arquivo.txt", "w");  //Wfile2 = write file

    fprintf(wFile2, "Nome: %s\n",nome); // linha 1
    fprintf(wFile2, "Idade: %d\n",idade); // linha 2
    fprintf(wFile2,"Cidade: %s\n",cidade); // linha 3
    fclose(wFile2); // fecha o arquivo de escrita

    FILE* rFile2 = fopen("arquivo.txt", "r");
    printf("\n");
    printf("Conteudo do Arquivo Editado:\n");
    while ((c=fgetc(rFile2)) != EOF) // EOF = end for file ; rFile2 = Read File
    {
        putchar(c); // Esta função é uma maneira simplificada de se mostrar um único caractere na tela
    }
    printf("\n");
    fclose(rFile2); // fecha o arquivo de leitura

    return 0;
    
}

