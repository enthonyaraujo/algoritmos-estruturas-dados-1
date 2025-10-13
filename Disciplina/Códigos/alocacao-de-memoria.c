#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pi = (int *)(malloc(sizeof(int)));
    if (pi == NULL) {
        printf("Falha na alocao de memoria.\n");
        return 1;
    }
    *pi = 1001;
    printf("Valor inteiro = %d\n", *pi);
    printf("Localizacao = %p \n\n", (void *)pi);

    double *pd = (double *)malloc(sizeof(double));
    if (pd == NULL){
        printf("Falha na alocacao de memoria. \n");
        free(pi);
        return 1;
    }
    *pd = 500.35;
    printf("Valor ponto flutuante = %.2f\n",*pd);
    printf("Localizacao = %p \n\n", (void *)pd);   
    
    printf("Tamanho de pi = %zu\n", sizeof(pi));
    printf("Tamanho de *pi = %zu\n", sizeof(*pi));
    printf("Tamanho de pd = %zu\n", sizeof(pd));
    printf("Tamanho de *pd = %zu\n", sizeof(*pd));

    free(pi);
    free(pd);
    return 0;
}