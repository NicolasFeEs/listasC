#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Faça um programa que receba um número inteiro digitado pelo
 * usuário e retorna se o número é par ou ímpar.
 *
 * Exemplos:
 *
 * Digite um numero: 5
 * Impar
 *
 * Digite um numero: 4
 * Par
 */

int main ()
{
    int a;
    printf("digite um numero:");
    scanf("%i", &a);
    a = a % 2;
    switch (a){
        case 0:
            printf("o numero e par");
            break;
        case 1:
            printf("o numero e impar");
            break;
    }
    return 0;
}
