#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Titulo {
    char nome[100];
    int ano;
    char categoria[50];
    struct Titulo* proximo;
} Titulo;

typedef struct {
    Titulo* inicio;
    Titulo* fim;
    int tamanho;
} Catalogo;

Catalogo* criar_catalogo() {
    Catalogo* catalogo = malloc(sizeof(Catalogo));
    catalogo->inicio = NULL;
    catalogo->fim = NULL;
    catalogo->tamanho = 0;
    return catalogo;
}

void adicionar_titulo(Catalogo* catalogo, const char* nome, int ano, const char* categoria) {
    Titulo* novo = malloc(sizeof(Titulo));
    strcpy(novo->nome, nome);
    novo->ano = ano;
    strcpy(novo->categoria, categoria);
    novo->proximo = NULL;
    
    if (catalogo->fim == NULL) {
        catalogo->inicio = novo;
    } else {
        catalogo->fim->proximo = novo;
    }
    catalogo->fim = novo;
    catalogo->tamanho++;
}

void buscar_por_categoria(Catalogo* catalogo, const char* categoria) {
    Titulo* atual = catalogo->inicio;
    int encontrado = 0;
    
    printf("\nTítulos na categoria '%s':\n", categoria);
    while (atual != NULL) {
        if (strcasecmp(atual->categoria, categoria) == 0) {
            printf("- %s (%d)\n", atual->nome, atual->ano);
            encontrado = 1;
        }
        atual = atual->proximo;
    }
    
    if (!encontrado) {
        printf("Nenhum título encontrado.\n");
    }
}
void listar_por_ano(Catalogo* catalogo) {
    if (catalogo->tamanho == 0) {
        printf("Catálogo vazio.\n");
        return;
    }
    
    Titulo* titulos[1000];
    Titulo* atual = catalogo->inicio;
    int i = 0;
    
    while (atual != NULL) {
        titulos[i++] = atual;
        atual = atual->proximo;
    }
    
    for (int j = 0; j < i-1; j++) {
        for (int k = 0; k < i-j-1; k++) {
            if (titulos[k]->ano > titulos[k+1]->ano) {
                Titulo* temp = titulos[k];
                titulos[k] = titulos[k+1];
                titulos[k+1] = temp;
            }
        }
    }
    
    printf("\nCatálogo ordenado por ano:\n");
    for (int j = 0; j < i; j++) {
        printf("%d. %s (%s)\n", j+1, titulos[j]->nome, titulos[j]->categoria);
    }
}

void exibir_catalogo(Catalogo* catalogo) {
    if (catalogo->tamanho == 0) {
        printf("Catálogo vazio.\n");
        return;
    }
    
    printf("\nCatálogo completo (%d títulos):\n", catalogo->tamanho);
    Titulo* atual = catalogo->inicio;
    while (atual != NULL) {
        printf("- %s (%d) - %s\n", atual->nome, atual->ano, atual->categoria);
        atual = atual->proximo;
    }
}

void destruir_catalogo(Catalogo* catalogo) {
    Titulo* atual = catalogo->inicio;
    while (atual != NULL) {
        Titulo* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(catalogo);
}

int main() {
    Catalogo* catalogo = criar_catalogo();
    
    adicionar_titulo(catalogo, "Oppenheimer", 2023, "Drama");
    adicionar_titulo(catalogo, "Um Sonho de Liberdade", 1994, "Drama");
    adicionar_titulo(catalogo, "Projeto X: Uma Festa Fora de Controle", 2012, "Comedia");
    adicionar_titulo(catalogo, "Interestelar", 2014, "Ficção Científica");
    adicionar_titulo(catalogo, "O Lobo de Wall Street", 2013, "Drama");
    
    exibir_catalogo(catalogo);
    buscar_por_categoria(catalogo, "Drama");
    buscar_por_categoria(catalogo, "Comedia");
    listar_por_ano(catalogo);
    
    destruir_catalogo(catalogo);
    return 0;
}
