#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Escreva um programa que leia um numero inteiro
 * e depois o exiba na tela
 *
 * Ex:
 *      Digite um numero: 5
 *      5
 *
 */

int main (int argc, char *argv[]){
  int a;
  printf("Digite um numero: ");
  // Seu codigo a partir daqui
  scanf("%i", &a);
  printf("o numero e %i", a);
  return 0;
}
