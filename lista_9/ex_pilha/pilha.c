#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void InicializarPilha(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int Empilhar(Pilha *p, Dados d) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) return 0;

    novo->dados = d;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    return 1;
}

int Desempilhar(Pilha *p, Dados *d) {
    if (p->topo == NULL) return 0;

    Node *tmp = p->topo;
    *d = tmp->dados;
    p->topo = tmp->prox;
    free(tmp);
    p->tamanho--;
    return 1;
}

int PilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void LiberarPilha(Pilha *p) {
    Dados d;
    while (Desempilhar(p, &d));
}
