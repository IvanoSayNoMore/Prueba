/*Ejercicio 8-2:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos
los siguientes datos:
idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
precio (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y
cuando haya espacio disponible en el array.
//////////////

BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.

MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InPut.h"
#include "Biblioteca_eProducto.h"
#include "ImprimirMostrar.h"
#define MAXIMOPRODUCTO 3
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0

int main(void) {
	setbuf(stdout, NULL);

	//int retornoGetNumero;
	char salida;
	int valida;
	int opcion;
	int numeroAlta;
	eProducto listadoDeProductos[MAXIMOPRODUCTO];
	utnInicializaStructura(listadoDeProductos, MAXIMOPRODUCTO);
	do
	{
		printf("1. Alta\n");
	    printf("2. Mostrar\n");
	    /* printf("3. Borrar producto\n");
	    printf("4. Modificar Producto\n");
	    printf("5. Ordenado Por Precio\n");
	    printf("6. Ordenado Por Descripcion\n");
	    printf("7- ordenar por iphon eeuu\n");*/
	    //opcion = IngresarEntero("Elija una opcion ewe\n");
		printf("8- Salir\n");
		scanf("%d",&opcion);//Seleccion de usuario
		fflush(stdin);//Por si ingresa caracter

		switch(opcion)
		{
		case 1 :
			valida=utnPuntoUnoDeCargaProducto(listadoDeProductos,&numeroAlta, MAXIMOPRODUCTO);//MAXIMOPRODUCTO es la cantidad de listado productos que asigne mas arriba (eProducto listadoDeProductos[MAX];)
			if(valida==RETORNOPOSITIVO)
			{
				printf("Se dio de alta correctamente con el numero: %d \n ",numeroAlta);
			}
			break;

		case 2 :
			valida=utnBuscaEspacioUtilizado(listadoDeProductos, MAXIMOPRODUCTO);
			if(valida==RETORNOPOSITIVO)
			{
				MostrarListadoProducto(listadoDeProductos, MAXIMOPRODUCTO);
			}

		}//fin Switch

	}while(salida!='s');


	return EXIT_SUCCESS;
}
