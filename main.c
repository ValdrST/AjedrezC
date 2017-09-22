#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablero.h"
#include "pilaMovimiento.h"
#include "jugadores.h"
#include "partida.h"
int main()
{
    char ***tablero;
    PARTIDA partida;
    JUGADORES negro, blanco;
    tablero=juegoNuevo(&partida,&blanco,&negro);
    if(strcmp(partida.turno,"b")==0){
        printf("\nturno de blancas_");
        ejecutarTurno(&blanco,tablero,&partida);
    }
    if(strcmp(partida.turno,"n")==0){
        printf("\nturno de negras_");
        ejecutarTurno(&negro,tablero,&partida);
    }
    return 0;
}
