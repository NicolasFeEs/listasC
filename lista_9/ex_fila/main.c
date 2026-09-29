#include <stdio.h>
#include "fila.h"

//Ex8
void ExecutarExercicio8() {
    Fila fila1, fila2, fila3;
    InicializarFila(&fila1);
    InicializarFila(&fila2);

    int n1, n2;

    printf("Tamanho da fila 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        Dados d = {0};
        printf("Valor %d da fila 1: ", i + 1);
        scanf("%d", &d.valor);
        InserirNaLista(&fila1, d);
    }

    printf("Tamanho da fila 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        Dados d = {0};
        printf("Valor %d da fila 2: ", i + 1);
        scanf("%d", &d.valor);
        InserirNaLista(&fila2, d);
    }

    fila3 = IntercalarFilas(&fila1, &fila2);

    printf("\nFila 3 (intercalada): ");
    Dados d;
    while (!FilaVazia(&fila3)) {
        RemoverDaFila(&fila3, &d);
        printf("%d ", d.valor);
    }
    printf("\n");
}

//Ex9
void ExecutarExercicio9() {
    Fila time1, time2;
    InicializarFila(&time1);
    InicializarFila(&time2);

    int n1, n2;

    printf("Quantos jogadores no time 1? ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        Dados d = {0};
        printf("Nickname do jogador %d do time 1: ", i + 1);
        scanf("%49s", d.nickname);
        InserirNaLista(&time1, d);
    }

    printf("Quantos jogadores no time 2? ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        Dados d = {0};
        printf("Nickname do jogador %d do time 2: ", i + 1);
        scanf("%49s", d.nickname);
        InserirNaLista(&time2, d);
    }

    if (FilaVazia(&time1) || FilaVazia(&time2)) {
        printf("Ambos os times precisam ter ao menos um jogador.\n");
        return;
    }

    printf("\nPrimeiro jogador do time 1: %s\n", time1.itens[time1.inicio].nickname);
    printf("Primeiro jogador do time 2: %s\n", time2.itens[time2.inicio].nickname);

    int timeVencedor;
    do {
        printf("\nQual time venceu a partida? (1, 2 ou 0 para sair): ");
        scanf("%d", &timeVencedor);

        if (timeVencedor == 1) {
            Dados d;
            RemoverDaFila(&time1, &d);
            printf("%s saiu da fila e foi para o final do time 1.\n", d.nickname);
            InserirNaLista(&time1, d);
        } else if (timeVencedor == 2) {
            Dados d;
            RemoverDaFila(&time2, &d);
            printf("%s saiu da fila e foi para o final do time 2.\n", d.nickname);
            InserirNaLista(&time2, d);
        } else if (timeVencedor != 0) {
            printf("Opcao invalida.\n");
        }

    } while (timeVencedor != 0);

    printf("\nExercicio 9 encerrado.\n");
}

// Ex10
typedef struct {
    Dados jogadores[CAPACIDADE_SALA];
    int qtdeAtual;
} Sala;

void InicializarSala(Sala *s) {
    s->qtdeAtual = 0;
}

int SalaCheia(Sala *s) {
    return s->qtdeAtual == CAPACIDADE_SALA;
}

void AdicionarNaSala(Sala *s, Dados j) {
    s->jogadores[s->qtdeAtual] = j;
    s->qtdeAtual++;
}

void MostrarStatus(Sala *s, Fila *espera) {
    printf("\n--- STATUS DO SISTEMA ---\n");
    printf("Sala (%d/%d jogadores):\n", s->qtdeAtual, CAPACIDADE_SALA);
    for (int i = 0; i < s->qtdeAtual; i++) {
        printf("  - ID %d: %s\n", s->jogadores[i].id, s->jogadores[i].nickname);
    }

    printf("Fila de espera (%d jogadores):\n", espera->tamanho);
    int idx = espera->inicio;
    for (int i = 0; i < espera->tamanho; i++) {
        printf("  - ID %d: %s\n", espera->itens[idx].id, espera->itens[idx].nickname);
        idx = (idx + 1) % TAM_MAX;
    }
    printf("--------------------------\n");
}

void ExecutarExercicio10() {
    Sala sala;
    Fila espera;
    InicializarSala(&sala);
    InicializarFila(&espera);

    int opcao;

    do {
        printf("\nMenu (Exercicio 10):\n");
        printf("1 - Adicionar novo jogador\n");
        printf("2 - Iniciar partida com os jogadores atuais\n");
        printf("3 - Terminar partida\n");
        printf("4 - Mostrar status do sistema\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Dados j = {0};
                printf("ID do jogador: ");
                scanf("%d", &j.id);
                printf("Nickname do jogador: ");
                scanf("%49s", j.nickname);

                if (!SalaCheia(&sala)) {
                    AdicionarNaSala(&sala, j);
                    printf("Jogador adicionado na sala.\n");
                } else {
                    if (InserirNaLista(&espera, j)) {
                        printf("Sala cheia. Jogador adicionado na fila de espera.\n");
                    } else {
                        printf("Fila de espera cheia. Nao foi possivel adicionar o jogador.\n");
                    }
                }
                break;
            }
            case 2: {
                if (sala.qtdeAtual == 0) {
                    printf("Nao ha jogadores na sala para iniciar a partida.\n");
                } else {
                    printf("Partida iniciada com %d jogadores.\n", sala.qtdeAtual);
                }
                break;
            }
            case 3: {
                if (sala.qtdeAtual == 0) {
                    printf("Nao ha partida em andamento.\n");
                    break;
                }
                printf("Partida encerrada. Liberando vagas na sala...\n");
                sala.qtdeAtual = 0;

                while (!SalaCheia(&sala) && !FilaVazia(&espera)) {
                    Dados j;
                    RemoverDaFila(&espera, &j);
                    AdicionarNaSala(&sala, j);
                    printf("%s movido da fila de espera para a sala.\n", j.nickname);
                }
                break;
            }
            case 4:
                MostrarStatus(&sala, &espera);
                break;
            case 0:
                printf("Voltando ao menu principal.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);
}

int main() {
    int opcao;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("8 - Exercicio 8 (intercalar filas)\n");
        printf("9 - Exercicio 9 (partida com dois times)\n");
        printf("10 - Exercicio 10 (sala com fila de espera)\n");
        printf("0 - Sair\n");
        printf("Escolha um exercicio: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 8:
                ExecutarExercicio8();
                break;
            case 9:
                ExecutarExercicio9();
                break;
            case 10:
                ExecutarExercicio10();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
