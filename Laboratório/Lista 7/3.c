#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho; 
} Lista;

Lista* criar_lista() {
    Lista* lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserir_no_inicio(Lista* lista, int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    
    if (lista->tamanho == 0) {
        novo_no->proximo = novo_no;  
        lista->inicio = novo_no;
    } else {
        novo_no->proximo = lista->inicio;
        No* ultimo = lista->inicio;
        while (ultimo->proximo != lista->inicio) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novo_no;
        lista->inicio = novo_no;
    }
    lista->tamanho++;
}

void inserir_no_fim(Lista* lista, int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    
    if (lista->tamanho == 0) {
        novo_no->proximo = novo_no;
        lista->inicio = novo_no;
    } else {
        No* ultimo = lista->inicio;
        while (ultimo->proximo != lista->inicio) {
            ultimo = ultimo->proximo;
        }
        novo_no->proximo = lista->inicio;
        ultimo->proximo = novo_no;
    }
    lista->tamanho++;
}

int buscar(Lista* lista, int valor) {
    if (lista->tamanho == 0) return 0;
    
    No* atual = lista->inicio;
    do {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    } while (atual != lista->inicio);
    
    return 0;
}

void remover(Lista* lista, int valor) {
    if (lista->tamanho == 0) return;
    
    if (lista->inicio->valor == valor) {
        if (lista->tamanho == 1) {
            free(lista->inicio);
            lista->inicio = NULL;
        } else {
            No* ultimo = lista->inicio;
            while (ultimo->proximo != lista->inicio) {
                ultimo = ultimo->proximo;
            }
            No* temp = lista->inicio;
            lista->inicio = lista->inicio->proximo;
            ultimo->proximo = lista->inicio;
            free(temp);
        }
        lista->tamanho--;
        return;
    }

    No* atual = lista->inicio;
    while (atual->proximo != lista->inicio && atual->proximo->valor != valor) {
        atual = atual->proximo;
    }
    
    if (atual->proximo != lista->inicio) {
        No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
        lista->tamanho--;
    }
}

void exibir(Lista* lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia\n");
        return;
    }
    
    No* atual = lista->inicio;
    printf("Lista circular: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("(tamanho: %d)\n", lista->tamanho);
}

void destruir(Lista* lista) {
    if (lista->tamanho == 0) {
        free(lista);
        return;
    }
    
    No* atual = lista->inicio->proximo; 
    No* temp;
    
    while (atual != lista->inicio) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista->inicio);
    free(lista);
}

int main() {
    Lista* lista = criar_lista();
    
    inserir_no_inicio(lista, 10);
    inserir_no_fim(lista, 20);
    inserir_no_inicio(lista, 5);
    exibir(lista); 
    
    printf("Busca 10: %s\n", buscar(lista, 10) ? "Sim" : "Nao");
    
    remover(lista, 10);
    exibir(lista);
    
    destruir(lista);
    return 0;
}
