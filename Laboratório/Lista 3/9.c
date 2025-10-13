#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    char pais[50];
    char continente[50];
} Local;

int main() {
    int n;
    Local *locais;

    printf("Quantos locais voce quer visitar nas proximas ferias? ");
    scanf("%d", &n);
    getchar(); 

    locais = (Local*) malloc(n * sizeof(Local));

    if (locais == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n=== Local %d ===\n", i + 1);

        printf("Nome do local: ");
        fgets(locais[i].nome, sizeof(locais[i].nome), stdin);

        printf("Pais: ");
        fgets(locais[i].pais, sizeof(locais[i].pais), stdin);

        printf("Continente: ");
        fgets(locais[i].continente, sizeof(locais[i].continente), stdin);
    }

    printf("\nVoce escolheu visitar os seguintes locais:\n");
    for (int i = 0; i < n; i++) {
        printf("\nLocal %d:\n", i + 1);
        printf("Nome: %s", locais[i].nome);
        printf("Pais: %s", locais[i].pais);
        printf("Continente: %s", locais[i].continente);
    }

    free(locais);

    return 0;
}
