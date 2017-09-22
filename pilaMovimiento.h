#ifndef PILAMOVIMIENTO_H_INCLUDED
#define PILAMOVIMIENTO_H_INCLUDED
#include "jugadores.h"
typedef struct posiciones{
    char tipoPieza[4];
    char posicion[3];
    struct posiciones *siguiente;
}POSICIONES;

char movimiento[6];

short revisarRegla(char *movimiento, POSICIONES *movPieza, char *jugador, char ***tablero);
short reglaLineal(short xi, short xf, short yi, short yf,char ***tablero);
short reglaDiagonal(short xi, short xf, short yi, short yf, char ***tablero);
void RecibirMovimiento(JUGADORES *jugador,char ***tablero);
short convertirFila(char fila);
short convertirColumna(char columna);

#endif // PILAMOVIMIENTO_H_INCLUDED
