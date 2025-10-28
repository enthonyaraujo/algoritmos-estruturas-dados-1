#include <stdio.h>
#include <stdlib.h> 

int main()
{
    FILE *fin; 
    char nome_peixe[100]; 
    int peso_gramas;      
    int comprimento_cm;   

    long total_gramas = 0; 
    double total_quilos;   

    fin = fopen("pescado.txt", "r");

    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'pescado.txt'.\n");
        printf("Por favor, crie este arquivo no mesmo diretorio do programa.\n");
        return 1; 
    }

    while (fscanf(fin, "%s %d %d", nome_peixe, &peso_gramas, &comprimento_cm) == 3) 
    {
        total_gramas = total_gramas + peso_gramas;
    }

    fclose(fin);

    total_quilos = (double)total_gramas / 1000.0;

    
    printf("Peso total em gramas: %ld g\n", total_gramas);
    printf("Peso total em quilos: %.2f kg\n", total_quilos);
    

    return 0; 
}