#include <stdio.h>

int main(){
    int copos = 6;
    int *pt1 = &copos;
    pt1 = &copos;

    double cafe = 4.5;
    double *pt2 = &cafe;
    pt2 = &cafe; 

    printf("Valor de copos = %d \n", copos);
    printf("Endereço de copos = %p \n",pt1);


    printf("Valor do café = %.2f \n", cafe);
    printf("Endereço do café = %p \n",pt2);

    *&copos = 2;
    *&cafe = 5.9;

    printf("Novo valor de copos = %d \n",copos);

    printf("Novo valor de cafes = %.2f \n",cafe);




   // printf("%d \n",*&copos);
  //  printf("%.2f \n", *&cafe);

    return 0;

}