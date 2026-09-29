
#include <stdio.h>
#include "fila.h"

void InicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int FilaVazia(Fila *f) {
    return f->tamanho == 0;
}

int FilaCheia(Fila *f) {
    return f->tamanho == TAM_MAX;
}

int InserirNaLista(Fila *f, Dados d) {
    if (FilaCheia(f)) return 0;
    f->fim = (f->fim + 1) % TAM_MAX;
    f->itens[f->fim] = d;
    f->tamanho++;
    return 1;
}

int RemoverDaFila(Fila *f, Dados *d) {
    if (FilaVazia(f)) return 0;
    *d = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX;
    f->tamanho--;
    return 1;
}

Fila IntercalarFilas(Fila *f1, Fila *f2) {
    Fila f3;
    InicializarFila(&f3);

    while (!FilaVazia(f1) && !FilaVazia(f2)) {
        Dados d;
        RemoverDaFila(f1, &d);
        InserirNaLista(&f3, d);

        RemoverDaFila(f2, &d);
        InserirNaLista(&f3, d);
    }

    Dados d;
    while (!FilaVazia(f1)) {
        RemoverDaFila(f1, &d);
        InserirNaLista(&f3, d);
    }
    while (!FilaVazia(f2)) {
        RemoverDaFila(f2, &d);
        InserirNaLista(&f3, d);
    }

    return f3;
}
