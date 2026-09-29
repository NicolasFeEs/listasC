/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usuário e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfabética. Utilize o algoritmo de ordenação que preferir.
 * O programa deve desconsiderar a diferença entre letras maíusculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

void bubbleSort(char arr[], int tamanho) {
    char a;
    for(int i = tamanho - 1; i > -1; i--){
        for (int j = 0; j < i ; j++){
            if (tolower(arr[j]) > tolower(arr[j+1])){
                a = tolower(arr[j]);
                arr[j] = tolower(arr[j+1]);
                arr[j+1] = a;
            }
        }
    }
}

int main (int argc, char *argv[]){
    char str[MAX];
    printf("digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    bubbleSort(str, strlen(str));
    printf("%s", str);
  return 0;
}
