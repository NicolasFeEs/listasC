#ifndef LISTA_H
#define LISTA_H
typedef struct {
    int codProd;        // codigo do produto
    char nomeProd[10];  // nome do produto
    float valor;        // valor do produto
    int qtdeEstoque;    // quantidade disponivel em estoque
    int valor;
} Dados;

int BuscarMenorValor(Lista *lista, int *codProd, char *nomeProd, float *valor, int *qtdeEstoque);

void ExibirLista(Lista *lista);

int Pares(Lista *lista);       // Exercicio 2
Lista ListaPares(Lista *lista);   // Exercicio 3
float MediaValores(Lista *lista);    // Exercicio 4
int ContarPrimos(Lista *lista);      // Exercicio 5




#endif // LISTA_H_INCLUDED
