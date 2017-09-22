#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pilaMovimiento.h"
#include "jugadores.h"


void RecibirMovimiento(JUGADORES *jugador,char ***tablero)
{
    int xi,yi, xf, yf, flag=0;
    char movimiento[6];
    POSICIONES *mov;
    mov=(POSICIONES*)malloc(sizeof(POSICIONES));
    do
    {
        printf("introduccion\n");
        scanf("%s",movimiento);
        xi=convertirFila(movimiento[0]);
        xf=convertirFila(movimiento[3]);
        yi=convertirColumna(movimiento[1]);
        yf=convertirColumna(movimiento[4]);

        if(revisarRegla(movimiento, jugador->movimientos, jugador->color, tablero)==1)
        {

            printf("\n%c%c%s -> %c%c%s",movimiento[0],movimiento[1],tablero[xi][yi], movimiento[3],movimiento[4],tablero[xf][yf]);
            strcpy(tablero[xf][yf],tablero[xi][yi]);
            strcpy(tablero[xi][yi],"   ");
            flag=0;
        }
        else
        {
            printf("\nmovimiento invalido\n");
            flag=1;
        }
    }
    while(flag!=1);

    strcpy(jugador->movimientos->posicion,"");
    mov->posicion[0]=movimiento[3];
    mov->posicion[1]=movimiento[4];
    mov->tipoPieza[0]=tablero[xf][yf][0];
    mov->tipoPieza[1]=tablero[xf][yf][1];
    mov->tipoPieza[2]=tablero[xf][yf][2];
    mov->siguiente=jugador->movimientos;
    jugador->movimientos=mov;
}

short revisarRegla(char *movimiento, POSICIONES *movPieza, char *jugador, char ***tablero)
{
    short xi, yi, xf, yf;
    if(convertirFila(movimiento[0])!=-1 && convertirFila(movimiento[3])!=-1 && convertirColumna(movimiento[1])!=-1 && convertirColumna(movimiento[4])!=-1)
    {
        xi=convertirFila(movimiento[0]);
        xf=convertirFila(movimiento[3]);
        yi=convertirColumna(movimiento[1]);
        yf=convertirColumna(movimiento[4]);
        if(convertirColumna(movimiento[1]!=-1) && convertirColumna(movimiento[4]!=-1))
        {
            if (jugador[0]==movPieza->tipoPieza[1])
            {
                if(movPieza->tipoPieza[0]=='P')
                {
                    if(xf<=7 && xf>=0 && yf<=7 && yf>=0){
                        if((xf==xi+1 && jugador[0]=='b') || (xf==xi+1 && (strcmp(tablero[xf][yf],"   ")!=0 && (yf==yi+1 || yf==yi-1) && tablero[xf][yf][1]!=jugador[0]))){
                            if(yf==7)
                                tablero[xi][yi][0]='Q';
                            return 1;
                        }
                        if((xf==xi-1 && jugador[0]=='n') || (xf==xi-1 && (strcmp(tablero[xf][yf],"   ")!=0 && (yf==yi+1 || yf==yi-1) && tablero[xf][yf][1]!=jugador[0]))){
                            if(yf==0)
                                tablero[xi][yi][0]='Q';
                            return 1;
                        }
                    }
                    return 0;
                }
                else if(movPieza->tipoPieza[0]=='T')
                {
                    if(xf<=7 && xf>=0 && yf<=7 && yf>=0)
                    {
                        if(strcmp(tablero[xf][yf],"   ")==0)
                        {
                            return reglaLineal(xi,xf,yi,yf, tablero);
                        }

                        if(strcmp(tablero[xf][yf],"   ")!=0 && tablero[xf][yf][1]!=jugador[0])
                        {
                            return reglaLineal(xi,xf,yi,yf, tablero);
                        }
                    }
                    return 0;
                }
                else if(movPieza->tipoPieza[0]=='C')
                {
                    if(xf<=7 && xf>=0 && yf<=7 && yf>=0)
                    {
                        if(((yf==yi+1 || yf==yi-1) && (xf==xi+2 || xf==xi-2))||((xf==xi+1 || xf==xi-1) && (yf==yi+2 || yf==yi-2)))
                        {
                            if(strcmp(tablero[xf][yf],"   ")==0)
                                return 1;
                            if(strcmp(tablero[xf][yf],"   ")!=0 && tablero[xf][yf][1]!=jugador[0])
                                return 1;
                        }
                    }
                    else
                        return 0;
                }
                else if(movPieza->tipoPieza[0]=='A')
                {
                    if(xf<=7 && xf>=0 && yf<=7 && yf>=0)
                    {
                        if(abs(xi-xf)==abs(yi-yf) && strcmp(tablero[xf][yf],"   ")==0)
                            return reglaDiagonal(xi,xf,yi,yf,tablero);
                        if(abs(xi-xf)==abs(yi-yf) && strcmp(tablero[xf][yf],"   ")!=0 && tablero[xf][yf][1]!=jugador[0])
                        {
                            return reglaDiagonal(xi,xf,yi,yf, tablero);
                        }
                    }
                    return 0;
                }
                else if(movPieza->tipoPieza[0]=='Q')
                {
                    if(xf<=7 && xf>=0 && yf<=7 && yf>=0)
                    {
                        if((abs(xi-xf)==abs(yi-yf) || xi==xf || yi==yf) && strcmp(tablero[xf][yf],"   ")==0)
                        {
                            if(abs(xi-xf)==abs(yi-yf))
                                return reglaDiagonal(xi,xf,yi,yf, tablero);
                            if(xi==xf || yi==yf)
                                return reglaLineal(xi,xf,yi,yf, tablero);

                        }
                        if((abs(xi-xf)==abs(yi-yf) || xi==xf || yi==yf) && strcmp(tablero[xf][yf],"   ")!=0 && tablero[xf][yf][1]!=jugador[0])
                        {
                            if(abs(xi-xf)==abs(yi-yf))
                                return reglaDiagonal(xi,xf,yi,yf, tablero);
                            if(xi==xf || yi==yf)
                                return reglaLineal(xi,xf,yi,yf, tablero);
                        }
                        return 0;
                    }
                }
                else if(movPieza->tipoPieza[0]=='K')
                {
                    if(xf<=7 && xf>=0 && yf<=7 && yf>=0)
                    {
                        if(abs(xi-xf)<=1 && abs(yi-yf<=1) && strcmp(tablero[xf][yf],"   ")==0)
                        {
                            return 1;
                        }
                        if(abs(xi-xf)<=1 && abs(yi-yf<=1) && strcmp(tablero[xf][yf],"   ")!=0 && tablero[xf][yf][1]!=jugador[0])
                        {
                            return 1;
                        }
                    }
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
        return 0;
    }
    return 0;
}


short convertirFila(char fila)
{
    switch(toupper(fila))
    {
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
}

short convertirColumna(char columna)
{
    switch(toupper(columna))
    {
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

short reglaDiagonal(short xi, short xf, short yi, short yf, char ***tablero)
{
    short ind, indY;
    if(xf>xi && yf>yi)
    {
        indY=yf;
        for(ind=xi; ind<xf; ind++)
        {
            if(strcmp(tablero[xf-ind][yf-indY],"   ")!=0)
            {
                return 0;
            }
            indY++;
        }
    }
    if(xf>xi && yf<yi)
    {
        indY=yf;
        for(ind=xi; ind<xf; ind++)
        {
            if(strcmp(tablero[xf-ind][yf+indY],"   ")!=0)
            {
                return 0;
            }
            indY--;
        }
    }
    if(xf<xi && yf>yi)
    {
        indY=yf;
        for(ind=xi; ind>xf; ind--)
        {
            if(strcmp(tablero[xf+ind][yf-indY],"   ")!=0)
            {
                return 0;
            }
            indY++;
        }
    }
    if(xf<xi && yf<yi)
    {
        indY=yf;
        for(ind=xi; ind>xf; ind--)
        {
            if(strcmp(tablero[xf+ind][yf+indY],"   ")!=0)
            {
                return 0;
            }
            indY--;
        }
    }
    return 1;
}

short reglaLineal(short xi, short xf, short yi, short yf, char ***tablero)
{
    short ind;
    if(yf!=yi && yf>yi)
    {
        for(ind=yi; ind<yf; ind++)
        {
            if(strcmp(tablero[xf][ind],"   ")!=0)
                return 0;
        }
    }
    if(yf!=yi && yf<yi)
    {
        for(ind=yi; ind>yf; ind--)
        {
            if(strcmp(tablero[xf][ind],"   ")!=0)
                return 0;
        }
    }
    if(xf!=xi && xf>xi)
    {
        for(ind=xi; ind<xf; ind++)
        {
            if(strcmp(tablero[ind][yf],"   ")!=0)
                return 0;
        }
    }
    if(xf!=xi && xf<xi)
    {
        for(ind=xi; ind>xf; ind--)
        {
            if(strcmp(tablero[ind][yf],"   ")!=0)
                return 0;
        }
    }
    return 1;
}
