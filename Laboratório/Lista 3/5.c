#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Aprovado,
    Trancado,
    Reprovado
} Situacao;

typedef struct {
    char nome[50];
    unsigned int codigo_disciplina;
    Situacao situacao;
} aluno;

void mostrarAluno(aluno *a) {
    printf("\n=== Dados do aluno ===\n");
    printf("Nome: %s\n", a->nome);
    printf("Código da disciplina: %u\n", a->codigo_disciplina);

    printf("Situação: ");
    switch (a->situacao) {
        case Aprovado:
            printf("Aprovado\n");
            break;
        case Trancado:
            printf("Trancado\n");
            break;
        case Reprovado:
            printf("Reprovado\n");
            break;
    }
}

int main() {
    int n;
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    getchar(); 
    
    aluno *alunos = (aluno*) malloc(n * sizeof(aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("\n=== Cadastro do primeiro aluno ===\n");
    printf("Digite o nome: ");
    fgets(alunos[0].nome, sizeof(alunos[0].nome), stdin);
    alunos[0].nome[strcspn(alunos[0].nome, "\n")] = 0; // remove '\n'

    printf("Digite o código da disciplina: ");
    scanf("%u", &alunos[0].codigo_disciplina);

    printf("\nEscolha a situação do aluno:\n");
    printf("0 - Aprovado\n");
    printf("1 - Trancado\n");
    printf("2 - Reprovado\n");
    printf("Opção: ");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 0:
            alunos[0].situacao = Aprovado;
            break;
        case 1:
            alunos[0].situacao = Trancado;
            break;
        case 2:
            alunos[0].situacao = Reprovado;
            break;
        default:
            printf("Opção inválida! Situação definida como Reprovado.\n");
            alunos[0].situacao = Reprovado;
    }

    mostrarAluno(&alunos[0]);

    free(alunos);

    return 0;
}
