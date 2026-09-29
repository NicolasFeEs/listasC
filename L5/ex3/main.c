/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, solicite ao usuário que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usuário se o caractere foi
 * encontrado ou não. O programa deve desconsiderar a difereça entre maíusculas
 * e minúsculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b não foi encontrado.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[]){
    char str[MAX], chave;
    int pos = -1;
    printf("digite uma string:");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("digite a chave: ");
    setbuf(stdin, 0);
    scanf("%c", &chave);
    chave = tolower(chave);
    for (int i = 0; i < strlen(str); i++){
        if (chave == tolower(str[i])){
            pos = i;
            printf("caractere %c encontrado na posicao %i", chave, pos);
        }
    }
    if (pos == -1)
        printf("caractere %c nao foi encontrado", chave);
  return 0;
}
