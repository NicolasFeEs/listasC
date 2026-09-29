/* Enunciado:
 *  Desenvolva um programa capaz de ler os valores de uma matriz m x n.
 *  A leitura deve ser feita em uma linha para cada linha da matriz (ver ex1).
 *  A condição de parada para a leitura das linhas é uma linha vazia
 *  (apenas com -100). O programa deve assumir que a quantidade de colunas
 *  da primeira linha define a dimensão da matriz, ou seja, qualquer linha
 *  subsequente que não tenha a mesma quantidade de linhas da linha inicial
 *  deve causar um erro e o encerramento do programa. Após a leitura da matriz,
 *  ela deve ser exibida seguindo o padrão mostrado nos exemplos a seguir.
 *
 *  Exemplos:
 *
 *   Linha 0: 1 1 1 -100
 *   Linha 1: 2 2 2 -100
 *   Linha 2: 3 3 3 -100
 *   Linha 3: -100
 *   [[1, 1, 1],
 *   [2, 2, 2],
 *   [3, 3, 3]]
 *
 *   Linha 0: 1 1 1 1 1 -100
 *   Linha 1: 1 2 3 -100
 *   Número de colunas incompatível. Saindo...
 *
 *   Linha 0: 1 2 3 4 5 6 7 8 -100
 *   Linha 1: 8 7 6 5 4 3 2 1 -100
 *   Linha 2: -100
 *   [[1, 2, 3, 4, 5, 6, 7, 8],
 *   [8, 7, 6, 5, 4, 3, 2, 1]]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

int main()
{
    int nl = -1, nc, e, f = 0, l, c;
    int Ar [ARRAY_MAX][ARRAY_MAX];
    do{
        nl++;
        printf("linha %i: ", nl);
        nc = 0;
        e = 0;
        while (e!=-100){
            scanf("%i", &e);
            if (e != -100){
            Ar[nl][nc] = e;
            nc++;
            }
            else{
                if (nl == 0)
                    f = nc;
                if (f != nc)
                    if (nc != 0)
                        f = -99; // flag para comparar com o ultimo numero de colunas
            }
        }
    }while((nc != 0 || e != -100)&& f != -99);
    if (f == -99)
        printf("numero de colunas incompativel");
    else{
        printf("[");
        for (l = 0; l < nl; l++){
            printf("[");
            for(c = 0; c < f; c++){
                printf("%i, ", Ar[l][c]);
            }
            if (l < nl-1)
                printf("\b\b],\n");
        }
        printf("\b\b]]");
    }


    return 0;
}
