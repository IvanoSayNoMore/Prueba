/*
 * File_eProducto.c
 *
 *  Created on: 11 abr 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InPut.h"
#include "Biblioteca_eProducto.h"
#define EMPTY 0
#define FULL -1
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0
#define REINTENTOS 3
#define MINIMONUM 0
#define MAXIMONUM 1000
#define MAXIMOCADENA 20

void utnInicializaStructura(eProducto lista[], int TAM)
{
	int i;
	for(i=0;i<TAM-1;i++)
	{
		lista[i].isEmpty=EMPTY;
	}
}

int utnEspacioLibreOno(eProducto lista[],int* espacioLibre,int TAM)
{
	int retorno=-1;//devuelve -1 si no encontro espacio
	int i;

	for(i=0;i<TAM-1;i++)
	{
		if(lista[i].isEmpty==EMPTY)
		{
			*espacioLibre=i;
			retorno=0;//devuelve 0 cuando encontro el espacio libre
			break;
		}

	}

	return retorno;
}
int utnBuscaEspacioUtilizado(eProducto lista[],int TAM)
{
	int retorno=-1;//devuelve -1 si no encontro espacio
	int i;

	for(i=0;i<TAM-1;i++)
	{
		if(lista[i].isEmpty==FULL)
		{
			retorno=0;//devuelve 0 cuando encontro el espacio libre
			break;
		}

	}

	return retorno;
}

int utnPuntoUnoDeCargaProducto(eProducto lista[],int* numeroDeAlta,int TAM)
{
	int retorno=RETORNONEGATIVO;
	int espacioAsignado;
	int validacion;
	validacion=utnEspacioLibreOno(lista, &espacioAsignado, TAM);
	if(validacion==RETORNOPOSITIVO)
	{
		lista[espacioAsignado]=IngresarUnProducto();
		if(lista[espacioAsignado].isEmpty==FULL)
		{
			retorno=RETORNOPOSITIVO;
			*numeroDeAlta=espacioAsignado;
		}
	}
	return retorno;
}
eProducto IngresarUnProducto(){
    eProducto producto;
    int valida;
    int opcion=0;
	eFechaIngreso fechaIngreso;
	char salir;
	int auxNumeroId;
	int auxPrecio;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxTipo[20];
	char auxCadenaDesc[20];
	char auxCadenaNaci[20];
	int flagOk=0;

	do{
		switch(opcion)
		{
			case 0:
					////////////////////////////
					// idProducto
					valida=utnGetNumero(&auxNumeroId, "Ingrese el ID del Celular: \n", "Ocurrio un error al cargar datos:\n",
							"Error al cargar datos. Desea volver a intentar ?:\n", MINIMONUM, MAXIMONUM, REINTENTOS);
					if(valida==0)
					{
						flagOk++;
					}
					else
					{
						break;
					}
					////////////////////////////
					//descripcion (alfanumérico)
					if(flagOk==1)
					{
						valida=utnIngresarAlfanumerico(auxCadenaDesc, "Ingrese La descricion:\n", MAXIMOCADENA);
					}
					if(valida==-1)
					{
						flagOk=0;
						break;
					}
					////////////////////////////
					//Tipo (alfanumérico)
					if(flagOk==1)
					{
						valida=utnIngresarAlfanumerico(auxTipo, "Ingrese La marca(tipo):\n", MAXIMOCADENA);
					}
					if(valida==-1)
					{
						flagOk=0;
						break;
					}
					////////////////////////////
					//nacionalidad
					if(flagOk==1)
					{
						valida=utnRecibeCadenaSoloCaracteres(auxCadenaNaci, "Ingrese Nacionalidad: \n",
								REINTENTOS, MAXIMOCADENA);
					}
					if(valida==-1)
					{
						flagOk=0;
						break;
					}
					////////////////////////////
					//Precio
					if(flagOk==1)
					{
						valida=utnGetNumero(&auxPrecio, "Ingrese el precio: \n", "Ocurrio un error",
														"Desea continuar?", MINIMONUM, MAXIMONUM, REINTENTOS);
					}
					if(valida==-1)
					{

						flagOk=0;
						break;
					}
					////////////////////////////
					//Anio Fabricacion
					if(flagOk==1)
					{
						valida=utnGetNumero(&auxAnio, "Ingrese año de fabricacion: \n", "Ocurrio un error \n",
								"Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
					}
					if(valida==-1)
					{
						flagOk=0;
						break;
					}
					////////////////////////////
					//Dia Fabricacion
					if(flagOk==1)
					{
						valida=utnGetNumero(&auxDia, "Ingrese el dia de  fabricacion: \n", "Ocurrio un error \n",
								"Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
					}
					if(valida==-1)
					{
						flagOk=0;;
						break;
					}
					////////////////////////////
					//Mes Fabricacion
					if(flagOk==1)
					{
						valida=utnGetNumero(&auxMes, "Ingrese el mes de fabricacion: \n", "Ocurrio un error \n",
								"Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
					}
					if(valida==-1)
					{
						flagOk=0;
						break;
					}
					else
					{
						salir='s';
					}
		}//Fin Switch


		if(flagOk==0)
		{
			valida=utnVerificacionConChar("Ocurrio un error al cargar datos. Desea volver a intentar?s o n \n",
					"\n ADIOS \n");
			if(valida==-1)
			{
				salir='s';
			}
		}

	}while(salir!='s');

	if(flagOk)
	{
		producto.idProducto=auxNumeroId;
		strcpy(producto.descripcion,auxCadenaDesc);
		strcpy(producto.madeIn,auxCadenaNaci);
		strcpy(producto.tipo,auxTipo);
		producto.percio=auxPrecio;
		fechaIngreso.anio=auxAnio;
		fechaIngreso.dia=auxDia;
		fechaIngreso.mes=auxMes;
		producto.fechaDeIngreso=fechaIngreso;
		producto.isEmpty=FULL;
	}

	return producto;

}


