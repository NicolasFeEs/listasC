
#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

void ExibirArestas (Grafo g)
{
    int i, j, a;
    printf("\nPeso da Aresta:\n");
    a = 65;
    for (i=0; i<g.nVertices; i++)
        for (j=0; j<g.nVertices; j++)
            if (PesoDaAresta(g, i, j) != 0)
                printf("Aresta %c%i,%i%c: w(%c)=%.1f\n",
                       g.digrafo==0?'{':'(',
                       i, j,
                       g.digrafo==0?'}':')',
                       a++,
                       PesoDaAresta(g, i, j)
                      );
    printf ("\n");
}

void ExibirGrafo (Grafo g)
{
    int i, j;
    // Troque por CLS se estiver usando Windows
    system("cls");


    printf ("Numero de vertices do %s: %i\n", g.digrafo==0?"GRAFO":"DIGRAFO",g.nVertices);
    for (i=0; i <g.nVertices; i++)
    {
        for (j=0; j < g.nVertices; j++)
            printf ("%0.1f   ", PesoDaAresta (g, i, j));
        printf ("\n");
    }
    printf ("\n");
}

void CriarGrafo (Grafo *g, int n, int dig)
{
    int i, j;
    g->nVertices = n;
    g->digrafo = dig;
    for (i=0; i < g->nVertices; i++)
        for (j=0; j < g->nVertices; j++)
            g->Pesos[i][j] = 0;
}


void InserirAresta (Grafo *g, int de, int para, float peso)
{
    g->Pesos[de][para] = peso;
    if (!g->digrafo)
        g->Pesos[para][de] = peso;
}


void RemoverAresta (Grafo *g, int de, int para)
{
    g->Pesos[de][para] = 0;
    if (!g->digrafo)
        g->Pesos[para][de] = 0;
}


float PesoDaAresta (Grafo g, int de, int para)
{
    return g.Pesos[de][para];
}


int GrauDeEntrada (Grafo g, int v)
{
    int i, grau = 0;
    for (i=0; i < g.nVertices; i++)
        if (PesoDaAresta(g, i, v) != 0)
            grau++;
    return grau;
}


int GrauDeSaida (Grafo g, int v)
{
    int j, grau = 0;
    for (j=0; j < g.nVertices; j++)
        if (PesoDaAresta(g, v, j) != 0)
            grau++;
    return grau;
}


int Vertedouro (Grafo g, int v)
{
    return GrauDeEntrada(g, v) == 0;
}


int Sorvedouro (Grafo g, int v)
{
    return GrauDeSaida(g, v) == 0;
}


int Adjacente (Grafo g, int de, int para)
{
    return PesoDaAresta(g, de, para) != 0;
}


void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT])
{
    int i, j, k;

    for (i=0; i < g.nVertices; i++)
        for (j=0; j < g.nVertices; j++)
            w[i][j] = Adjacente(g, i, j) ? 1 : 0;

    for (k=0; k < g.nVertices; k++)
        for (i=0; i < g.nVertices; i++)
            for (j=0; j < g.nVertices; j++)
                if (w[i][k] && w[k][j])
                    w[i][j] = 1;
}


int Alcanca (Grafo g, int de, int para)
{
    int w[MAX_VERT][MAX_VERT];
    Warshall(g, w);
    return w[de][para];
}


float PesoDoPasseio (Grafo g, ListaDeVertices p)
{
    int i, de, para;
    float soma = 0;

    for (i=0; i < p.nVertices - 1; i++)
    {
        de = p.vertices[i];
        para = p.vertices[i+1];

        if (!Adjacente(g, de, para))
            return -1;

        soma += PesoDaAresta(g, de, para);
    }

    return soma;
}

