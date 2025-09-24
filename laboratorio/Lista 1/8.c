/* Assumindo que o endereço da variável x foi atribuído a um ponteiro px,
escreva uma expressão que não usa x e divida x por 3. */

#include <stdio.h>

int main() {
    int x = 9;        
    int *px = &x;     

    printf("Antes: x = %d\n", x);

    *px = *px / 3;

    printf("Depois: x = %d\n", x);

    return 0;
}
