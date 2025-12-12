#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void inserir_no_inicio(Lista* lista, int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
}

void inserir_no_fim(Lista* lista, int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    
    if (lista->inicio == NULL) {
        lista->inicio = novo_no;
        return;
    }
    
    No* atual = lista->inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo_no;
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
    if (lista->inicio == NULL) return;
    
    if (lista->inicio->valor == valor) {
        No* temp = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(temp);
        return;
    }
    
    No* atual = lista->inicio;
    while (atual->proximo != NULL && atual->proximo->valor != valor) {
        atual = atual->proximo;
    }
    
    if (atual->proximo != NULL) {
        No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
    }
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
    exibir(lista); 
    
    int elemento_na_busca = 20;

    printf("Busca %d: %s\n",elemento_na_busca, buscar(lista, elemento_na_busca) ? "Sim" : "Nao");
    
    remover(lista, 10);
    exibir(lista);  
    
    destruir(lista);
    return 0;
}
