/* Enunciado: Desenvolva um programa capaz de ler n valores inteiros e os
 *  insira em um array. A leitura deve ser feita em uma única linha, separando
 *  os valores por espaço. A leitura deve ser encerrada quando um
 *  valor -100 é lido. Após a leitura ser realizada, o programa deve utilizar
 *  o procedimento exibe_array para exibir o array em uma única linha
 *  e entre colchetes.
 *
 *  Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 8 -100
 *    [1, 2, 3, 4, 5, 6, 7, 8]
 *
 *    Digite os valores para o array: 1 2 3 4 -100
 *    [1, 2, 3, 4]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_array(int array[], int tam_array){
    printf("[");
    for (int i = 0; i<tam_array; i++){
        printf("%i, ", array[i]);
    }
    printf("\b\b]");
}

int main()
{
    int valores[ARRAY_MAX];
    int e = 0, nv=0;

    printf("digite os valores para o array: ");

    while (e != -100){
        scanf("%i", &e);
        if (e != -100){
        valores[nv] = e;
        nv++;}}
    exibe_array(valores, nv);
    return 0;
}
