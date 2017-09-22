#ifndef PILAMOVIMIENTO_H_INCLUDED
#define PILAMOVIMIENTO_H_INCLUDED
typedef struct posiciones{
    char tipoPieza[4];
    char posicion[3];
    struct posiciones *siguiente;
}POSICIONES;
POSICIONES *movNegra, *movBlancas;
char movimiento[6];
short revisarRegla(char *movimiento, POSICIONES *movPieza, char jugador, char ***tablero);
void RecibirMovimiento(char *movimiento, POSICIONES *movPieza, char jugador);
short convertirFila(char fila);
short convertirColumna(char columna);

#endif // PILAMOVIMIENTO_H_INCLUDED
