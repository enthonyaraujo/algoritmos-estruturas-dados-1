#include <stdio.h>
#include <stdlib.h>

int main(){

    int n_alunos;
    printf("Digite o numero de alunos (minino 2)");
    scanf("%d", &n_alunos);

    if (n_alunos > 2) {
        printf("Numero de alunos maior que 2");
    }
    float *vet = (float* ) malloc(n_alunos*sizeof(float));

    if (vet == NULL){
        printf("Erro na alocaçao de memoria\n");
        return 1;
    }

    for (int i = 0; i < n_alunos; i++)
    {
        printf("Digite a nota do aluno %d: ",i + 1);
        scanf("%f", (vet+i));
    }

    printf("\nNotas:\n");
    for (int i = 0; i < n_alunos; i++)
    {
        printf("As notas digitadas foram %d,",vet[i]);
    }
    

    free(vet);
}