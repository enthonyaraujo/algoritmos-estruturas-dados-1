#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char caractere;
    int valor;
} ASCII;

ASCII* cria_ascii(int valor, char caractere) {
    ASCII *p = (ASCII*) malloc(sizeof(ASCII));
    if (!p) {
        printf("Erro na alocacao de memoria.\n");
        return NULL;
    }
    p->caractere = caractere;
    p->valor = valor;
    return p;
}

int main() {
    int valor;
    char caractere;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    while (getchar() != '\n'); 

    printf("Digite um caractere: ");
    caractere = getchar();

    ASCII *p_ascii = cria_ascii(valor, caractere);
    if (!p_ascii) {
        return 1;
    }

    printf("\nValores armazenados:\n");
    printf("Caractere: %c\n", p_ascii->caractere);
    printf("Valor: %d\n", p_ascii->valor);

    free(p_ascii);  

    return 0;
}
