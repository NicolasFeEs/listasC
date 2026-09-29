/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de duas matriz 3x3
 * e, a seguir, exiba a matriz resultante da multiplicação entre elas.
 *
 * Exemplos:
 *
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[1, 1, 1],
 *    [2, 2, 2],
 *    [3, 3, 3]]
 *
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[14, 14, 14],
 *    [32, 32, 32],
 *    [50, 50, 50]]
 *
 *    Digite a linha 0: 2 0 0
 *    Digite a linha 1: 0 2 0
 *    Digite a linha 2: 0 0 2
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[2, 2, 2],
 *    [4, 4, 4],
 *    [6, 6, 6]]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.
void recebermatriz(int matriz[ARRAY_MAX][ARRAY_MAX]);

int main()
{
    printf("matriz 1\n");
    int matriz1[ARRAY_MAX][ARRAY_MAX];
    recebermatriz(matriz1);

    printf("matriz 2\n");
    int matriz2[ARRAY_MAX][ARRAY_MAX];
    recebermatriz(matriz2);

    int matriz3[ARRAY_MAX][ARRAY_MAX];

    for (int l = 0; l < ARRAY_MAX; l++){
        for (int c = 0; c < ARRAY_MAX; c++){
                int vc = 0;
                for (int sub = 0; sub < ARRAY_MAX; sub++){
                        vc += matriz1[l][sub]*matriz2[sub][l];
                }
                matriz3[c][l]= vc;
            }
        }
    printf("[");
    for (int l = 0; l < ARRAY_MAX; l++){
            printf("[");
        for (int c = 0; c < ARRAY_MAX; c++){
                printf("%i, ", matriz3[c][l]);
        }
        printf("\b\b]");
        if (l < ARRAY_MAX-1)
            printf("\n");
    }
    printf("]");

    return 0;
}

void recebermatriz(int matrizgen[ARRAY_MAX][ARRAY_MAX]){
    for (int l = 0; l < ARRAY_MAX; l++){
        printf("digite a linha %i: ", l);
        for (int c = 0; c < ARRAY_MAX; c++){
            scanf("%i", &matrizgen[l][c]);
        }
    }
}
