#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Em matemática, o número harmônico designado por H(n) define-se
 * como sendo a soma da série harmônica:
 *
 *                         H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
 *
 * Faça um programa que leia um valor n inteiro e positivo e
 * apresente o valor de H(n) com duas casas decimais
 *
 * Exemplos:
 *
 * Digite um valor para n: 10
 * 2.93
 *
 * Digite um valor para n: -1
 * Erro, n menor que 0!
 */

int main()
{
    int a;
    float b, Hn = 0;
    printf("Digite um valor para n:");
    scanf("%i",&a);
    if (a > 0){
        for (b = 1; b <= a; b++){
            Hn = Hn + 1/b;
        }
        printf("%.2f", Hn);}
    else
        if (a == 0)
            printf("soma nula!");
        else
            printf("erro, n menor que 0");
    return 0;
}
