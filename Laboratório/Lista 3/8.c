#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;   
    int n;      

    printf("Quantos valores deseja guardar? ");
    scanf("%d", &n);

    vetor = (int*) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("\nQuais os valores? \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Os valores ");
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%d ", vetor[i]);          
        else
            printf("%d, ", vetor[i]);
    }          
    printf("foram armazenados.\n");


    printf("\n");

    free(vetor);

    return 0;
}
