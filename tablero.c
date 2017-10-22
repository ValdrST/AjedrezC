/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*** iniciarTablero(){
    short ind, indY;
    char ***tablero;
    tablero=(char***)malloc(8*sizeof(char**));
    for(ind=0;ind<8;ind++){
        tablero[ind]=(char**)malloc(8*sizeof(char*));
        for(indY=0;indY<8;indY++)
            tablero[ind][indY]=(char*)malloc(4*sizeof(char));
    }
    tablero[0][0]="Tb";
    tablero[1][0]="Cb";
    tablero[2][0]="Ab";
    tablero[3][0]="Qb";
    tablero[4][0]="Kb";
    tablero[5][0]="Ab";
    tablero[6][0]="Cb";
    tablero[7][0]="Tb";
    for(ind=0;ind<8;ind++){
        strcpy(tablero[ind][1],"Pb");
    }
    tablero[0][7]="Tn";
    tablero[1][7]="Cn";
    tablero[2][7]="An";
    tablero[3][7]="Qn";
    tablero[4][7]="Kn";
    tablero[5][7]="An";
    tablero[6][7]="Cn";
    tablero[7][7]="Tn";
    for(ind=0;ind<8;ind++){
        strcpy(tablero[ind][6],"Pn");
    }
    for(indY=2;indY<=5;indY++){
        for(ind=0;ind<=7;ind++){
            strcpy(tablero[ind][indY],"  ");
        }
    }
    return tablero;
}

void imprimirTablero(char ***tablero){
    int x, y;
    for(y=0;y<8;y++){
        for(x=0;x<8;x++){
            printf(" %s ",tablero[x][y]);
        }
        printf("\n");
    }
}