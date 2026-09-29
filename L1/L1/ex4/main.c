#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia dois numero inteiros
 * troque os valores entre as variáveis e os imprima
 *
 * Ex:
 *      Digite um numero: 5
 *      Digite um numero: 7
 *      7 5
 *
 */

int main (int argc, char *argv[])
{
  printf("Digite um numero: ");
  // Leitura do numero
  int a, b;
  scanf("%i",&a);
  printf("Digite um numero: ");
  scanf("%i",&b);
  // Resto do seu codigo
 printf("%i %i", b, a);

  return 0;
}
