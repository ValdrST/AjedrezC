#include <stdio.h>
#include <string.h>
void iniciarTablero(char **tablero){
    int ind, indY;
    tablero[0][0]="Tb1";
    tablero[1][0]="Cb1";
    tablero[2][0]="Ab1";
    tablero[3][0]="Qb";
    tablero[4][0]="Kb";
    tablero[5][0]="Ab2";
    tablero[6][0]="Cb2";
    tablero[7][0]="Tb2";
    for(ind=0;ind<8;ind++){
        strcpy(tablero[ind][1],strcat("Pb",(ind+1));
    }
    tablero[0][7]="Tn2";
    tablero[1][7]="Cn2";
    tablero[2][7]="An2";
    tablero[3][7]="Qn";
    tablero[4][7]="Kn";
    tablero[5][7]="An1";
    tablero[6][7]="Cn1";
    tablero[7][7]="Tn1";
    for(ind=0;ind<8;ind++){
        strcpy(tablero[ind][6],strcat("Pn",(8-ind));
    }
    for(indY=2;indY<=5;ind++){
        for(ind=0;ind<=7,ind++){
            strcpy(tablero[ind][indY],"   ");
        }
    }
}
