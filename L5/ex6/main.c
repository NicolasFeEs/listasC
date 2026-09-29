/*
 * Enunciado:
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usuário e,
 * a seguir, deve informá-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferença entre letras maíusculas e letras minúsculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored é anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored não é anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi não é anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi é anagrama de ioo
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
    char str_1[MAX], str_2[MAX], aux_1[MAX], aux_2[MAX];
    int tamanho_1, tamanho_2;
    printf("digite uma string: ");
    fgets(str_1, MAX, stdin);
    str_1[strcspn(str_1, "\n")] = '\0';
    tamanho_1 = strlen(str_1);
    strcpy(aux_1, str_1);
    printf("digite uma string: ");
    fgets(str_2, MAX, stdin);
    str_2[strcspn(str_2, "\n")] = '\0';
    tamanho_2 = strlen(str_2);
    strcpy(aux_2, str_2);
    if (tamanho_1 != tamanho_2)
        printf("%s nao e um anagrama de %s", str_1, str_2);
    else{
        bubbleSort(str_1, tamanho_1);
        bubbleSort(str_2, tamanho_2);
        if (strcmp(str_1,str_2) == 0)
            printf("%s e um anagrama de %s", aux_1, aux_2);
        else
            printf("%s nao e um anagrama de %s", aux_1, aux_2);
    }

  return 0;
}
