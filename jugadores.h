#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include "partida.h"


void getDatos(JUGADORES *jugador, char *color);
void ejecutarTurno(JUGADORES *jugador, char ***tablero,PARTIDA *partida);
#endif // JUGADORES_H_INCLUDED
