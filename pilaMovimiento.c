#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilaMovimiento.h"
void RecibirMovimiento(char *movimiento, POSICIONES *movPieza, char jugador){
    scanf("%s",movimiento);
    if(revisarRegla(movimiento, movPieza, jugador)==1){

    }

}

short revisarRegla(char *movimiento, POSICIONES *movPieza, char jugador, char ***tablero){
    short xi, yi, xf, yf;
    if(convertirFila(movimiento[0])!=-1 && convertirFila(movimiento[3])!=-1){
        xi=convertirFila(movimiento[3]);
        xf=convertirFila(movimiento[3]);
        if(convertirColumna(movimiento[1]!=-1) && convertirColumna(movimiento[4]!=-1)){
            yi=movimiento[1];
            yf=movimiento[4];
            if (jugador==movPieza->tipoPieza[1]){
                if(movPieza->tipoPieza[0]=='P'){
                    if(yf==(yi+1)||yf<=7 && strcmp(movimiento[xf][yf],"   ")==0){
                        if(yf==7)
                            movPieza->tipoPieza[0]='Q';
                        else
                            return 1;
                    }else
                        if(yf==(yi+1) && (xf==xi+1 || xf==xf-1) && strcmp(movimiento[xf][yf],"   ")!=0){
                            return 1;
                        }else
                            return 0;
                }else
                if(movPieza->tipoPieza[0]=='T'){

                }else
                if(movPieza->tipoPieza[0]=='C'){
                }else
                if(movPieza->tipoPieza[0]=='A'){
                }else
                if(movPieza->tipoPieza[0]=='Q'){
                }else
                if(movPieza->tipoPieza[0]=='K'){
                }else
                return 0;

            }else
                return 0;
        }else
            return 0;
    }else
        return 0;

}

short convertirFila(char fila){
    switch(toupper(fila)){
        case 'A':
            return 0;
            break;

        case 'B':
            return 1;
            break;

        case 'C':
            return 2;
            break;

        case 'D':
            return 3;
            break;

        case 'E':
            return 4;
            break;

        case 'F':
            return 5;
            break;

        case 'G':
            return 6;
            break;

        case 'H':
            return 7;
            break;
        default:
            return -1;
            break;
    }

short convertirColumna(char columna){
    switch(toupper(columna)){
        case '1':
            return 0;
            break;

        case '2':
            return 1;
            break;

        case '3':
            return 2;
            break;

        case '4':
            return 3;
            break;

        case '5':
            return 4;
            break;

        case '6':
            return 5;
            break;

        case '7':
            return 6;
            break;

        case '8':
            return 7;
            break;

        default:
            return -1;
            break;
        }
}
