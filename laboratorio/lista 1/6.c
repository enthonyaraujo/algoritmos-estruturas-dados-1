/*Assumindo que queremos ler o valor de x, e o endereço de x foi atribuído a
px, a instrução seguinte é correta? Por que?
scanf ( “%d”, *px );*/
#include <stdio.h>

int main(){

    int x = 2;
    int *px;

    px = &x;

    scanf("%d",*px);
    printf("%p",*px);

    return 0;

}