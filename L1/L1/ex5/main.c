#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero de 5 digitos e, em seguida, exiba
 * o numero digitado com os digitos invertidos.
 *
 * Ex:
 *      Digite um numero: 54321
 *      12345
 *
 *      Digite um numero: 38271
 *      17283
 *
 */

int main (int argc, char *argv[])
{
  int a, b, c, d, e;
  printf("Digite um numero: ");
  scanf("%i", &a);
  b = a/10000;
  a = a - b*10000;

  c = a /  1000;
  a = a - c*1000;

  d  = a /  100;
  a = a - d*100;

  e = a /  10;
  a = a - e*10;

  printf("%i%i%i%i%i",a ,e ,d , c, b);

  return 0;
}
