/* Como seria o output se eu desse “print” nas variáveis a seguir:
​
​int x=68, y;
int *p;
p = &x;
y = *p + 200; */

#include <stdio.h>

int main(){
    int x=68, y;
    int *p;
    p = &x;
    y = *p + 200;

    printf("Valor de X: %d\n",x);
    printf("Valor de Y: %d\n",y);
    printf("Valor de P: %p\n",p);

}