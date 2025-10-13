#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    ptr = (int*) malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    *ptr = 100;

    printf("Valor armazenado inicialmente: %d\n", *ptr);

    printf("Digite um novo número inteiro: ");
    scanf("%d", ptr); 

    printf("Novo valor armazenado: %d\n", *ptr);

    free(ptr);

    return 0;
}
