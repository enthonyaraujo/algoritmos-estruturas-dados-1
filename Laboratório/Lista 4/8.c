#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define um limite para o número de alunos e tamanho dos nomes
#define MAX_ALUNOS 100
#define MAX_NOME 50

// 1. Crie um registro (struct) para representar um aluno
typedef struct {
    char primeiro_nome[MAX_NOME];
    char ultimo_nome[MAX_NOME];
    char codigo[4]; // Para "M6", "T8", etc. (2 chars + '\0')
} Aluno;

int main()
{
    FILE *fin;
    // 2. Crie um vetor de alunos
    Aluno alunos[MAX_ALUNOS];
    int num_alunos = 0; // Contador de quantos alunos foram lidos

    // --- LEITURA DO ARQUIVO ---

    fin = fopen("lista_alunos.txt", "r");
    if (fin == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'lista_alunos.txt'.\n");
        printf("Por favor, crie este arquivo com a lista de alunos.\n");
        return 1;
    }

    // Lê o arquivo linha por linha e guarda no vetor de alunos
    // O loop para quando não conseguir ler 3 strings ou o vetor estiver cheio
    while (num_alunos < MAX_ALUNOS && 
           fscanf(fin, "%s %s %s", 
                  alunos[num_alunos].primeiro_nome,
                  alunos[num_alunos].ultimo_nome,
                  alunos[num_alunos].codigo) == 3)
    {
        num_alunos++; // Incrementa o contador de alunos lidos
    }

    fclose(fin);

    printf("Total de %d alunos lidos. Organizando por turma...\n\n", num_alunos);

    // --- AGRUPAMENTO E EXIBIÇÃO ---

    // Para facilitar, criamos vetores com os títulos e os códigos
    // que queremos procurar, na ordem correta da exibição.
    char *titulos[6] = {
        "Matutino 6a Série",
        "Matutino 7a Série",
        "Matutino 8a Série",
        "Vespertino 6a Série",
        "Vespertino 7a Série",
        "Vespertino 8a Série"
    };
    
    char *codigos_busca[6] = {"M6", "M7", "M8", "T6", "T7", "T8"};

    // Laço principal para agrupar (6 grupos)
    for (int g = 0; g < 6; g++) {
        
        printf("%s\n", titulos[g]);
        printf("-----------------\n");

        // Laço interno para procurar alunos do grupo atual
        for (int i = 0; i < num_alunos; i++) {
            // 3. Use testes condicionais (strcmp) para separar
            // strcmp compara duas strings. Retorna 0 se forem iguais.
            if (strcmp(alunos[i].codigo, codigos_busca[g]) == 0) 
            {
                // Exibe o aluno se o código for o correto
                printf("%s %s\t%s\n", 
                       alunos[i].primeiro_nome, 
                       alunos[i].ultimo_nome, 
                       alunos[i].codigo);
            }
        }
        printf("\n"); // Adiciona uma linha em branco entre os grupos
    }


    // --- SUGESTÃO: SEPARAR APENAS POR TURNO ---
    printf("=========================================\n");
    printf("Sugestao: Alunos separados por turno\n");
    printf("=========================================\n\n");

    // Turno Matutino (M)
    printf("Turno Matutino\n");
    printf("-----------------\n");
    for (int i = 0; i < num_alunos; i++) {
        // Verifica apenas o primeiro caractere do código
        if (alunos[i].codigo[0] == 'M') {
            printf("%s %s\t%s\n", 
                   alunos[i].primeiro_nome, 
                   alunos[i].ultimo_nome, 
                   alunos[i].codigo);
        }
    }
    printf("\n");

    // Turno Vespertino (T)
    printf("Turno Vespertino\n");
    printf("-----------------\n");
    for (int i = 0; i < num_alunos; i++) {
        // Verifica apenas o primeiro caractere do código
        if (alunos[i].codigo[0] == 'T') {
            printf("%s %s\t%s\n", 
                   alunos[i].primeiro_nome, 
                   alunos[i].ultimo_nome, 
                   alunos[i].codigo);
        }
    }
    printf("\n");


    return 0;
}