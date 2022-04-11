/*
 ============================================================================
 Name        : 1.c
 Author      : Ivan Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SeleccionOpcion.h"
#include "BaseDeDatos.h"


int main(void) {
	setbuf(stdout, NULL);
	float precioAerolineas;
	float precioLatam;
	float auxPrecioAerolineas;
	float auxPrecioLatam;
	float KM;
	float auxKM;
	int flagPrecioVuelos=0;
	int flagKm;
	int opcion;
	char salir;
	int peticiones=0;


	do{
		printf("\n1- Ingrese (KM=");
		if(flagKm==1 || KM!=NULL)
		{
			printf("%2.f)\n",KM);
		}
		else
		{
			printf("X)\n");
		}//Vista de KM

		printf("2- Ingresar Precio de Vuelos \n");
		if(flagPrecioVuelos==1||precioAerolineas!=NULL)
		{
			printf("(Aerolineas=%2.f , LATAM=%2.f) \n",precioAerolineas, precioLatam);
		}
		else
		{
			printf("(Aerolineas=X , LATAM=Y)\n");
		}//Vista de precios

		printf("3- Calcular costos del vuelo\n");

		printf("4- Mostrar Costos \n");

		printf("5- Carga Forzada\n");

		printf("6- Salir\n");
		scanf("%d",&opcion);//Seleccion de usuario
		fflush(stdin);//Por si ingresa caracter

		SeleccionOpcion(opcion, &auxPrecioAerolineas, &auxPrecioLatam, &flagPrecioVuelos, &flagKm, &auxKM, &salir);
		if(flagKm)
		{
			KM=auxKM;
		}
		else
		{
			if(flagKm==-1)
			{
				KM=NULL;
			}
		}
		if(flagPrecioVuelos)
		{
			precioAerolineas=auxPrecioAerolineas;
			precioLatam=auxPrecioLatam;
		}
		else
		{
			if(flagPrecioVuelos==-1)
			{
				precioAerolineas=NULL;
			}
		}//aca quede, falta el envio a la base de datos. como ?



	}while(salir!='s');//Fin Menu
	return EXIT_SUCCESS;
}

