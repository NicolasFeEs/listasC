/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, exibir o maior palíndromo possível dentro da string digitada.
 * Caso não haja nenhum palíndromo possível, o programa deve alertar o usuário.
 * O programa deve desconsiderar diferenças entre letras minúsculas e letras
 * maiúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: tiririca
 *   iriri
 *
 *   Digite uma string: I have a racecar
 *   racecar
 *
 *   Digite uma string: Cuidado com o Diego
 *   dad
 *
 *   Digite uma string: Alexandre
 *   Não existe nenhum palíndromo possível
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void ler_string(char s[MAX]){
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = '\0';
}
void to_lower_string(char s[MAX]){
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = tolower(s[i]);
}
void substring(char destino[MAX], char origem[MAX], int comeco, int fim){
    int j = 0;
    for (int i = comeco; i <= fim; i++){
        destino[j++] = origem[i];
    }
    destino[j] = '\0';
}
int verifica_palindromo(char s[MAX]){
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j){
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
void maior_palindromo(char s[MAX], char resultado[MAX]){
    char temp[MAX];
    int tamanho = strlen(s);
    int maior = 0;
    resultado[0] = '\0';
    for (int i = 0; i < tamanho; i++){
        for (int j = i; j < tamanho; j++){
            substring(temp, s, i, j);

            if (verifica_palindromo(temp)){
                int tam = strlen(temp);
                if (tam > maior){
                    maior = tam;
                    strcpy(resultado, temp);
                }
            }
        }
    }
}
int main (){
    char str[MAX], resultado[MAX], original[MAX];
    printf("Digite uma string: ");
    ler_string(str);
    strcpy(original, str);
    to_lower_string(str);
    maior_palindromo(str, resultado);
    if (strlen(resultado) > 1)
        printf("%s\n", resultado);
    else
        printf("Nao existe nenhum palindromo possivel\n");

    return 0;
}
