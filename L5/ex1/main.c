/*
 * Enunciado:
 *  Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 *  a seguir, exiba essa string invertida.
 *
 *  Exemplo:
 *    Digite uma string: ola
 *    alo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[]){
    char str[MAX];
    printf("digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = strlen(str); i > 0; i--)
        printf("%c", str[i]);

  return 0;
}
