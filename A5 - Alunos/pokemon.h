#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

typedef struct
{
    char Nome[20];
    int HP, AT, DF, SP;
} Pokemon;

void GerarTimes(Pokemon p1[6], Pokemon p2[6]);

#endif
