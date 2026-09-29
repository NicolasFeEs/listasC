/*
 * Enunciado:
 * Desenvolva um programa capaz de ler n valores inteiros e os insira em um
 * array. A leitura deve ser feita de acordo com o programa feito no ex1.
 * Após a leitura, desenvolva a função calcula_media e calcula_dvp
 * para calcular a média e o desvio padrão dos valores informados.
 * O programa principal deve receber os valores lidos pelo array e retornar a
 * média e o desvio padrão no seguinte formato: MÉDIA +- DVP
 *
 * Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 -100
 *    4.00 +- 2.0
 *
 *    Digite os valores para o array: 1 1 1 1 1 1 1 1 1 1 1 -100
 *    1.00 +- 0.0
 *
 *    Digite os valores para o array: 10 20 1 40 50 90 100 -100
 *    44.43 +- 35.6
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // A biblioteca math tem pow e sqrt

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
float calcula_media(int array[], int tam_array);
float calcula_dvp(int array[], int tam_array);

int main()
{
    int valores[ARRAY_MAX];
    int e = 0, nv=0;
    float m, dv;

    printf("digite os valores para o array: ");

    while (e != -100){
        scanf("%i", &e);
        if (e != -100){
        valores[nv] = e;
        nv++;}}
    m = calcula_media(valores, nv);
    dv = calcula_dvp(valores, nv);
    printf("%.2f +- %.1f", m, dv);
    return 0;
}

/* Implementação das Funções */
float calcula_media(int array[], int tam_array) {
    float media;
    for (int i = 0; i<tam_array; i++){
    media += (float)array[i]/tam_array;}
    return media;
}

float calcula_dvp(int array[], int tam_array) {
    float desvio, somas=0, n;
    float m = calcula_media(array, tam_array);
    for (int i = 0; i<tam_array; i++){
        n = array[i];
        somas += pow(n - m, 2);
    }
    desvio = sqrt(somas/tam_array);
    return desvio;
}
