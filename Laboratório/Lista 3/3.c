#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char modelo[30];
    int ano;
    float preco;
} carro;

float calcularValorTotal(carro *vetor, int quantidade) {
    float total = 0;
    for (int i = 0; i < quantidade; i++) {
        total += vetor[i].preco;
    }
    return total;
}

int main() {
    int qtd = 2;  
    carro *carros;

    carros = (carro*) malloc(qtd * sizeof(carro));
    if (carros == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    
    for (int i = 0; i < qtd; i++) {
        printf("\n=== Cadastro do carro %d ===\n", i + 1);

        printf("Digite o modelo: ");
        fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
        carros[i].modelo[strcspn(carros[i].modelo, "\n")] = 0; // remove '\n'

        printf("Digite o ano: ");
        scanf("%d", &carros[i].ano);

        printf("Digite o preço: ");
        scanf("%f", &carros[i].preco);
        getchar(); // limpa buffer
    }

    printf("\n=== Lista de carros cadastrados ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Carro %d:\n", i + 1);
        printf("  Modelo: %s\n", carros[i].modelo);
        printf("  Ano: %d\n", carros[i].ano);
        printf("  Preço: R$ %.2f\n", carros[i].preco);
    }

    float total = calcularValorTotal(carros, qtd);
    printf("\nValor total dos carros: R$ %.2f\n", total);

 
    free(carros);

    return 0;
}
