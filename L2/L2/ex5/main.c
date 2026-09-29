#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Faça um programa que leia uma data no seguinte formato:
 * D/M/A. O programa deve determinar se a data digitada válida ou não.
 * Lembre-se que Fevereiro tem 29 dias em anos bissextos e 28 dias em anos não
 * bissextos.
 *
 * Exemplos:
 *
 * Data: 22/02/2022
 * Data valida!
 *
 * Data: 29/02/2020
 * Data valida!
 *
 * Data: 29/02/2022
 * Data invalida!
 *
 * Data: 31/06/2022
 * Data invalida!
 *
 * Data: 31/13/2022
 * Data invalida!
 */

int main()
{
    int d, m, a;
    printf("Data: ");
    scanf("%i/%i/%i",&d ,&m ,&a );
    if (a < 0)
        m = 0;
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (d < 1 || d > 31)
                printf("data invalida");
            else
                printf("data valida");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (d < 1 || d > 30)
                printf("data invalida");
            else
                printf("data valida");
            break;
        case 2:
            if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)){
                if (d < 1 || d > 29)
                    printf("data invalida");
                else
                    printf("data valida");}
            else {
                if (d < 1 || d > 28)
                    printf("data invalida");
                else
                    printf("data valida");
            }

            break;
        default:
            printf("data invalida");
            break;

    }
    return 0;
}
