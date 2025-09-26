/*Descubra qual é a saída do seguinte trecho de código, sem auxílio do
computador. Depois rode o programa passo a passo com o depurador para
verificar se conseguiu chegar na resposta certa.
#include <stdio.h>
int main() {
​
int valor = 10, *temp, soma = 0;
​
​temp = &valor;
*temp = 20;
​
​temp = &soma;
*temp = valor;
​printf("valor: %d\nsoma: %d\n", valor, soma);
​
return 0;
}
Sugestão: observe como as variáveis se alteram com a execução do programa.*/
#include <stdio.h>
int main() {

    int valor = 10, *temp, soma = 0;

    temp = &valor;
    *temp = 20;

    temp = &soma;
    *temp = valor;

    printf("valor: %d\nsoma: %d\n", valor, soma);

    return 0;
}