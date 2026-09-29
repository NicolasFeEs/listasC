//Nicolas Ferreira Escobar Ra: 25.00378-1
//Pedro Oikawa Martins Oliveira R.A: 25.01632-0

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

#define N_LOCAIS 10
#define TAM_NOME 30
#define SAIDA_1 0  /* Portaria */
#define SAIDA_2 9  /* Estacionamento */

char nomesLocais[N_LOCAIS][TAM_NOME] = {
    "Portaria",
    "Biblioteca",
    "Bloco A",
    "Laboratorio",
    "Cantina",
    "Praca Central",
    "Auditorio",
    "Bloco B",
    "Quadra",
    "Estacionamento"
};

void exibirLocais(void);
int existeRota(Grafo g, int origem, int destino);
int saidaMaisProxima(Grafo g, int origem, int saida1, int saida2, int *distancia);
void mostrarRota(Grafo g, int origem, int destino);
void consultarEvacuacao(Grafo g, int origem, int saida1, int saida2);
void interditarPassagem(Grafo *g, int v1, int v2);
void liberarPassagem(Grafo *g, int v1, int v2);


int main(void){
    Grafo g;
    int opcao, temp;
    int origem;
    int v1, v2;
    int interditado1 = -1;
    int interditado2 = -1;

    /* MODELAGEM DO GRAFO */
    CriarGrafo(&g, N_LOCAIS, 0);

    InserirAresta(&g,0,1,1 );
    InserirAresta(&g,1,2,1 );
    InserirAresta(&g,2,3,1 );
    InserirAresta(&g,3,4,1 );
    InserirAresta(&g,4,5,1 );
    InserirAresta(&g,5,6,1 );
    InserirAresta(&g,6,7,1 );
    InserirAresta(&g,7,8,1 );
    InserirAresta(&g,8,4,1 );
    InserirAresta(&g,9,6,1 );
    InserirAresta(&g,9,0,1 );
    InserirAresta(&g,5,7,1 );
    InserirAresta(&g,7,4,1 );
    InserirAresta(&g,0,5,1 );
    InserirAresta(&g,1,5,1 );
    InserirAresta(&g,5,2,1 );


    /* FIM MODELAGEM DO GRAFO */

    do {
        printf("\nSISTEMA DE ROTAS DE EVACUACAO\n\n");
        printf("1 - Exibir locais do campus\n");
        printf("2 - Consultar rota de evacuacao\n");
        printf("3 - Interditar passagem\n");
        printf("4 - Liberar passagem\n");
        printf("0 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            exibirLocais();
            break;

        case 2:
            exibirLocais();
            printf("\nInforme o local de origem: ");
            scanf("%d", &origem);
            consultarEvacuacao(g, origem, SAIDA_1, SAIDA_2);
            break;

        case 3:
            exibirLocais();
            printf("\nPrimeiro local: ");
            scanf("%d", &v1);
            printf("Segundo local: ");
            scanf("%d", &v2);
            if (interditado1 != -1){
                printf("ja existe uma passagem interditada");
                break;
            }
            interditarPassagem(&g, v1, v2);
            interditado1 = v1;
            interditado2 = v2;
            break;

        case 4:
            if (interditado1 != -1) {
                liberarPassagem(&g, interditado1, interditado2);
                interditado1 = -1;
                interditado2 = -1;
            } else {
                printf("\nNao ha passagem interditada.\n");
            }
            break;

        case 0:
            printf("\nPrograma encerrado.\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

void exibirLocais(void){
    int i;

    printf("\nLOCAIS DO CAMPUS\n\n");
    for (i = 0; i < N_LOCAIS; i++)
        printf("%d - %s\n", i, nomesLocais[i]);
}

int existeRota(Grafo g, int origem, int destino){
    float dist = 0;
    ListaDeVertices caminho[N_LOCAIS];
    BFS(g, origem, destino, &dist, &caminho);
    return dist != 0;
    }

int saidaMaisProxima(Grafo g, int origem, int saida1, int saida2, int *distancia){
    float dist1[N_LOCAIS], dist2[N_LOCAIS];
    printf("teste3");
    ListaDeVertices caminho1[N_LOCAIS], caminho2[N_LOCAIS];
    BFS(g, origem, saida1, &dist1, &caminho1);
    BFS(g, origem, saida2, &dist2, &caminho2);
    if(dist1 == 0 && dist2==0)
        return -1;
    if (dist1<=dist2){
    distancia = (int) dist1[];
    printf("teste4");
    return saida1;
    }
    if(dist1>dist2){
        printf("teste4.5");
        distancia = (int) dist2[];
        printf("teste5");
        return saida2;}
}

void mostrarRota(Grafo g, int origem, int destino){
    float dist = 0;
    int aux;
    ListaDeVertices caminho[N_LOCAIS];
    BFS(g, origem, destino, &dist, &caminho);
    for(int i = dist; i != 0; i--){
        aux = caminho->vertices[i];
        printf("%s->", nomesLocais[aux][TAM_NOME]);
    }
    printf("\b\b");
}

void consultarEvacuacao(Grafo g, int origem, int saida1, int saida2){
    int distancia;
    printf("teste1");
    int saida;
    saida = saidaMaisProxima(g, origem, saida1, saida2, &distancia);
    printf("\n\n saida: %i, distancia%i", saida, distancia);
    if(saida != -1){
        printf("teste2");
        printf("CONSULTA DE EVACUACAO\n\nOrigem:%s\n\nSaida:%s\nDistancia:%i", nomesLocais[origem][TAM_NOME], nomesLocais[saida][TAM_NOME], distancia);
        mostrarRota(g, origem, saida);
    }
    else
        printf("CONSULTA DE EVACUACAO\nOrigem:%s\n\nNao existe rota de evacuacao", nomesLocais[origem][TAM_NOME]);
}

void interditarPassagem(Grafo *g, int v1, int v2){
     RemoverAresta(g, v1, v2);
}

void liberarPassagem(Grafo *g, int v1, int v2){
    InserirAresta(g, v1, v2, 1);
}
