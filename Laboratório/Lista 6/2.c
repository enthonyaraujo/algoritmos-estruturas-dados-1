#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int vazia(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, char c) {
    No* novo = malloc(sizeof(No));
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char pop(Pilha* p) {
    if (vazia(p)) return '\0';
    No* temp = p->topo;
    char c = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return c;
}

void inverter(char* resultado, Pilha* p) {
    int i = 0;
    while (!vazia(p)) {
        resultado[i++] = pop(p);
    }
    resultado[i] = '\0';
}

void liberar_pilha(Pilha* p) {
    while (!vazia(p)) pop(p);
    free(p);
}

int main() {
    char entrada[100];
    printf("Digite uma palavra/frase: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;
    
    Pilha* p = criar_pilha();
    for (int i = 0; entrada[i]; i++) {
        push(p, entrada[i]);
    }
    
    char invertida[100];
    inverter(invertida, p);
    liberar_pilha(p);
    
    printf("Invertida: %s\n", invertida);
    return 0;
}
