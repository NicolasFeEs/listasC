#include <stdio.h>
#include <stdlib.h>
/* Enunciado:
 *
 * Elabore um programa que receba um valor inteiro de 6 digitos do usuario
 * e, em seguida, exiba uma versao binaria falsa desse numero. Para calcular
 * a versao binaria falsa, verifique cada um dos digitos do numero e, se o
 * digito for maior ou igual a 5, transforme-o em 1, se for menor, transforme-o
 * em 0.
 *
 *
 * Ex:
 *     Digite um numero: 123456
 *     000011
 *
 *     Digite um numero: 583910
 *     110100
 *
 *     Digite um numero: 830209
 *     100001
 *
 * DICA: Lembre-se das ferramentas de quebra de fluxo que tinhamos em Python.
 * Como usa-las em C? Pesquise!
 *
 */

int main (int argc, char *argv[])
{
    int n, a, b, c, d, e;
    printf("digite um numero:");
    scanf("%i", &n);
    a = n / 500000;
    n = n - (n / 100000)*100000;
    b = n / 50000;
    n = n - (n / 10000)*10000;
    c = n / 5000;
    n = n - (n / 1000)*1000;
    d = n / 500;
    n = n - (n / 100)*100;
    e = n / 50;
    n = n - (n / 10)*10;
    n = n / 5;
    printf("%i%i%i%i%i%i", a, b, c, d, e, n);
    //deve ter um jeito melhor de fazer isso


  return 0;
}
