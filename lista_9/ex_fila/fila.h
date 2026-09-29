
#ifndef FILA_H
#define FILA_H

#define TAM_MAX 200
#define TAM_NICK 50
#define CAPACIDADE_SALA 4

typedef struct {
    int valor;
    int id;
    char nickname[TAM_NICK];
} Dados;

typedef struct {
    Dados itens[TAM_MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void InicializarFila(Fila *f);
int InserirNaLista(Fila *f, Dados d);
int RemoverDaFila(Fila *f, Dados *d);
int FilaVazia(Fila *f);
int FilaCheia(Fila *f);

Fila IntercalarFilas(Fila *f1, Fila *f2);

#endif
