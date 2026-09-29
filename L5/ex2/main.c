/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, informe-o se o valor digitado se trata de um palíndromo ou não.
 * O programa deve descosiderar diferença entre maíusculas e minúsculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  É palíndromo
 *
 *  Digite uma string: oi
 *  Não é palíndromo
 *
 *  Digite uma string: RaceCar
 *  É palíndromo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[]){
    char str[MAX];
    int j = 0;
    printf("digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = strlen(str)-1; i > 0; i--){
        if (tolower(str[i]) != tolower(str[j])){
            printf("nao e palindromo");
            j = -5;
            break;
        }
        j++;
    }
    if (j != -5)
        printf("e palindromo");

  return 0;
}
