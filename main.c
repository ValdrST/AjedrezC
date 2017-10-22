/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: valdr
 *
 * Created on 21 de octubre de 2017, 19:28
 */

#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"
#include "partida.h"
#include "jugadores.h"
#include "pilaMovimiento.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char ***tablero;
    PARTIDA *partida;
    JUGADORES *blanco, *negro;
    tablero = juegoNuevo(partida, blanco, negro);
    if(strcmp(partida->turno,"b\0")!=0){
        printf("\nturno de blancas_");
        ejecutarTurno(blanco,tablero,partida);
    }
    if(strcmp(partida->turno,"n\0")!=0){
        printf("\nturno de negras_");
        ejecutarTurno(negro,tablero,partida);
    }
    imprimirTablero(tablero);
    return 0;
}

