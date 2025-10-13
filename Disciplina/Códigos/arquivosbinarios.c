#include <stdio.h>

int main()
{
    FILE* arquivo = fopen("dados.bin","rb");

    int numeros[5];
    fread(numeros,sizeof(int),5,arquivo);
   // int numeros[] = {10,20,30,40,50};

   // fwrite(numeros,sizeof(int), 5, arquivo);

   // size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);

    fclose(arquivo);

    //printf("Dados gravados com sucesso");
    printf("Dados lidos do arquivo: \n");
    int i;
    for (i=0; i<5; i++) {
        printf("%d ", numeros[i] );
    }
    printf("\n");
    return 0;
}