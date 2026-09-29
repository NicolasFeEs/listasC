#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Faça um programa que leia um numero inteiro positivo par e,
 * a seguir, exiba todos os numeros pares de 0 ate o numero digitado em ordem
 * crescente, separados apenas por um espaco.
 *
 * Exemplos:
 *
 * Numero: 5
 * Digite um numero par!
 *
 * Numero: -5
 * Digite um numero positivo!
 *
 * Numero: 6
 * 0 2 4 6
 *
 * Numero: 14
 * 0 2 4 6 8 10 12 14
 */

int main()
{
    int a, b;
    printf("Digite um numero:");
    scanf("%i",&a);
    if (a % 2 == 0 && a >= 0)
        for (b = 0; b <= a; b += 2){
            printf("%i ", b);
        }
    else
        if (a % 2 != 0)
            printf("digite um numero par");
        else
            printf("digite um numero positivo");
    return 0;
}
