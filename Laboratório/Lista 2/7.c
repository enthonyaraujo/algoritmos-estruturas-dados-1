
/*Uma cor pode ser representada pela combinação de 4 valores de intensidade
para R (Red), G (Green), B (Blue) e A (Alpha). Esses valores podem ser
guardados em um registro com 4 inteiros de 8 bits (0-255) ou por um valor
inteiro de 32 bits codificado com os 4 valores. Construa uma união para
armazenar uma cor. Em seguida construa uma função para ler do usuário uma
cor no formato RGBA e outra para ler uma cor no formato inteiro de 32 bits.
Ambas as funções devem receber o endereço de uma variável do tipo cor e
modificar a variável recebida, sem retornar valor.*/

#include <stdio.h>
#include <stdint.h>


struct code_rgba
{
    uint8_t r, g, b, a;
};

union COR
{
    struct code_rgba rgba;
    uint32_t cod;
};

void cor_rgba(union COR *ptr)
{
    int r, g, b, a;
    printf("Informe uma cor no formato : RGBA\n");
    scanf("%d %d %d %d", &r, &g, &b, &a);

    ptr->rgba.r = (uint8_t)r;
    ptr->rgba.g = (uint8_t)g;
    ptr->rgba.b = (uint8_t)b;
    ptr->rgba.a = (uint8_t)a;
}

void cor_cod(union COR *ptr)
{
    int codigo;
    printf("Informe uma cor no formato: Int32 \n");
    scanf("%u", &codigo);

    ptr->cod = codigo;
}

void imprimir_cor(union COR *ptr)
{
    printf("Cor (R,G,B,A): (%u, %u, %u, %u)\n",
           ptr->rgba.r, ptr->rgba.g, ptr->rgba.b, ptr->rgba.a);
    printf("Valor inteiro: %u (0x%08X)\n", ptr->cod, ptr->cod);
}

int main()
{

    union COR cor, *px;
    px = &cor;

    printf("Ler cor no formato RGBA\n");
    cor_rgba(px);
    imprimir_cor(px);

    printf("Ler cor no formato inteiro\n");
    cor_cod(px);
    imprimir_cor(px);

    return 0;
}