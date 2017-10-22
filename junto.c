#include <stdio.h>
#include <stdlib.h>

int main(){

	
	int tablero[8][8];
	int jugador,juego;
	char comando[4];
	int error1,error2,error3,error4,error5,error6,error7,error8,xi,yi,xf,yf,bandera;
	jugador = 2;

//Asignamos fichas blancas
	tablero[7][0]=10;
	tablero[7][1]=11;
	tablero[7][2]=12;
	tablero[7][3]=13;
	tablero[7][4]=14;
	tablero[7][5]=12;
	tablero[7][6]=11;
	tablero[7][7]=10;
//Asignamos peones blancos
	for(int i = 0; i<=7; i++){
		tablero[6][i] = 15;
	}
//Asignamos casillas vacias
	for(int i = 2; i<=5; i++){
		for(int j = 0; j<=7; j++){
			tablero[i][j] = 99;
		}
	}
//Asignamos fichas negras
	tablero[0][0]=20;
	tablero[0][1]=21;
	tablero[0][2]=22;
	tablero[0][3]=23;
	tablero[0][4]=24;
	tablero[0][5]=22;
	tablero[0][6]=21;
	tablero[0][7]=20;
//Asignamos peones negros
	for(int i = 0; i<=7; i++){
		tablero[1][i] = 25;
	}

//----------------------------------Loop de jugador
do{

switch(jugador){
	case 1: jugador=2;printf("    TURNO FICHAS NEGRAS\n"); break;
	case 2: jugador=1;printf("    TURNO FICHAS BLANCAS\n"); break;
}
printf("\n");
//Impresion tablero inicial
	for(int i = 0; i<=7; i++){
		printf("%i  ",i+1);
		for(int j = 0; j<=7; j++){
			switch(tablero[i][j]){
				case 10:printf("TB "); break;
				case 20:printf("TN "); break;
				case 11:printf("CB "); break;
				case 21:printf("CN "); break;
				case 12:printf("AB "); break;
				case 22:printf("AN "); break;
				case 13:printf("QB "); break;
				case 23:printf("QN "); break;
				case 14:printf("RB "); break;
				case 24:printf("RN "); break;
				case 15:printf("PB "); break;
				case 25:printf("PN "); break;
				case 99:printf("   "); break;
			}
		}
		printf("\n");
	}printf("\n   A  B  C  D  E  F  G  H\n");

//Jugada-----------------------------------------------------------------------


do{
	printf("Esperando movimiento..\n");
	scanf("%s",&comando[0]);
//Error columna inicial invalida--------------------------------------------------
	switch(comando[0]){
		case 'A': xi=0;error1=0; break;case 'a': xi=0;error1=0; break;
		case 'B': xi=1;error1=0; break;case 'b': xi=1;error1=0; break;
		case 'C': xi=2;error1=0; break;case 'c': xi=2;error1=0; break;
		case 'D': xi=3;error1=0; break;case 'd': xi=3;error1=0; break;
		case 'E': xi=4;error1=0; break;case 'e': xi=4;error1=0; break;
		case 'F': xi=5;error1=0; break;case 'f': xi=5;error1=0; break;		
		case 'G': xi=6;error1=0; break;case 'g': xi=6;error1=0; break;
		case 'H': xi=7;error1=0; break;case 'h': xi=7;error1=0; break;
		default:error1=1;printf("Columna inicial no válida\n");break;
	}
//Error fila inicial invalida--------------------------------------------------
	switch(comando[1]){
		case '1': yi=0;error2=0; break;
		case '2': yi=1;error2=0; break;
		case '3': yi=2;error2=0; break;
		case '4': yi=3;error2=0; break;
		case '5': yi=4;error2=0; break;
		case '6': yi=5;error2=0; break;
		case '7': yi=6;error2=0; break;
		case '8': yi=7;error2=0; break;
		default:error2=1;printf("Fila inicial no válida\n");break;
	}
//Error columna final invalida--------------------------------------------------
	switch(comando[2]){
		case 'A': xf=0;error3=0; break;case 'a': xf=0;error3=0; break;
		case 'B': xf=1;error3=0; break;case 'b': xf=1;error3=0; break;
		case 'C': xf=2;error3=0; break;case 'c': xf=2;error3=0; break;
		case 'D': xf=3;error3=0; break;case 'd': xf=3;error3=0; break;
		case 'E': xf=4;error3=0; break;case 'e': xf=4;error3=0; break;
		case 'F': xf=5;error3=0; break;case 'f': xf=5;error3=0; break;		
		case 'G': xf=6;error3=0; break;case 'g': xf=6;error3=0; break;
		case 'H': xf=7;error3=0; break;case 'h': xf=7;error3=0; break;
		default:error3=1;printf("Columna final no válida\n");break;
	}
//Error fila final invalida-----------------------------------------------------
	switch(comando[3]){
		case '1': yf=0;error4=0; break;
		case '2': yf=1;error4=0; break;
		case '3': yf=2;error4=0; break;
		case '4': yf=3;error4=0; break;
		case '5': yf=4;error4=0; break;
		case '6': yf=5;error4=0; break;
		case '7': yf=6;error4=0; break;
		case '8': yf=7;error4=0; break;
		default:error4=1;printf("Fila final no válida\n");break;
	}
//Error por seleccionar espacio en blanco----------------------------------------
	if(tablero[yi][xi]==99){
		error5=1;printf("No hay ficha en casilla inicial\n");
	}else{error5=0;}
//Error por seleccionar ficha de otro jugador------------------------------------
	switch(jugador){
		case 1:
			if(tablero[yi][xi]==20||tablero[yi][xi]==21||tablero[yi][xi]==22||tablero[yi][xi]==23||tablero[yi][xi]==24||tablero[yi][xi]==25)
				{error5=1;printf("La ficha inicial no te pertenece\n");}else{error5=0;}
		break;
		case 2:
			if(tablero[yi][xi]==10||tablero[yi][xi]==11||tablero[yi][xi]==12||tablero[yi][xi]==13||tablero[yi][xi]==14||tablero[yi][xi]==15)
				{error5=1;printf("La ficha inicial no te pertenece\n");}else{error5=0;}
		break;
	}
//Error por sereccionar ficha de destino propia----------------------------------
	switch(jugador){
		case 1:
			if(tablero[yf][xf]==10||tablero[yf][xf]==11||tablero[yf][xf]==12||tablero[yf][xf]==13||tablero[yf][xf]==14||tablero[yf][xf]==15)
				{error6=1;printf("La ficha en casilla final es tuya\n");}else{error6=0;}
		break;
		case 2:
			if(tablero[yf][xf]==20||tablero[yf][xf]==21||tablero[yf][xf]==22||tablero[yf][xf]==23||tablero[yf][xf]==24||tablero[yf][xf]==25)
				{error6=1;printf("La ficha en casilla final es tuya\n");}else{error6=0;}
		break;
	}
//Error por no realizar desplazamiento-------------------------------------------
	if(xi==xf&&yi==yf){error7=1;printf("No se realizó nigún desplazamiento\n");}else{error7=0;}
//Error por no cumplir con reglas de ficha---------------------------------------

	//Casos particulares-------------------------------------
int a,b,c,d;
		if(xi==xf){a=1;}else{if(yi==yf){a=2;}else{if(abs(yf-yi)==abs(xf-xi)){a=3;}}}
		if(yi>yf){b=1;}else{if(yi<yf){b=2;}}
		if(xi>xf){c=1;}else{if(xi<xf){c=2;}}
		if(abs(xi-xf)<=1 && abs(yf-yi)<=1){d=1;}else{d=2;}
	//-------------------------------------------------------	
switch(tablero[yi][xi]){
//Movimiento de torre negra
	case 10:
		switch(d){
			case 1://Solo se mueve una casilla
				switch(a){
					case 1://Se mueve en verical
						error8=0;
					break;
					case 2://Se mueve en horizontal
						error8=0;
					break;
					case 3://Se mueve en diagonal
						error8=1;printf("Movimiento inválido\n");
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
			case 2://Se mueve mas de una casilla
				switch(a){
					case 1://Se mueve en vertical
						switch(b){
							case 1://Se mueve hacia arriba
								for(int i = yi-1; i>yf; i--){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;
							case 2://S emueve hacia abajo
								for(int i = yi+1; i<yf; i++){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;
						}
					break;
					case 2://Se mueve en horizontal
						switch(c){
							case 1://Se mueve hacia izquierda
								for(int i = xi-1; i>xf; i--){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválid\n");}else{error8=0;}
								}
							break;
							case 2://Se mueve hacia derecha
								for(int i = xi+1; i<xf; i++){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;

						}
					break;
					case 3://Se mueve en diagonal
						error8=1;printf("Movimiento inválido5\n");
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
		}
	break;
//Movimiento de tore blanca
	case 20:
		switch(d){
			case 1://Solo se mueve una casilla
				switch(a){
					case 1://Se mueve en verical
						error8=0;
					break;
					case 2://Se mueve en horizontal
						error8=0;
					break;
					case 3://Se mueve en diagonal
						error8=1;printf("Movimiento inválido\n");
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
			case 2://Se mueve mas de una casilla
				switch(a){
					case 1://Se mueve en vertical
						switch(b){
							case 1:
								for(int i = yi-1; i>yf; i--){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido1\n");}else{error8=0;}
								}
							break;
							case 2:
								for(int i = yi+1; i<yf; i++){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido2\n");}else{error8=0;}
								}
							break;
						}
					break;
					case 2://Se mueve en horizontal
						switch(c){
							case 1:
								for(int i = xi-1; i>xf; i--){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválid3\n");}else{error8=0;}
								}
							break;
							case 2:
								for(int i = xi+1; i<xf; i++){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválido4\n");}else{error8=0;}
								}
							break;

						}
					break;
					case 3://Se mueve en diagonal
						error8=1;printf("Movimiento inválido5\n");
					break;
					default:{error8=1;printf("Movimiento inválido6\n");}
				}
			break;
		}
	break;
//Movimiento de caballo blanco
	case 11:
		switch(b){
			case 1:
				switch(c){
					case 1:
						if(xi==xf+1 && yi==yf+2){error8=0;}else
						{if(xi==xf+2 && yi==yf+1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
					case 2:
						if(xi==xf-1 && yi==yf+2){error8=0;}else
						{if(xi==xf-2 && yi==yf+1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
				}
			break;
			case 2:
				switch(c){
					case 1:
						if(xi==xf+1 && yi==yf-2){error8=0;}else
						{if(xi==xf+2 && yi==yf-1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
					case 2:
						if(xi==xf-1 && yi==yf-2){error8=0;}else
						{if(xi==xf-2 && yi==yf-1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
				}
			break;
			default:error8=1;printf("Movimiento inválido\n");
		}
	break;
//Movimiento de caballo negro
	case 21:
		switch(b){
			case 1:
				switch(c){
					case 1:
						if(xi==xf+1 && yi==yf+2){error8=0;}else
						{if(xi==xf+2 && yi==yf+1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
					case 2:
						if(xi==xf-1 && yi==yf+2){error8=0;}else
						{if(xi==xf-2 && yi==yf+1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
				}
			break;
			case 2:
				switch(c){
					case 1:
						if(xi==xf+1 && yi==yf-2){error8=0;}else
						{if(xi==xf+2 && yi==yf-1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
					case 2:
						if(xi==xf-1 && yi==yf-2){error8=0;}else
						{if(xi==xf-2 && yi==yf-1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}}
					break;
				}
			break;
			default:error8=1;printf("Movimiento inválido\n");
		}
	break;
//Movimiento de alfil blanco
	case 12:
		switch(d){
			case 1://Solo se mueve una casilla
				switch(a){
					case 1://Se mueve en vertical
						error8=1;printf("Movimiento inválido\n");
					break;
					case 2://Se mueve en horizontal
						error8=1;printf("Movimiento inválido\n");
					break;
					case 3://Se mueve en diagonal
						error8=0;
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
			case 2://Se mueve mad de una casilla
				switch(a){
					case 1://Se mueve en vertical
						error8=1;printf("Movimiento inválido\n");
					break;
					case 2://Se mueve en horizontal
						error8=1;printf("Movimiento inválido\n");
					break;
					case 3://Se mueve en diagonal
						switch(b){
							case 1:
								switch(c){
									case 1://Se mueve arriba a la izquierda
										for(int i = yi-1; i>yf; i--){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve arriba a la derecha
										for(int i = yi-1; i>yf; i--){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
								}
							break;
							case 2:
								switch(c){
									case 1://Se mueve abajo a la izquierda
										for(int i = yi+1; i<yf; i++){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve abajo a la derecha
										for(int i = yi+1; i<yf; i++){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;

								}
							break;
						}
					break;
					default:{error8=1;printf("Movimiento inválido\n");}

				}
			break;
		}
	break;
//Movimiento de alfil negro
	case 22:break;
		switch(d){
			case 1://Solo se mueve una casilla
				switch(a){
					case 1://Se mueve en vertical
						error8=1;printf("Movimiento inválido\n");
					break;
					case 2://Se mueve en horizontal
						error8=1;printf("Movimiento inválido\n");
					break;
					case 3://Se mueve en diagonal
						error8=0;
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
			case 2://Se mueve mad de una casilla
				switch(a){
					case 1://Se mueve en vertical
						error8=1;printf("Movimiento inválido\n");
					break;
					case 2://Se mueve en horizontal
						error8=1;printf("Movimiento inválido\n");
					break;
					case 3://Se mueve en diagonal
						switch(b){
							case 1:
								switch(c){
									case 1://Se mueve arriba a la izquierda
										for(int i = yi-1; i>yf; i--){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve arriba a la derecha
										for(int i = yi-1; i>yf; i--){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
								}
							break;
							case 2:
								switch(c){
									case 1://Se mueve abajo a la izquierda
										for(int i = yi+1; i<yf; i++){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve abajo a la derecha
										for(int i = yi+1; i<yf; i++){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;

								}
							break;
						}
					break;
					default:{error8=1;printf("Movimiento inválido\n");}

				}
			break;
		}
//Movimiento de reina blnaca
	case 13:
		switch(d){
			case 1://Solo se mueve una casilla
				switch(a){
					case 1://Se mueve en vertical
						error8=0;
					break;
					case 2://Se mueve en horizontal
						error8=0;
					break;
					case 3://Se mueve en diagonal
						error8=0;
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
			case 2://Se mueve mad de una casilla
				switch(a){
					case 1://Se mueve en vertical
						switch(b){
							case 1://Se mueve hacia arriba
								for(int i = yi-1; i>yf; i--){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;
							case 2://S emueve hacia abajo
								for(int i = yi+1; i<yf; i++){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;
						}
					break;
					case 2://Se mueve en horizontal
						switch(c){
							case 1://Se mueve hacia izquierda
								for(int i = xi-1; i>xf; i--){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválid\n");}else{error8=0;}
								}
							break;
							case 2://Se mueve hacia derecha
								for(int i = xi+1; i<xf; i++){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;

						}
					break;
					case 3://Se mueve en diagonal
						switch(b){
							case 1:
								switch(c){
									case 1://Se mueve arriba a la izquierda
										for(int i = yi-1; i>yf; i--){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve arriba a la derecha
										for(int i = yi-1; i>yf; i--){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
								}
							break;
							case 2:
								switch(c){
									case 1://Se mueve abajo a la izquierda
										for(int i = yi+1; i<yf; i++){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve abajo a la derecha
										for(int i = yi+1; i<yf; i++){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;

								}
							break;
						}
					break;
					default:{error8=1;printf("Movimiento inválido\n");}

				}
			break;
		}
	break;
//Movimiento de reina negra
	case 23:
		switch(d){
			case 1://Solo se mueve una casilla
				switch(a){
					case 1://Se mueve en vertical
						error8=0;
					break;
					case 2://Se mueve en horizontal
						error8=0;
					break;
					case 3://Se mueve en diagonal
						error8=0;
					break;
					default:{error8=1;printf("Movimiento inválido\n");}
				}
			break;
			case 2://Se mueve mad de una casilla
				switch(a){
					case 1://Se mueve en vertical
						switch(b){
							case 1://Se mueve hacia arriba
								for(int i = yi-1; i>yf; i--){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;
							case 2://S emueve hacia abajo
								for(int i = yi+1; i<yf; i++){
									if(tablero[i][xi]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;
						}
					break;
					case 2://Se mueve en horizontal
						switch(c){
							case 1://Se mueve hacia izquierda
								for(int i = xi-1; i>xf; i--){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválid\n");}else{error8=0;}
								}
							break;
							case 2://Se mueve hacia derecha
								for(int i = xi+1; i<xf; i++){
									if(tablero[yi][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
								}
							break;

						}
					break;
					case 3://Se mueve en diagonal
						switch(b){
							case 1:
								switch(c){
									case 1://Se mueve arriba a la izquierda
										for(int i = yi-1; i>yf; i--){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve arriba a la derecha
										for(int i = yi-1; i>yf; i--){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
								}
							break;
							case 2:
								switch(c){
									case 1://Se mueve abajo a la izquierda
										for(int i = yi+1; i<yf; i++){
											for(int j = xi-1; j>xf; j--){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;
									case 2://Se mueve abajo a la derecha
										for(int i = yi+1; i<yf; i++){
											for(int j = xi+1; j<xf; j++){
												if(tablero[j][i]!=99){error8=1;printf("Movimiento inválido\n");}else{error8=0;}
											}
										}
									break;

								}
							break;
						}
					break;
					default:{error8=1;printf("Movimiento inválido\n");}

				}
			break;
		}
	break;
//Movimiento de rey blanco
	case 14:
		if(d==1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}
	break;
//Movimiento de rey negro
	case 24:
		if(abs(xf-xi)<=1 && abs(yf-yi)<=1){error8=0;}else{error8=1;printf("Movimiento inválido\n");}
	break;
//Movimiento de peon blanco
	case 15:
			switch(d){
			case 1://Se mueve una casilla
				switch(a){
					case 1://Se mueve vertical
						switch(b){
							case 1:if(tablero[yf][xf]!=99){error8=1;printf("Movimiento inválida\n");}else{error8=0;} break;
							case 2:error8=1;printf("Movimiento inválido\n"); break;
						}
					break;
					case 2://Se mueve horizontal
						error8=1;printf("Movimiento inválido\n"); 
					break;
					case 3://Se mueve en diagonal
						switch(b){//Dirección a la que avanza
							case 1: if(tablero[yf][xf]==20||tablero[yf][xf]==21||tablero[yf][xf]==22||tablero[yf][xf]==23||tablero[yf][xf]==24||tablero[yf][xf]==25)
								{error8=0;}else{error8=1;printf("Movimiento inválido\n");} break;
							case 2:error8=1;printf("Movimiento inválido\n"); break;
						}
					break;
				}
			break;
			case 2://Se mueve más de una casilla
				switch(a){
					case 1:
						switch(b){
							case 1:if(yi==6 && yf==4){error8=0;}else{error8=1;printf("Movimiento inválido\n");} break;
							case 2:error8=1;printf("Movimiento inválido\n"); break;
						}
					break;
					case 2:error8=1;printf("Movimiento inválido\n"); break;
					case 3:error8=1;printf("Movimiento inválido\n"); break;
					default:{error8=1;printf("Movimiento inválido\n");}

				}
			break;
		}	

	break;
//Movimiento de peon negro
	case 25:
		switch(d){
			case 1://Se mueve una casilla
				switch(a){
					case 1://Se mueve vertical
						switch(b){
							case 1:error8=1;printf("Movimiento inválido\n");break;
							case 2:if(tablero[yf][xf]!=99){error8=1;printf("Movimiento inválida\n");}else{error8=0;} break;
						}
					break;
					case 2://Se mueve horizontal
						error8=1;printf("Movimiento inválido\n"); 
					break;
					case 3://Se mueve en diagonal
						switch(b){//Dirección a la que avanza
							case 1:error8=1;printf("Movimiento inválido2\n"); break;
							case 2:if(tablero[yf][xf]==10||tablero[yf][xf]==11||tablero[yf][xf]==12||tablero[yf][xf]==13||tablero[yf][xf]==14||tablero[yf][xf]==15)
								{error8=0;}else{error8=1;printf("Movimiento inválido1\n");} break;
						}
					break;
				}
			break;
			case 2://Se mueve más de una casilla
				switch(a){
					case 1:
						switch(b){
							case 1:error8=1;printf("Movimiento inválido\n"); break;
							case 2:if(yi==1 && yf==3){error8=0;}else{error8=1;printf("Movimiento inválido\n");} break;
						}
					break;
					case 2:error8=1;printf("Movimiento inválido\n"); break;
					case 3:error8=1;printf("Movimiento inválido\n"); break;
					default:{error8=1;printf("Movimiento inválido\n");}

				}
			break;
		}	

	break;
}



//-------------------------------------------------------------------------------	
	if(error1 ==0 && error2 ==0 && error3==0 && error4==0 && error5==0 && error6==0 && error7==0 && error8==0){bandera = 0;}else{bandera = 1;}
}while(bandera != 0);

if(tablero[yf][xf]==14){printf("Jugador de fichas negras es el ganador\n");juego=0;}else{
if(tablero[yf][xf]==24){printf("Jugador de fichas blancas es el ganador\n");juego=0;}else{
	juego=1;
}
}


tablero[yf][xf] = tablero[yi][xi];
tablero[yi][xi] = 99;




}while(juego==1);

//------------------------------------------------------


	return 0;
}

//jugador 2 es negras y 1 es blancas
/*
blancas
10 -> torre
11 -> caballo
12 -> alfil
13 ->reina
14 ->rey
15-> peon

negras
20 -> torre
21 -> caballo
22 -> alfil
23 -> reina
24 -> rey
25 -> peon

0 -> vacío
*/