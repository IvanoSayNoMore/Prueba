/*
 * BaseDeDatos.c
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */
#define CANTIDADDEDATOS 7
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ImprimirMostrar.h"

void BaseDeDatos(int enviaRecive,float datoAconDescuento,float datoBconDescuento,float datoAconAumento,float datoBconAumento,
		float datoAporUnidad, float datoBporUnidad, float diferenciaAyB)
{
	int pivot;
	int DatoA;
	int DatoB;
	float datosAdescuento;
	float datosBdescuento;
	float datosAcredito;
	float datosBcredito;
	float datoAxUnidad;
	float datoBxUnidad;
	float diferencias;
	if(enviaRecive==1)
	{
		datosAdescuento=datoAconDescuento;
		datosBdescuento=datoBconDescuento;
		datosAcredito=datoAconAumento;
		datosBcredito=datoBconAumento;
		datoAxUnidad=datoAporUnidad;
		datoBxUnidad=datoBporUnidad;
		diferencias=diferenciaAyB;
	}
	else
	{
		utnMostrarResultados(pivot,DatoA,DatoB,datosAdescuento,datosBdescuento,
				datosAcredito,datosBcredito,datoBxUnidad,
				datoAxUnidad,diferencias);
	}

}
void BaseDeDatosIngresados(int enviaRecive, int datoPivot, int datoA, int datoB, int* pivot, int* datoX, int* datoY)
{
	int auxDatoPivot;
	int auxDatoA;
	int auxDatoB;

	if(enviaRecive==1)
	{
		auxDatoPivot=datoPivot;
		auxDatoA=datoA;
		auxDatoB=datoB;
	}
	else
	{
		*pivot=auxDatoPivot;
		*datoX=auxDatoA;
		*datoY=auxDatoB;
	}

}
