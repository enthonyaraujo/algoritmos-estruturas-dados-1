#include <stdio.h>
#include <string.h>

struct funcionario
{
    char nome[20];
    char cargo[20];
    float salario;
};

void exibir(struct funcionario* ptr){
    printf("Nome: %s\n",ptr->nome);
    printf("Cargo: %s\n",ptr->cargo);
    printf("Salario: %.2f\n",ptr->salario);
   // ptr->salario = 2.5;

}

void exibir2(struct funcionario f){
    printf("Nome: %s\n",f.nome);
    printf("Cargo: %s\n",f.cargo);
    printf("Salario: %.2f\n",f.salario);
    f.salario = 2.5;
}

int main(){
 
    struct funcionario f1 = {"Joao da impressora", "Suporte de TI", 3575.86};
    struct funcionario f2 = {"Carla do RH", "RH", 3876.85};

    exibir(&f1);
    exibir2(f1);

    exibir(&f2);
    exibir2(f2);

}