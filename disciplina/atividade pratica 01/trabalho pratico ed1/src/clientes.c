#include <stdio.h>
#include <string.h>
#include "../include/clientes.h"
#include "../include/structs.h"

void RemoverQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void SalvarCliente(const clientes *novoCliente) {
    FILE *arquivo = fopen("../data/clientes.txt", "a"); // "a" = append (adiciona no fim)
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo clientes.txt");
        return;
    }

    fprintf(arquivo, "%s,%s,%s\n", novoCliente->nome, novoCliente->cpf, novoCliente->telefone);

    fclose(arquivo);
}

void CadastrarCliente(clientes *novoCliente) {

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("\n=== Cadastro de Cliente ===\n");

    // Nome
    printf("Digite o nome do cliente: ");
    fgets(novoCliente->nome, sizeof(novoCliente->nome), stdin);
    RemoverQuebraLinha(novoCliente->nome);

    // CPF
    printf("Digite o CPF (somente números): ");
    fgets(novoCliente->cpf, sizeof(novoCliente->cpf), stdin);
    RemoverQuebraLinha(novoCliente->cpf);

    // Telefone
    printf("Digite o telefone (somente números): ");
    fgets(novoCliente->telefone, sizeof(novoCliente->telefone), stdin);
    RemoverQuebraLinha(novoCliente->telefone);

    printf("\nCliente cadastrado com sucesso!\n");
    printf("Nome: %s\nCPF: %s\nTelefone: %s\n", 
           novoCliente->nome, novoCliente->cpf, novoCliente->telefone);
}

void MenuClientes() {
    int opcao;
    clientes novoCliente;

    do {
        printf("\n=== Menu de Clientes ===\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Atualizar Cliente\n");
        printf("3 - Remover Cliente\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            // Entrada inválida
            printf("Entrada inválida. Tente novamente.\n");
            // Limpar buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        switch (opcao) {
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            case 1:
                CadastrarCliente(&novoCliente);
                break;
            case 2:
                printf("Funcao de atualizar cliente ainda nao implementada.\n");
                break;
            case 3:
                printf("Funcao de remover cliente ainda nao implementada.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}
