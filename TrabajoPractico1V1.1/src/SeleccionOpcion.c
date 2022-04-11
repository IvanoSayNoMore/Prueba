/*
 * SeleccionOpcion.c
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */
#include "Calculos.h"
#include "InPut.h"
#include "ImprimirMostrar.h"
#include "BaseDeDatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ENVIA 1
#define IMPRIME 0
#define MINIMO 200
#define MAXIMO 9999999
#define REINTENTOS 3
#define RETORNONEGATIVO 0
#define KMFORZADOS 7090
#define PRECIOAREOLINEASHARDC 762965
#define PRECIOLAMATHARDC 159339
void SeleccionOpcion(int opcion,float* precioAerol,float* precioLt, int* FlagVuelos, int* FlagKm, int* kM,char* Salir)
{
	int retornoGetNumero;
	char salir;
	int salida;
	float aerolineasConDebito;
	float latamConDebito;
	float diferenciaDePrecios;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	float aerolineasConCredito;
	float latamConCredito;
	float KM;
	float precioLatam;
	float precioAerolineas;
	int flagKm=0;
	int flagCalculos=0;
	int flagVuelos=0;


	switch(opcion)
	{
	case 1:
		retornoGetNumero=(utnGetNumero(&KM,"Ingrese los KM a recorrer\n","Se cancela la carga de datos.\n"
				,"Error en la carga de datos, desea intentar nuevamente?\n",MINIMO, MAXIMO, REINTENTOS)==0);

		if(retornoGetNumero==RETORNONEGATIVO)
		{

			puts("Se cancela la operacion y se reinician los KM\n");
			*FlagKm=-1;
		}
		else
		{

			flagVuelos=0;
			*FlagKm=1;
			*kM=KM;
		}
		break;

	case 2:

		retornoGetNumero=(utnGetNumero(&precioAerolineas,"Ingrese precio del vuelo de AEROLINEAS:\n"
				,"Se cancela la carga de datos.\n","Error en la carga de datos, desea intentar nuevamente?\n",MINIMO, MAXIMO, REINTENTOS)==0);
		if(retornoGetNumero==RETORNONEGATIVO)
		{
			puts("Se cancela la operacion\n");
			break;
		}
		else
		{
			*precioAerol=precioAerolineas;
			*FlagVuelos=1;
		}

		retornoGetNumero=(utnGetNumero(&precioLatam,"Ingrese precio del vuelo de LATAM:\n"
				,"Se cancela la carga de datos.\n","Error en la carga de datos, desea intentar nuevamente?\n",MINIMO, MAXIMO, REINTENTOS)==0);
		if(retornoGetNumero==RETORNONEGATIVO)
		{
			puts("Se cancela la operacion\n");
			*FlagVuelos=-1;
			break;
		}
		else
		{
			*precioLt=precioLatam;
		}
		break;

	case 3:
		if(flagKm !=0 && flagVuelos!=0)
		{
			/*utnCalcularCostos(KM,precioAerolineas,precioLatam,&aerolineasConDebito,&latamConDebito,
							&aerolineasConCredito,&latamConCredito,&precioPorKmLatam,
							&precioPorKmAerolineas,&diferenciaDePrecios);

			BaseDeDatos(ENVIA, KM, precioAerolineas, precioLatam, aerolineasConDebito,
					latamConDebito, aerolineasConCredito, latamConCredito,
					precioPorKmAerolineas, precioPorKmLatam, diferenciaDePrecios);
			*/
			flagCalculos++;
			puts("Se han calculado los costos exitosamente.\n\n");
		}
		else
		{
			printf("Aun faltan cargar Datos\n");
		}
		break;

	case 4:
		if(flagCalculos)
		{

			flagCalculos=0;
			flagKm=0;
			flagVuelos=0;
		}
		else
		{
			printf("Aun faltan cargar y/o calcular los datos");
		}
		break;

	case 5:
		utnCalcularCostos(KMFORZADOS,PRECIOAREOLINEASHARDC,PRECIOLAMATHARDC,&aerolineasConDebito,&latamConDebito,
										&aerolineasConCredito,&latamConCredito,&precioPorKmLatam,
								  		&precioPorKmAerolineas,&diferenciaDePrecios);
		utnMostrarResultados(KMFORZADOS,PRECIOAREOLINEASHARDC,PRECIOLAMATHARDC,aerolineasConDebito,latamConDebito,
				aerolineasConCredito,latamConCredito,precioPorKmLatam,
				precioPorKmAerolineas,diferenciaDePrecios);


		break;

	case 6:
		salida=utnVerificacionConChar("Seguro desea salir  ?s o n \n","\n ADIOS \n");
		if(salida==-1)
		{
			salir='s';
			break;
		}

		break;
	default:
		puts("\n\nError en la seleccion de la opcion\n\n");
		break;

	}//fin swhitch
}

