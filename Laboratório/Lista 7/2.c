#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Lista;

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void inserir_no_inicio(Lista* lista, int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    novo_no->anterior = NULL;
    
    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo_no;
    } else {
        lista->fim = novo_no;
    }
    lista->inicio = novo_no;
}

void inserir_no_fim(Lista* lista, int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = lista->fim;
    
    if (lista->fim != NULL) {
        lista->fim->proximo = novo_no;
    } else {
        lista->inicio = novo_no;
    }
    lista->fim = novo_no;
}

int buscar(Lista* lista, int valor) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void remover(Lista* lista, int valor) {
    No* atual = lista->inicio;
    
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }
    
    if (atual == NULL) return;  
    
    if (atual == lista->inicio) {
        lista->inicio = atual->proximo;
        if (lista->inicio != NULL) {
            lista->inicio->anterior = NULL;
        } else {
            lista->fim = NULL;
        }
    }
    else if (atual == lista->fim) {
        lista->fim = atual->anterior;
        lista->fim->proximo = NULL;
    }
    else {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    
    free(atual);
}

void exibir(Lista* lista) {
    No* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void destruir(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

int main() {
    Lista* lista = criar_lista();
    
    inserir_no_inicio(lista, 10);
    inserir_no_fim(lista, 20);
    inserir_no_inicio(lista, 5);
    inserir_no_fim(lista, 30);
    exibir(lista);  
    
    printf("Busca 20: %s\n", buscar(lista, 20) ? "Sim" : "Nao");
    
    remover(lista, 10);
    exibir(lista);  
    
    destruir(lista);
    return 0;
}
