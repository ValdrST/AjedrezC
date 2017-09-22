#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partida.h"
#include "tablero.h"
#include "jugadores.h"
#include "pilaMovimiento.h"
char*** juegoNuevo(PARTIDA *partida, struct jugadores* blanco, struct jugadores* negro){
    char ***tablero;
    //partida=(PARTIDA*)calloc(1,sizeof(PARTIDA));
    partida->numTurno=1;
    strcpy(partida->turno,"b");
    tablero=iniciarTablero();
    //blanco=(JUGADORES*)malloc(sizeof(JUGADORES));
    getDatos(blanco, "blanco");
    strcpy(blanco->color,"b");
    //negro=(JUGADORES*)malloc(sizeof(JUGADORES));
    getDatos(blanco, "negro");
    strcpy(blanco->color,"n");
    blanco->movimientos=(POSICIONES*)malloc(sizeof(POSICIONES));
    negro->movimientos=(POSICIONES*)malloc(sizeof(POSICIONES));
    return tablero;
}

void finPartida(PARTIDA *partida, struct jugadores* blanco, struct jugadores* negro){
    free(blanco);
    free(negro);
    free(partida);
 }
