#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct 
{
    char nome[100];
    int cpf; // deve conter 11 numeros
    int telefone; // deve conter 12 numeros
} clientes;

typedef struct 
{
    char placa[7];
    char modelo[50];
    int ano;
    char *clientePtr;
} veiculos;

typedef enum{
    AGUARDANDO_AVALIACAO,
    EM_REPARO, 
    FINALIZADO, 
    ENTREGUE
} statusOrdem;

typedef struct {
    int idOrdem;               
    veiculos *veiculo;          
    char dataEntrada[11];      
    char descricaoProblema[256]; 
    statusOrdem status;
} OrdemServico;        

#endif

