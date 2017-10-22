/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   jugadores.h
 * Author: valdr
 *
 * Created on 21 de octubre de 2017, 19:53
 */

#ifndef JUGADORES_H
#define JUGADORES_H
void getDatos(JUGADORES *jugador, char *color);
void ejecutarTurno(JUGADORES *jugador, char ***tablero,PARTIDA *partida);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* JUGADORES_H */

