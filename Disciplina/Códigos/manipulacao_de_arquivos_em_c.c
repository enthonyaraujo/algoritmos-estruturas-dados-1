#include <stdio.h>
#include <stdlib.h>

int main()
{
    // usar r, w e 
    //"r": Aberto para leitura. O arquivo deve existir.
    //"w": Abre para escrita. Cria um arquivo vazio ou trunca um arquivo existente.
    //"a": Abre para anexação. Grava dados no final do arquivo. Cria o arquivo se ele não existir.

    FILE* arquivo; 
    arquivo = fopen("arquivo_de_texto.txt", "w");
    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo\n");
        return 1;
    }

    fprintf(arquivo, "Esta eh uma linha de exemplo\n");
    fprintf(arquivo, "Esta é outra linha de exemplo\n");
    fclose(arquivo);

    return 0;


}