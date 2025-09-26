/*Declare um registro Horário com os campos horas e minutos. Crie uma
função MostrarHorario que deve receber um ponteiro para um Horário e
mostrá-lo no formato HH:MM. Na função principal, declare uma variável do
tipo Horário e um ponteiro que aponta para ela. Peça que o usuário digite o
horário atual e guarde-o na variável. Usando o ponteiro, incremente o horário
recebido em uma hora e em seguida mostre o horário corrigido com
MostrarHorario.*/

#include <stdio.h>

struct Horario
{
    int horas, minutos;
};

int VerificarHorario(struct Horario *h) {
    return (h->horas >= 0 && h->horas <= 23) && 
           (h->minutos >= 0 && h->minutos <= 59);
}

void MostrarHorario(struct Horario *ptr){
    printf("%02d:%02d\n", ptr->horas, ptr->minutos);
}
int main(){

    struct Horario horario = {};
    struct Horario *HorarioPtr;
    HorarioPtr = &horario;

    printf("Digite um horario [HORAS:MINUTOS])\n");
    scanf("%d %d",&HorarioPtr->horas, &HorarioPtr->minutos);

    if (VerificarHorario(HorarioPtr)) {
        HorarioPtr->horas++;
        if (HorarioPtr->horas == 24)
        {
            HorarioPtr->horas = 0;
        } 
        printf("Seu reologio esta atrasado, o horario correto é ");
        MostrarHorario(HorarioPtr);
    }    
    else {
        printf("Horário inválido!\n");
    }
    

}

