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

void empilhar(Pilha* p, char c) {
    No* novo = malloc(sizeof(No));
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilhar(Pilha* p) {
    if (vazia(p)) return '\0';
    No* temp = p->topo;
    char c = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return c;
}

int balanceada(char* s) {
    Pilha* p = criar_pilha();
    char pares[128] = {0};
    pares[')'] = '('; pares[']'] = '['; pares['}'] = '{';
    
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            empilhar(p, c);
        } else if (pares[(int)c]) {
            char topo = desempilhar(p);
            if (topo != pares[(int)c]) {
                free(p);
                return 0;  // n balanceada
            }
        }
    }
    
    int resultado = vazia(p);
    free(p);
    return resultado;
}

int main() {
    char entrada[100];
    printf("Digite a entrada: \n");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;  
    
    if (balanceada(entrada)) {
        printf("Entrada Balanceada\n");
    } else {
        printf("Entrada não Balanceada\n");
    }
    return 0;
}
