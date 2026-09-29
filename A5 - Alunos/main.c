#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void GerarListas(TLista *time1, TLista *time2);
void ExibirTimes(TLista *time1, TLista *time2);
void Atacar(Pokemon *atacante, Pokemon *defensor);
int Batalha(Pokemon *p1, Pokemon *p2);

int main(){
    TLista *time1;
    TLista *time2;

    TLista *pokemon1;
    TLista *pokemon2;

    int escolha1;
    int escolha2;

    int vencedor;
    int derrotado1, derrotado2;

    time1 = CriarLista();
    time2 = CriarLista();

    GerarListas(time1, time2);
    do{
    ExibirTimes(time1, time2);

        /* =============================
           Escolha do jogador 1
           ============================= */
    printf("Jogador 1 - escolha seu Pokemon:");
    scanf("%i", &escolha1);
        /* =============================
           Escolha do jogador 2
           ============================= */
    printf("Jogador 2 - escolha seu Pokemon:");
    scanf("%i", &escolha2);

        /* =============================
           Batalha
           ============================= */
    pokemon1 = SelecionarPokemon(time1, escolha1);
    pokemon2 = SelecionarPokemon(time1, escolha2);
    vencedor = Batalha(pokemon1, pokemon2);

        /* =============================
           Remove o derrotado
           ============================= */
    if(vencedor == 1){
            RemoverPokemon(time1, pokemon1);
            }
    else{
            RemoverPokemon(time2, pokemon2);
    }}while(derrotado1 != 0 && derrotado2 != 0);


    return 0;
}

/* =========================================================
   GERACAO DOS TIMES
   ========================================================= */

void GerarListas(TLista *time1, TLista *time2){
    Pokemon t1[6], t2[6];
    GerarTimes(t1, t2);
    for (int i = 0; i < 6; i++){
        InserirNoFim(time1, t1[i]);
    }
    for (int i = 0; i < 6; i++){
        InserirNoFim(time2, t2[i]);
    }
}

/* =========================================================
   EXIBICAO DOS TIMES
   ========================================================= */

void ExibirTimes(TLista *time1, TLista *time2){
    system("CLS");

    printf("===============================================\n");
    printf("                POKEMON BATTLE\n");
    printf("===============================================\n\n");

    printf("JOGADOR 1\n\n");

    ExibirLista(time1);

    printf("\n");

    printf("******************* VS ************************\n\n");

    printf("JOGADOR 2\n\n");

    ExibirLista(time2);

    printf("\n");
}

/* =========================================================
   ATAQUE
   ========================================================= */

void Atacar(Pokemon *atacante, Pokemon *defensor){
    int dano = atacante->AT - defensor->DF / 2;
    printf("dano causado: %i", dano);
    if(dano>atacante->HP){

    }

}

/* =========================================================
   BATALHA
   ========================================================= */

int Batalha(Pokemon *p1, Pokemon *p2){

    system("CLS");

    printf("===============================================\n");
    printf("                   BATALHA\n");
    printf("===============================================\n\n");

    ExibirLista(p1);
    printf("\nVS\n");
    ExibirLista(p2);
    do{
    printf("%s atacou %s", p1->Nome,p2->Nome);
    Atacar(p1, p2);
    if(p1->HP == 0){
        printf("%s venceu!\n%s foi eliminado!", p1->Nome, p2->Nome);
        printf("pressione qualquer tecla para continuar");
        scanf("");
        return 1;
    }
    printf("%s atacou %s", p2,p1);
    Atacar(p2, p1);
    }while(p2->HP != 0 && p1->HP!=0);
    printf("%s venceu!\n%s foi eliminado!", p2->Nome, p1->Nome);
    printf("pressione qualquer tecla para continuar");
    scanf("");
    return 0;



}
