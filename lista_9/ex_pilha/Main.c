#include <stdio.h>
#include "pilha.h"

int main() {
    long numero;
    int base;

    printf("Digite um numero: ");
    scanf("%ld", &numero);

    printf("Digite a base desejada: ");
    scanf("%d", &base);

    if (numero <= 0 || base < 2 || base > 36) {
        printf("Valor invalido.\n");
        return 1;
    }

    char digitos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    Pilha p;
    InicializarPilha(&p);

    long numerador = numero;

    while (numerador > 0) {
        Dados d;
        d.valor = numerador % base;
        Empilhar(&p, d);
        numerador = numerador / base;
    }

    printf("%ld na base %d: ", numero, base);
    Dados d;
    while (Desempilhar(&p, &d)) {
        printf("%c", digitos[d.valor]);
    }
    printf("\n");

    return 0;
}
