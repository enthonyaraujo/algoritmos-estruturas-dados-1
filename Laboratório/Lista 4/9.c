#include <stdio.h>
#include <stdlib.h>

struct peixe {
    char nome[20];
    unsigned peso;
    float comp;
};

int main()
{
    struct peixe p;
    FILE *f;


    printf("--- Peixes Cadastrados Atualmente ---\n");
    f = fopen("peixes.dat", "rb"); 

    if (f == NULL) {
        printf("Nenhum peixe cadastrado ainda.\n");
    } else {

        while (fread(&p, sizeof(struct peixe), 1, f) == 1) {
            printf("Nome: %s, Peso: %u g, Comp: %.1f cm\n", 
                   p.nome, p.peso, p.comp);
        }
        fclose(f);
    }
    printf("-------------------------------------\n\n");

    printf("--- Cadastrar Novo Peixe ---\n");
    
    printf("Nome do peixe: ");
    scanf("%19s", p.nome); 
    
    printf("Peso (em gramas): ");
    scanf("%u", &p.peso);
    
    printf("Comprimento (em cm): ");
    scanf("%f", &p.comp);

   
    f = fopen("peixes.dat", "ab"); 
    if (f == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo para escrita.\n");
        return 1;
    }

    fwrite(&p, sizeof(struct peixe), 1, f);
    
    fclose(f);

    printf("\nPeixe adicionado com sucesso ao arquivo 'peixes.dat'!\n");

    return 0;
}