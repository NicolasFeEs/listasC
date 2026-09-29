/* Enunciado:
 *   Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3
 *   e, a seguir, calcule e exiba sua determinante. O cálculo da determinante
 *   deve ser feito pela função determinante, que recebe por referência uma
 *   matriz 3x3 e retorna o valor inteiro referente à determinante.
 *
 *   Exemplos:
 *     Digite a linha 0: 2 3 4
 *     Digite a linha 1: 1 3 4
 *     Digite a linha 2: 5 6 7
 *     -3
 *
 *     Digite a linha 0: 1 0 0
 *     Digite a linha 1: 0 1 0
 *     Digite a linha 2: 0 0 1
 *     1
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int determinante(int matriz[ARRAY_MAX][ARRAY_MAX]);

int main()
{
    int Matriz[ARRAY_MAX][ARRAY_MAX];
    for (int l = 0; l < ARRAY_MAX; l++){
        printf("digite a linha %i: ", l);
        for (int c = 0; c < ARRAY_MAX; c++){
            scanf("%i", &Matriz[l][c]);
        }
    }
    int det = determinante(Matriz);
    printf("o determinante desta matriz e: %i", det);
    return 0;
}

/* Implementação das Funções */
int determinante(int matriz[ARRAY_MAX][ARRAY_MAX]) {
    int sub1, sub2, sub3, det;
    sub1 = matriz[0][0]*(matriz[1][1]*matriz[2][2]-matriz[1][2]*matriz[2][1]);
    sub2 = matriz[0][1]*(matriz[1][0]*matriz[2][2]-matriz[1][2]*matriz[2][0]);
    sub3 = matriz[0][2]*(matriz[1][0]*matriz[2][1]-matriz[1][1]*matriz[2][0]);
    det = sub1 + sub3 - sub2;
    return det;
}
