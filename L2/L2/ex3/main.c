#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Faça um programa que receba um número inteiro e, a seguir,
 * exibe todos os seus possíveis divisores separados apenas por um espaço.
 *
 * Exemplos:
 *
 * Digite um numero: 7
 * 1 7
 *
 * Digite um numero: 12
 * 1 2 3 4 6 12
 */

int main()
{
    int a, b, c;
    printf("digite um numero:");
    scanf("%i", &a);
    for (b = 1; b < a; b++){
        c = a % b;
        if (c == 0)
            printf("%i ", b);
    }
    printf("%i", a);
    return 0;
}
