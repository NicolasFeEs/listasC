/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings.
 * O array deve ser ordenado alfabéticamente e, a seguir, exibido utilizando o
 * procedimento exibe_nomes fornecido. A quantidade de nomes digitado deve ser
 * sempre 5 (definido por MAX_NOMES). O programa deve desconsiderar a diferença
 * entre letras maiúsculas e minúsculas.
 *
 * Dica: pesquise pela função strtok
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['alexandre', 'diego', 'julio', 'nicola', 'tiririca']
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['ana julia', 'joao', 'marco antonio', 'matheus', 'victoria']
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOMES 5 // Valor máximo para o tamanho do array. Não modifique.
#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_nomes(char nomes[MAX_NOMES][MAX]);
void bubbleSort(char arr[MAX_NOMES][MAX], int tamanho) {
    char aux[MAX];
    for(int i = tamanho - 1; i > -1; i--){
        for (int j = 0; j < i ; j++){
            if (arr[j][0] > arr[j+1][0]){
            strcpy(aux, arr[j]);
            strcpy(arr[j], arr[j+1]);
            strcpy(arr[j+1], aux);
            }
        }
    }
}


int main (int argc, char *argv[]){
    char nomes[MAX_NOMES][MAX], str[MAX];
    char *token;
    int i = 0;
    printf("digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int j = 0; j < strlen(str); j++)
        str[j] = tolower(str[j]);
    token = strtok(str, ",");
    while (token != NULL && i < MAX_NOMES){
        strcpy(nomes[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    bubbleSort(nomes, MAX_NOMES);
    exibe_nomes(nomes);
  return 0;
}

void exibe_nomes(char nomes[MAX_NOMES][MAX]) {
  printf("[");
  for(int i = 0; i < MAX_NOMES; ++i) {
    printf("'%s'", nomes[i]);
    if( i != MAX_NOMES - 1 ) printf(", ");
  }
  printf("]\n");
}
