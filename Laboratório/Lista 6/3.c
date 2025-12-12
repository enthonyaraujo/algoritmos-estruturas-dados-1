#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
char peek(Pilha* p) {
    if (vazia(p)) return '\0';
    return p->topo->dado;
}

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void posfixa(char* saida, char* infixa) {
    Pilha* p = criar_pilha();
    int i = 0, j = 0;
    
    while (infixa[i]) {
        char c = infixa[i];
        
        if (isspace(c)) { i++; continue; }  
        
        if (isdigit(c) || (c >= 'A' && c <= 'Z')) {
            saida[j++] = c; 
        }
        else if (c == '(') {
            push(p, c);
        }
        else if (c == ')') {
            while (!vazia(p) && peek(p) != '(') {
                saida[j++] = pop(p);
            }
            pop(p); 
        }
        else if (strchr("+-*/", c)) {  
            while (!vazia(p) && peek(p) != '(' && 
                   precedencia(peek(p)) >= precedencia(c)) {
                saida[j++] = pop(p);
            }
            push(p, c);
        }
        i++;
    }
    
    while (!vazia(p)) {
        saida[j++] = pop(p);
    }
    saida[j] = '\0';
    
    while (!vazia(p)) pop(p);
    free(p);
}
int main() {
    char infixa[100];
    printf("Digite a expressão infixa: ");
    fgets(infixa, sizeof(infixa), stdin);
    infixa[strcspn(infixa, "\n")] = 0; 
    
    char posfixa_saida[100];
    posfixa(posfixa_saida, infixa);
    printf("Saída: %s\n", posfixa_saida);
    return 0;
}
