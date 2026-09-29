#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int op;
float resultado, a, b;
void menu(){
    printf("***calculadora***\nselecione uma das opcoes:\n1 - soma\n2 - subtracao\n3 - multiplicacao\n4 - divisao\n5 - raiz n\n6 - x elevado a n\n7 - seno\n8 - cosseno\n-1 - sair\n");
    scanf("%i", &op);
}
void soma(){
    printf("soma:\n");
    printf("digite a soma (a+b):");
    scanf("%f+%f", &a, &b);
    resultado = a + b;
    printf("%.2f + %.2f = %.2f\n\n", a, b, resultado);
}
void subtracao(){
    printf("subtracao:\n");
    printf("digite a soma (a-b):");
    scanf("%f-%f", &a, &b);
    resultado = a - b;
    printf("%.2f - %.2f = %.2f\n\n", a, b, resultado);
}
void multiplicacao(){
    printf("multiplicacao:\n");
    printf("digite a soma (a*b):");
    scanf("%f*%f", &a, &b);
    resultado = a * b;
    printf("%.2f * %.2f = %.2f\n\n", a, b, resultado);
    }
void divisao(){
    printf("divisao:\n");
    printf("digite a soma (a/b):");
    scanf("%f/%f", &a, &b);
    if (b != 0){
        resultado = a / b;
        printf("%.2f / %.2f = %.2f\n\n", a, b, resultado);}
    else
        printf("erro matematico\n\n");
}
void raiz_n(){
    printf("raiz de n:\n");
    printf("digite dois valores (a r b):");
    scanf("%f r %f", &a, &b);
    if (a >= 0){
        resultado = pow(a, 1/b);
        printf("%.2f r %.2f = %.2f\n\n", a, b, resultado);}
    else{
        a = fabs(a);
        resultado = pow(a, 1/b);
        printf("%.2f r %.2f = %.2fi\n\n", a, b, resultado);}
}
void potencia_n(){
    printf("x elevado a n");
    printf("digite dois valores (a^b):");
    scanf("%f^%f", &a, &b);
    resultado = pow(a, b);
    printf("%.2f ^ %.2f = %.2f\n\n", a, b, resultado);
}
void seno(){
    printf("seno de um angulo");
    printf("digite o valor em graus:");
    scanf("%f", &a);
    b = a * (M_PI / 180.0);
    resultado = sin(b);
    printf("seno(%.2f) = %.2f\n\n", a, resultado);
}
void cosseno(){
    printf("cosseno de um angulo");
    printf("digite o valor em graus:");
    scanf("%f", &a);
    b = a * (M_PI / 180.0);
    resultado = cos(b);
    printf("cos(%.2f) = %.2f\n\n", a, resultado);
}


void main (){
    do {
    menu();
    switch (op){
    case -1:
        printf("Saindo...");
        break;
    case 1:
        soma();
        break;
    case 2:
        subtracao();
        break;
    case 3:
        multiplicacao();
        break;
    case 4:
        divisao();
        break;
    case 5:
        raiz_n();
        break;
    case 6:
        potencia_n();
        break;
    case 7:
        seno();
        break;
    case 8:
        cosseno();
        break;
    default:
        printf("opcao invalida tente novamente: \n");
    }
    }while (op != -1);
}
