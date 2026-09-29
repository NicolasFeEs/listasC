#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "pokemon.h"

typedef struct SLista
{
    Pokemon dados;
    struct SLista *prox;
} TLista;

TLista *CriarLista(void);
void InserirNoFim(TLista *p, Pokemon dados);
void ExibirLista(TLista *p);
int QuantidadeNaLista(TLista *p);
TLista *SelecionarPokemon(TLista *p, int posicao);
int RemoverPokemon(TLista *p, TLista *pokemon);
TLista *DestruirLista(TLista *p);

#endif // LISTA_H_INCLUDED
