#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "jugadores.h"
#include "pilaMovimiento.h"

void getDatos(JUGADORES *jugador, char *color)
{
    printf("\nJugador %s cual es tu nombre?_", color);
    scanf("%s",jugador->nombre);
}

void ejecutarTurno(JUGADORES *jugador, char ***tablero ,PARTIDA *partida){
    RecibirMovimiento(jugador,tablero);
    partida->numTurno++;
    if(strcmp(jugador->color,"b")==0)
        strcpy(partida->turno,"n");
    if(strcmp(jugador->color,"n")==0)
        strcpy(partida->turno,"b");
}
