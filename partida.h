/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   partida.h
 * Author: valdr
 *
 * Created on 21 de octubre de 2017, 19:49
 */

#ifndef PARTIDA_H
#define PARTIDA_H
typedef struct partida {
    int numTurno;
    char turno[2];
}PARTIDA;

typedef struct posiciones{
    char tipoPieza[4];
    char posicion[3];
}POSICIONES;

typedef struct jugadores{
    char nombre[30];
    char color[2];
    struct posiciones *movimientos;
}JUGADORES;
char*** juegoNuevo(PARTIDA *partida, JUGADORES *blanco, JUGADORES *negro);
void finPartida(PARTIDA *partida, JUGADORES *blanco, JUGADORES *negro);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PARTIDA_H */

