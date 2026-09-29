#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//ex 1
int BuscarMenorValor(Lista *lista, int *codProd, char *nomeProd, float *valor, int *qtdeEstoque) {
    if (lista->inicio == NULL) return 0;//retorno se não foi possivel fazer a operação

    Tlista *atual = lista->inicio;
    Tlista *menor = atual;

    while (atual != NULL) {
        if (atual->dados.valor < menor->dados.valor) {
            menor = atual;
        }
        atual = atual->prox;
    }

    *codProd = menor->dados.codProd;
    strcpy(nomeProd, menor->dados.nomeProd);
    *valor = menor->dados.valor;
    *qtdeEstoque = menor->dados.qtdeEstoque;//retorna por ref
    return 1;
}

// Ex 2
int Pares(Lista *lista) {
    int cont = 0;
    Tlista *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dados.valor % 2 == 0) cont++;
        atual = atual->prox;
    }
    return cont;
}

// Ex 3
Lista ListaPares(Lista *lista) {
    Lista nova;
    Tlista *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dados.valor % 2 == 0) {
            InserirNoFim(&nova, atual->dados);
        }
        atual = atual->prox;
    }
    return nova;
}

// Ex 4
float MediaValores(Lista *lista) {
    if (lista->tamanho == 0) return 0.0f;

    float soma = 0;
    Tlista *atual = lista->inicio;
    while (atual != NULL) {
        soma += atual->dados.valor;
        atual = atual->prox;
    }
    return soma / lista->tamanho;
}


// Ex 5
int ContarPrimos(Lista *lista) {
    int cont = 0, i = 0;
    Tlista *atual = lista->inicio;
    while (atual != NULL) {
        i++
        if (atual->dados.valor % i == 0) cont++;
        atual = atual->prox;
    }
    return cont;
}

