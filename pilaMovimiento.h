/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilaMovimiento.h
 * Author: valdr
 *
 * Created on 21 de octubre de 2017, 19:53
 */

#ifndef PILAMOVIMIENTO_H
#define PILAMOVIMIENTO_H
short revisarRegla(char *movimiento, POSICIONES *movPieza, char *jugador, char ***tablero);
short reglaLineal(short xi, short xf, short yi, short yf,char ***tablero);
short reglaDiagonal(short xi, short xf, short yi, short yf, char ***tablero);
void RecibirMovimiento(JUGADORES *jugador,char ***tablero);
short convertirFila(char fila);
short convertirColumna(char columna);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PILAMOVIMIENTO_H */

