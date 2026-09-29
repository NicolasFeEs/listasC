#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int valor;
} Dados;

typedef struct Tpilha {
    Dados dados;
    struct Spilha *prox;
    S
} Spilha;


void InicializarPilha(Pilha *p);
int Empilhar(Pilha *p, Dados d);
int Desempilhar(Pilha *p, Dados *d);
int PilhaVazia(Pilha *p);
void LiberarPilha(Pilha *p);

#endif
