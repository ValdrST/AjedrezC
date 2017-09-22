#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED

typedef struct partida {
    int numTurno;
    char turno[2];
}PARTIDA;

typedef struct jugadores{
    char nombre[30];
    char color[2];
    struct posiciones *movimientos;
}JUGADORES;

char*** juegoNuevo(PARTIDA *partida, JUGADORES *blanco, JUGADORES *negro);
void finPartida(PARTIDA *partida, JUGADORES *blanco, JUGADORES *negro);

#endif // PARTIDA_H_INCLUDED
