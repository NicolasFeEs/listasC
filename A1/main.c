//Nicolas Ferreira Escobar RA:25.00378-1
//Rafaella Bonutti  RA:25.00250-2
#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define TAM (MAX * MAX)

/* Protótipos das funções */
void geraMatriz(int m[][MAX]);
void exibeMatriz(int m[][MAX]);
void exibeVetor(int arr[], int tamanho);
int buscaLinear(int arr[][MAX], int tamanho, int valorBuscado);
int buscaBinaria(int arr[], int tamanho, int valorBuscado);

int main(){
    int matriz[MAX][MAX];
    int vetor[TAM];
    int v, i = 0;
    /* Geração automática da matriz */
    geraMatriz(matriz);

    printf("=== MATRIZ GERADA AUTOMATICAMENTE ===\n");
    exibeMatriz(matriz);

    /* =========================
       ETAPA 1 - BUSCA LINEAR
       ========================= */
    printf("=== ETAPA 1 - BUSCA LINEAR NA MATRIZ ===\ndigite o valor a ser buscado: ");
    scanf("%i", &v);
    buscaLinear(matriz, TAM, v);

    /* =========================
       CRIAÇÃO DO VETOR AUXILIAR
       ========================= */
    for (int l = 0; l < MAX; l++){
        for (int c = 0; c < MAX; c++){
          vetor[i]= matriz[l][c];
          i++;
        }
    }
    exibeVetor(vetor, TAM);


    /* =========================
       ETAPA 2 - BUSCA BINARIA
       ========================= */
    printf("\n=== ETAPA 2 - BUSCA BINARIA NA MATRIZ ===\ndigite o valor a ser buscado: ");
    scanf("%i", &v);
    buscaBinaria(vetor, TAM, v);

    return 0;
}

/* Gera automaticamente a matriz */
void geraMatriz(int m[][MAX]){
    int i, j;
    int valor = 1;

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            m[i][j] = valor;
            valor++;
        }
    }
}

/* Exibe a matriz */
void exibeMatriz(int m[][MAX]){
    printf("[");
    for (int l = 0; l < MAX; l++){
            printf("[");
        for (int c = 0; c < MAX; c++){
                printf("%i, ", m[l][c]);
        }
        printf("\b\b]");
        if (l < MAX-1)
            printf("\n");
    }
    printf("]\n");
}

/* Exibe o vetor */
void exibeVetor(int arr[], int tamanho){
    printf("\n[");
    for(int i = 0; i < tamanho; i++){
        printf("%i, ", arr[i]);
    }
    printf("\b\b]\n");
}

/* Busca linear */
int buscaLinear(int arr[][MAX], int tamanho, int valorBuscado){
    int encontrado = 0, l, c;
    for (l = 0; l < MAX; l++){
        for (c = 0; c < MAX; c++){
                if (arr[l][c]==valorBuscado){
                    encontrado = 1;
                    break;
                }
        }
        if (encontrado == 1)
            break;
    }
    if (encontrado == 1)
        printf("valor %i encontrado na matriz na posicao [%i][%i]", valorBuscado, l, c);
    else
        printf("valor %i nao esta na matriz", valorBuscado);
    return 0;
}

/* Busca binária */
int buscaBinaria(int arr[], int tamanho, int valorBuscado){
    int vmin = 0, l, c, encontrado, indice, espaco, meio;
    while (vmin < tamanho){
        espaco = tamanho - vmin;
        meio = espaco/2;
        indice = meio + vmin;
        if (valorBuscado == arr[indice]){
            encontrado = 1;
            break;}
        else{
            if (valorBuscado < arr[indice]){
                tamanho = indice;
                //printf("-"); //propositos de debug
            }
            else{
                vmin = indice;
                //printf("+"); //propositos de debug
                }
        }}
        if (encontrado == 1){
        printf("valor %i encontrado no vetor na posicao [%i]\n", valorBuscado, indice);
        l = indice / MAX;
        c = indice % MAX;
        printf("posicao equivalente na matriz: [%i][%i]", l, c);

        }
        else
            printf("valor %i nao esta na matriz", valorBuscado);

    return 0;
}



