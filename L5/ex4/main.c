/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, implemente a estratégia de criptografia ZENIT - POLAR.
 * A estratégia em questão consiste em substituir os caracteres da string
 * da seguinte maneira:
 *
 *            Z <-> P
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferença entre letras maíusculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[]){
    char str[MAX], aux[MAX];
    printf("digite uma string: ");
    fgets(str, MAX, stdin);
    aux[strcspn(str, "\n")] = '\0';
    for (int i = 0; i < strlen(str), i++){
        switch(str[i]){
    case 'p':
        aux[i] = 'z';
        break;
    case 'o':
        aux[i] = 'e';
        break;
    case 'l':
        aux[i] = 'n';
        break;
    case 'a':
        aux[i] = 'i';
        break;
    case 'r':
        aux[i] = 't';
        break;
    case 'z':
        aux[i] = 'p';
        break;
    case 'e':
        aux[i] = 'o';
        break;
    case 'n':
        aux[i] = 'l';
        break;
    case 'i':
        aux[i] = 'a';
        break;
    case 't':
        aux[i] = 'r';
        break;}}

    printf("%s", aux);
  return 0;
}
