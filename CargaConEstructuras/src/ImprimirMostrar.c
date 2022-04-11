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
	for(i=0;i<tam-1;i++)
	{
		if(producto[i].isEmpty==FULL)
		{
			MostrarUnEmpleado(producto[i]);
		}
	}
}
void MostrarUnEmpleado(eProducto producto)
{
	  puts("|Numero de id  | Descripcion  |    Tipo     |    Precio     |  Fabricado en | Fecha de Fabricacion |");
	printf("|%d            |%s            | %s          | %d            |  %s           | %d|%d|%d             | \n",
			producto.idProducto,producto.descripcion,producto.tipo,producto.percio,producto.madeIn,
			producto.fechaDeIngreso.dia,producto.fechaDeIngreso.mes,producto.fechaDeIngreso.anio);
}
