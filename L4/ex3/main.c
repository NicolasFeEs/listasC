/* Enunciado:
 *  Desenvolva um programa capaz de ler dois vetores com três elementos
 *  inteiros cada. A leitura deve ser feita em uma única linha para cada vetor,
 *  com os elementos separados por espaços. Após a leitura, o programa
 *  deve exibir o produto escalar entre os vetores digitados no formato
 *  exemplificado abaixo. O cálculo do produto escalar deve obrigatoriamente
 *  ser feito pela função produto_escalar, que recebe como referência os
 *  dois arrays e retorna um valor inteiro referente ao resultado do produto
 *  escalar.
 *
 *  Exemplos:
 *      Digite o primeiro array: 1 2 3
 *      Digite o segundo array: 3 2 1
 *      [1, 2, 3] . [3, 2, 1] = 10
 *
 *      Digite o primeiro array: 10 20 30
 *      Digite o segundo array: -10 2 5
 *      [10, 20, 30] . [-10, 2, 5] = 90
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
int produto_escalar(int array[], int array2[]);

int main()
{
    int A1[ARRAY_MAX];
    int A2 [ARRAY_MAX];
    int pe;
    printf("digite o primeiro array:");
    for (int i=0;i<ARRAY_MAX;i++){
        scanf("%i", &A1[i]);
    }
    printf("digite o segundo array:");
    for (int i=0;i<ARRAY_MAX;i++){
        scanf("%i", &A2[i]);
    }
    pe = produto_escalar(A1, A2);
    printf("[%i, %i, %i] . [%i, %i, %i] = %i",A1[0], A1[1], A1[2], A2[0], A2[1], A2[2], pe);

    return 0;
}

/* Implementação das Funções */
int produto_escalar(int array[], int array2[]) {
    int produto = 0;
    for (int i=0;i<ARRAY_MAX;i++)
        produto += array[i] * array2[i];
    return produto;
}
