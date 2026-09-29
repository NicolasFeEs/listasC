/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, ler um intervalo separado por vírgula que deve ser utilizado para
 * gerar uma substring que começa no começo do intervalo digitado e termina no
 * índice final (intervalo fechado).
 *
 * Exemplos:
 *
 * Digite uma string: Oi, eu sou o Goku!
 * Intervalo: 0, 9
 * Oi, eu sou
 *
 * Digite uma string: 0123456789
 * Intervalo: 3,7
 * 34567
 *
 * Digite uma string: Estruturas de Dados
 * Intervalo: 3, 12
 * ruturas de
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[]){
    char str[MAX], aux[MAX];
    int in, f, j = 0;
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Intervalo: ");
    scanf("%i,%i", &in, &f);
    int tamanho = strlen(str);
    if (in < 0 || f >= tamanho || in > f)
        printf("Intervalo invalido\n");
    else{
        for (int i = in; i < f + 1; i++){
                aux[j] = str[i];
                j++;}
        aux[j] = '\0'
        printf("%s", aux);}


  return 0;
}
