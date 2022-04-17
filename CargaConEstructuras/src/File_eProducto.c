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
#include "ImprimirMostrar.h"
#define EMPTY 0
#define FULL -1
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0
#define REINTENTOS 3
#define MINIMONUM 0
#define MAXIMONUM 40000
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
	int numDeAlta;

	validacion=utnEspacioLibreOno(lista, &espacioAsignado, TAM);
	if(validacion==RETORNOPOSITIVO)
	{
		lista[espacioAsignado]=IngresarUnProducto();
		if(lista[espacioAsignado].isEmpty==FULL)
		{
			Alta(&numDeAlta);
			lista[espacioAsignado].numeroDeAlta=numDeAlta;
			retorno=RETORNOPOSITIVO;
			*numeroDeAlta=numDeAlta;
		}
	}
	return retorno;
}

void Alta(int* numeroAlta)
{
	static int altaNumero=0;
	altaNumero=altaNumero+1;
	*numeroAlta=altaNumero;
}

eProducto IngresarUnProducto(){
    eProducto producto;
    int valida;

	eFechaIngreso fechaIngreso;
	char salir;
	int auxNumeroId;
	int auxPrecio;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxTipo[20];
	char auxCadenaModelo[20];
	char auxCadenaNaci[20];
	int flagOk=0;

	do{

			////////////////////////////
			// idProducto
			valida=utnGetNumero(&auxNumeroId, "Ingrese el ID del Celular: \n", "Ocurrio un error al cargar datos:\n",
					"Error al cargar datos. Desea volver a intentar ?:\n", MINIMONUM, MAXIMONUM, REINTENTOS);
			printf("%d",valida);
			if(valida==0)
			{
				flagOk++;
			}
			////////////////////////////
			//Modelo (alfanumérico)
			if(flagOk==1)
			{
				valida=utnIngresarAlfanumerico(auxCadenaModelo, "Ingrese el modelo:\n", MAXIMOCADENA);
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
				valida=utnIngresarAlfanumerico(auxTipo, "Ingrese La marca:\n", MAXIMOCADENA);
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
				valida=utnGetNumero(&auxPrecio, "Ingrese el precio: \n", "Ocurrio un error \n",
												"Recuerde que el maximo es de 40000. Solo ingrese numeros\n Desea continuar? \n", MINIMONUM, MAXIMONUM, REINTENTOS);
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
						"Puso una fecha incorrecta\n  Solo ingrese numeros\n Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
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
							"Puso una fecha incorrecta\n . Solo ingrese numeros\n Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
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
						"Puso una fecha incorrecta\n Solo ingrese numeros\n Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
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
		strncpy(producto.modelo,auxCadenaModelo,sizeof(producto.modelo));
		strncpy(producto.madeIn,auxCadenaNaci,sizeof(producto.madeIn));
		strncpy(producto.tipo,auxTipo,sizeof(producto.tipo));
		producto.percio=auxPrecio;
		fechaIngreso.anio=auxAnio;
		fechaIngreso.dia=auxDia;
		fechaIngreso.mes=auxMes;
		producto.fechaDeIngreso=fechaIngreso;
		producto.isEmpty=FULL;
	}

	return producto;

}

int utnBorrarProducto(eProducto lista[],int altaABorrar,int TAM)
{
	int retorno=-1;
	int i;
	int validar;
	int indice;
	validar=buscaUnProducto(lista, altaABorrar, &indice, TAM);
	if(validar==-1)
	{
		puts("No se encontro el alta .\n");
	}
	else
	{
		for(i=0;i<TAM-1;i++)
		{
			if(lista[i].idProducto==altaABorrar && lista[i].isEmpty==FULL)
			{
				lista[i].isEmpty=EMPTY;
				retorno=0;
				break;
			}

		}//Fin for
	}//Fin else

	return retorno;
}

int modificarProducto(eProducto lista[],int indice)
{
	int retorno=0;
	char salir;
	int validar;
	int opcion;
	//int flag=0;
	int aux;
	char auxCadena[20];
	do
	{

	puts("\nOpcion 1: Dia"
		 "\nOpcion 2: Mes"
		 "\nOpcion 3: año"
		 "\nOpcion 4: Marca"
		 "\nOpcion 5: Modelo"
		 "\nOpcion 6: Nacionalidad"
		 "\nOpcion 7: Precio\n");
	validar=utnGetNumero(&opcion, "Si desea cambiar uno por uno, ingrese 0, sino, alguna de las opciones ?",
			"La opcion ingresada es incorrecta", "Error al ingresar, desea volver a intentar?", 0, 7, REINTENTOS);

	if(validar==0)
	{
		switch(opcion)
		{
		/*case 0:
			flag++;*/

		case 1:
			////////////////////////////
			validar=utnGetNumero(&aux, "Ingrese el dia de  fabricacion: \n", "Ocurrio un error \n",
						"Puso una fecha incorrecta\n . Solo ingrese numeros\n Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
			if(validar==0)
			{
				lista[indice].fechaDeIngreso.dia=aux;
				break;
			}
			else
			{
				puts("Se cancela la modificacion");
				retorno=-1;
				break;
			}

		case 2:
			validar=utnGetNumero(&aux, "Ingrese el mes de  fabricacion: \n", "Ocurrio un error \n",
						"Puso una fecha incorrecta\n . Solo ingrese numeros\n Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
			if(validar==0)
			{
				lista[indice].fechaDeIngreso.mes=aux;
				break;
			}
			else
			{
				retorno=-1;
				puts("Se cancela la modificacion");
				break;
			}
		case 3:
			validar=utnGetNumero(&aux, "Ingrese el año de  fabricacion: \n", "Ocurrio un error \n",
						"Puso una fecha incorrecta\n . Solo ingrese numeros\n Desea continuar? \n",  MINIMONUM, MAXIMONUM, REINTENTOS);
			if(validar==0)
			{
				lista[indice].fechaDeIngreso.anio=aux;
				break;
			}
			else
			{
				puts("Se cancela la modificacion");
				retorno=-1;
				break;
			}
		case 4:
			//Marca (alfanumérico)

			validar=utnIngresarAlfanumerico(auxCadena, "Ingrese el modelo:\n", MAXIMOCADENA);

			if(validar==0)
			{
				strncpy(lista[indice].tipo,auxCadena,sizeof(lista[indice].tipo));
				break;
			}
			else
			{
				retorno=-1;
				puts("Se cancela la modificacion");
				break;

			}

		case 5:
			validar=utnIngresarAlfanumerico(auxCadena, "Ingrese el modelo:\n", MAXIMOCADENA);
			if(validar==0)
			{
				strncpy(lista[indice].modelo,auxCadena,sizeof(lista[indice].modelo));
				break;
			}
			else
			{
				retorno=-1;
				puts("Se cancela la modificacion");
				break;

			}

		case 6:
			validar=utnRecibeCadenaSoloCaracteres(auxCadena, "Ingrese Nacionalidad: \n",
					REINTENTOS, MAXIMOCADENA);
			if(validar==1)
			{
				strncpy(lista[indice].madeIn,auxCadena,sizeof(lista[indice].madeIn));
				break;
			}
			else
			{
				retorno=-1;
				puts("Se cancela la modificacion");
				break;
			}

		case 7:
			validar=utnGetNumero(&aux, "Ingrese el precio: \n", "Ocurrio un error \n",
				"Recuerde que el maximo es de 40000. Solo ingrese numeros\n Desea continuar? \n", MINIMONUM, MAXIMONUM, REINTENTOS);

			if(validar==0)
			{
				lista[indice].percio=aux;
				break;
			}
			else
			{
				retorno=-1;
				puts("Se cancela la modificacion");
				break;
			}

		default:
			retorno=-1;
			puts("Error de seleccion");
			break;

		}//fin switch
	}//fin if
	validar=utnVerificacionConChar("Desea continuar modificando(s) o (n) ? ", "\n\nAdios\n\n");
	if(validar==-1)
	{
		salir='s';
	}
	}while(salir!='s');
	return retorno;

}

int utnBuscarModificarProducto(eProducto lista[],int altaAModificar, int TAM)
{

	int retorno;
	int aux;
	int auxIndice;

	aux=buscaUnProducto(lista,altaAModificar,&auxIndice,3);

	if(aux==0)
	{
		printf("El producto a modificar es : \n");
		MostrarUnEmpleado(lista[auxIndice]);
		aux=utnVerificacionConChar("Desea continuar ? S o N", "Se cancela la modificacion");
		if(aux==0)
		{
			aux=modificarProducto(lista,auxIndice);
		}
	}
	retorno=0;


	return retorno;
}

int buscaUnProducto(eProducto lista[],int numAltaProducto,int* indiceEnMemoria,int TAM)
{
	int retorno=-1;//devuelve -1 si no encontro el producto
	int i;

	for(i=0;i<TAM-1;i++)
	{
		if(lista[i].numeroDeAlta==numAltaProducto && lista[i].isEmpty==FULL)
		{
			*indiceEnMemoria=i;
			retorno=0;//devuelve 0 cuando encontro al producto
			break;
		}

	}

	return retorno;
}

void utnOrdenarPoPrecio(eProducto lista[],int TAM)
{
    eProducto auxiliarProducto;

	for(int i=0; i<TAM-1; i++)
	{
		for(int j=i+1; j<TAM; j++)
		{
			if(lista[i].percio>lista[j].percio)
			{
				auxiliarProducto = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarProducto;
			}//
		}//For j
	}//For i
}

void utnOrdenarPorModelo(eProducto lista[],int TAM)
{
    eProducto auxiliarProducto;

	for(int i=0; i<TAM-1; i++)
	{
		for(int j=i+1; j<TAM; j++)
		{
			if(strncmp(lista[i].modelo,lista[j].modelo,sizeof(lista[i].modelo))<0)
			{
				auxiliarProducto = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarProducto;
			}//
		}//For j
	}//For i

}


























