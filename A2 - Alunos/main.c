#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define TOTAL (MAX * MAX)

/* Protótipos das funções */
void preencheMatriz(int m[][MAX]);
void exibeMatriz(int m[][MAX]);
void exibeVetor(int arr[], int tamanho);

void bubbleSort(int arr[], int tamanho);
void copiaMatrizParaVetor(int m[][MAX], int arr[]);
void copiaVetorParaMatriz(int arr[], int m[][MAX]);

int main() {
    int matriz[MAX][MAX];
    int vetor[TOTAL];
    int a;
    /* Inicializa gerador de números aleatórios */
    srand(time(NULL));

    /* Preenche a matriz com valores aleatórios */
    preencheMatriz(matriz);

    printf("\n=========== MATRIZ ORIGINAL ===========\n");
    exibeMatriz(matriz);

    /* Etapa 1 */
    for (int l = 0; l < MAX; l++){
        for(int i = MAX - 1; i > -1; i--){
            for (int j = 0; j < i; j++){
                if (matriz[l][j] > matriz[l][j+1]){
                    a = matriz[l][j];
                    matriz[l][j] = matriz[l][j+1];
                    matriz[l][j+1] = a;
                }
            }
        }
    }

    printf("\n===== MATRIZ APOS ORDENACAO DAS LINHAS =====\n");
    exibeMatriz(matriz);

    /* Etapa 2 */
    copiaMatrizParaVetor(matriz, vetor);
    exibeVetor(vetor, TOTAL);
    bubbleSort(vetor, TOTAL);

    printf("\n=========== VETOR ORDENADO ===========\n");
    exibeVetor(vetor, TOTAL);

    printf("\n===== MATRIZ TOTALMENTE ORDENADA =====\n");
    copiaVetorParaMatriz(vetor, matriz);
    exibeMatriz(matriz);
    return 0;
}

/* Preenche a matriz com valores aleatórios entre 0 e 999 */
void preencheMatriz(int m[][MAX]) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            m[i][j] = rand() % 1000;
        }
    }
}

/* Exibe a matriz */
void exibeMatriz(int m[][MAX]) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

/* Exibe o vetor */
void exibeVetor(int arr[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%4d ", arr[i]);

        /* Quebra de linha para melhor visualização */
        if ((i + 1) % 25 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}


void bubbleSort(int arr[], int tamanho) {
    int a;
    for(int i = tamanho - 1; i > -1; i--){
        for (int j = 0; j < i ; j++){
            if (arr[j] > arr[j+1]){
                a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }
}

void copiaMatrizParaVetor(int m[][MAX], int arr[]) {
    int i = 0;
    for (int l = 0; l < MAX; l++){
        for (int c = 0; c < MAX; c++){
          arr[i]= m[l][c];
          i++;
        }
    }
}

void copiaVetorParaMatriz(int arr[], int m[][MAX]) {
    int i = 0 ;
    for (int l = 0; l < MAX; l++){
        for (int c = 0; c < MAX; c++){
          m[l][c] = arr[i];
          i++;
        }
    }
}
