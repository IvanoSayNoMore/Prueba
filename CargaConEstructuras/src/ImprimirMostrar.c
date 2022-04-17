/*
 * ImprimirMostrar.c
 *
 *  Created on: 11 abr 2022
 *      Author: Usuario Programador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca_eProducto.h"
#include "ImprimirMostrar.h"
#define EMPTY 0
#define FULL -1
void MostrarListadoProducto(eProducto producto[], int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(producto[i].isEmpty==FULL)
		{	puts("|Numero de id  | Descripcion  |    Tipo     |    Precio     |  Fabricado en | Fecha de Fabricacion |");
			MostrarUnEmpleado(producto[i]);
		}
	}
}
void MostrarUnEmpleado(eProducto producto)
{

	printf("|%d            |%s            | %s          | %d            |  %s           | %d|%d|%d            | \n",
			producto.numeroDeAlta,producto.modelo,producto.tipo,producto.percio,producto.madeIn,
			producto.fechaDeIngreso.dia,producto.fechaDeIngreso.mes,producto.fechaDeIngreso.anio);
	printf("\n\nNumero de alta: %d\n",producto.numeroDeAlta);
}
