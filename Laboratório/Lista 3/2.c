#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Como criar uma variável de tipo peixe
typedef struct 
{
    char especie[30];
    float peso;
    float comprimento;
    

} peixe;

typedef struct {
    float diametro; //diametro em metros
    char marca[20]; //nome da marca
    int modelo; // numero do modelo
} balao;

int main() {

    // alocar dinamicamente uma variável do tipo balao
    balao *meuBalao;

    meuBalao = (balao*) malloc(sizeof(balao));
    if (meuBalao == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite a marca do balão: ");
    fgets(meuBalao->marca, sizeof(meuBalao->marca), stdin);
    meuBalao->marca[strcspn(meuBalao->marca, "\n")] = 0; 

    printf("Digite o diametro do balão: ");
    scanf("%f", &meuBalao->diametro);

    printf("Digite o modelo do balão: ");
    scanf("%d", &meuBalao->modelo);


    printf("\n=== Dados do Balão ===\n");
    printf("Mrca: %s\n", meuBalao->marca);
    printf("diametro: %.2f\n", meuBalao->diametro);
    printf("modelo: %d\n", meuBalao->modelo);

 
    free(meuBalao);

    getchar();

    // como alocar dinamicamemnte um registro do tipo peixe

    peixe *meuPeixe = (peixe*) malloc(sizeof(peixe));

    if (meuPeixe == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite a espécie: ");
    fgets(meuPeixe->especie, sizeof(meuPeixe->especie), stdin);
    meuPeixe->especie[strcspn(meuPeixe->especie, "\n")] = 0;

    printf("Digite o peso: ");
    scanf("%f", &meuPeixe->peso);

    printf("Digite o comprimento: ");
    scanf("%d", &meuPeixe->comprimento);

    printf("\n=== Peixe ===\n");
    printf("Espécie: %s\n", meuPeixe->especie);
    printf("Peso: %.2f kg\n", meuPeixe->peso);
    printf("Comprimento: %.2f anos\n", meuPeixe->comprimento);

    free(meuPeixe);


    return 0;
}
