/*
 * InPuts.h
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#ifndef INPUT_H_
#define INPUT_H_
int utnMyGets(char* cadena, int longitud);
int utnGetInt(int* pResultado);
int utnGetNumero(int* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos);
int utnEsNumerica(char* cadena);
int utnVerificacionConChar(char* mensajeValidacion,char* mensajeFinal);
int utnIngresarAlfanumerico(char cadena[], char mensaje[], int tam);
int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam);
char utnIngresarChar(char mensaje[]);
#endif /* INPUT_H_ */
