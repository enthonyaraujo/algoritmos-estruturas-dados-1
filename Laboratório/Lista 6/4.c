#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct No {
    double dado;  
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

void push(Pilha* p, double valor) {
    No* novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

double pop(Pilha* p) {
    if (vazia(p)) return 0;
    No* temp = p->topo;
    double valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

double avaliar_posfixa(char* posfixa) {
    Pilha* p = criar_pilha();
    int i = 0;
    
    while (posfixa[i]) {
        char c = posfixa[i];
        
        if (isspace(c)) { i++; continue; }
        
        if (isdigit(c)) {
            double num = 0;
            while (isdigit(posfixa[i])) {
                num = num * 10 + (posfixa[i] - '0');
                i++;
            }
            push(p, num);
            continue; 
        }
        
        if (strchr("+-*/", c)) {
            double b = pop(p);
            double a = pop(p);
            switch (c) {
                case '+': push(p, a + b); break;
                case '-': push(p, a - b); break;
                case '*': push(p, a * b); break;
                case '/': push(p, a / b); break;
            }
        }
        i++;
    }
    
    double resultado = pop(p);
    while (!vazia(p)) pop(p);  
    free(p);
    return resultado;
}

int main() {
    char posfixa[100];
    printf("Digite a expressão pós-fixa: ");
    fgets(posfixa, sizeof(posfixa), stdin);
    posfixa[strcspn(posfixa, "\n")] = 0;
    
    double resultado = avaliar_posfixa(posfixa);
    printf("Saída: %.0f\n", resultado);
    return 0;
}
