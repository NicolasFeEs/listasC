#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia um valor monetario (int) a ser pago e retorne
 * a solucao otimizada para quantas notas de 50, 10 e 2 sao necessarias para
 * compor aquele valor monetario, alem do troco necessario.
 *
 * Formato da saida:
 *  N50: **qtd_50** N10: **qtd_10** N2: **qtd_2** T: **troco**
 *
 *
 * Ex:
 *      Total: 60
 *      N50: 1 N10: 1 N2: 0 T: 0
 *
 *      Total: 85
 *      N50: 1 N10: 3 N2: 2 T: 1
 *
 *      Total: 171
 *      N50: 3 N10: 2 N2: 0 T: 1
 *
 */

int main (int argc, char *argv[])
{
    int valor, N50, N20, N2, resto;
    printf("digite o valor:");
    scanf("%i", &valor);
    N50 = valor / 50;
    valor = valor - N50*50;
    N20 = valor / 20;
    valor = valor - N20*20;
    N2 = valor / 2;
    resto = valor % 2;
    printf("N50: %i N20: %i N2:%i resto: %i", N50, N20, N2, resto);

  return 0;
}
