#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Faça um programa que calcula a associação em paralelo
 * de dois resistores R1 e R2 fornecidos pelo usuário via teclado e retorna seu valor com duas casas decimais.
 * O programa deverá solicitar valores e calcular a resistência equivalente até
 * que o usuário entre com um valor para alguma das resistências igual a 0
 *
 * Exemplos:
 *
 * Digite um valor para R1: 470
 * Digite um valor para R2: 2200
 * Resistencia equivalente em paralelo: 387.27
 *
 * Digite um valor para R1: 0
 * Digite um valor para R2: 100
 * Finalizando o programa!
*/

int main()
{
    int R1, R2;
    float Req;
    do{
        printf("digite um valor para R1: ");
        scanf("%i", &R1);
        printf("digite um valor para R2: ");
        scanf("%i", &R2);
        if (R1 > 0 && R2 > 0){
            Req = (float)R1 * R2/(R1 + R2);
            printf("Resistencia equivalente em paralelo: %.2f\n", Req);
        }
        if (R1 < 0 || R2 < 0)
            printf("erro, valor menor que 0\n");
    }while(R1 && R2 != 0);
    printf("Finalizando programa");
    return 0;
}
