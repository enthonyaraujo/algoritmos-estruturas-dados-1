/* Desenvolva uma função que receba como parâmetro os ponteiros de
dois vetores de 5 posições. O procedimento deverá imprimir na tela os
valores contidos nos dois vetores de forma crescente (Utilize ponteiros). */

#include <stdio.h>

void imprime_vetor_crescente(int *v1, int *v2) {
    int i, menor, maior;

    menor = *v1;
    maior = *v1;
    for (i = 0; i < 5; i++) {
        if (*(v1 + i) < menor) menor = *(v1 + i);
        if (*(v1 + i) > maior) maior = *(v1 + i);
        if (*(v2 + i) < menor) menor = *(v2 + i);
        if (*(v2 + i) > maior) maior = *(v2 + i);
    }

    for (int val = menor; val <= maior; val++) {
        for (i = 0; i < 5; i++) {
            if (*(v1 + i) == val || *(v2 + i) == val) {
                printf("%d ", val);
            }
        }
    }
}

int main() {
    int v1[5] = {2, 5, 9, 8, 3};
    int v2[5] = {7, 4, 1, 10, 6};

    printf("Saida: ");
    imprime_vetor_crescente(v1, v2);
    printf("\n");
    
    return 0;
}
