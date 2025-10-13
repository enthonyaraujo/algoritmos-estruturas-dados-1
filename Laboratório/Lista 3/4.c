#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char modelo[30];
    int ano;
    float preco;
} carro;

void exibirCarro(carro * meusCarros){
    printf("Modelo: %s\n", meusCarros->modelo);
    printf("Ano: %d\n", meusCarros->ano);
    printf("Preco: %.2f\n",meusCarros->preco);

}

int main(){

    carro carros[2] = {};
    carro *ptrCarro;

    for (int i = 0; i < 2; i++)
    {
        ptrCarro = &carros[i];
        
        printf("Entre com os dados de 2 carros: \n"),
        printf("Digite o modelo do carro: \n");
        fgets(ptrCarro->modelo, sizeof(ptrCarro->modelo), stdin);

        printf("Digite o ano do carro: \n");
        scanf("%d",&ptrCarro->ano);

        printf("Digite o preco: \n");
        scanf("%f", &ptrCarro->preco);
        
        exibirCarro(&carros[i]);
        getchar();
    }
    


    return 0;
}


