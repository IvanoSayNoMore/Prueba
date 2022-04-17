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
	int auxiliar;
	//int numeroAlta;
	eProducto listadoDeProductos[MAXIMOPRODUCTO]={{1000,1,"A Samsung","Argentina","S1 2",15000,-1,{19,04,93}},{2000,2,"B nokia","bolivia","mil100",10000,-1,{19,04,93}},{3000,3,"C LG","Bolivia","gt",18000,-1,{19,04,93}}};
	//utnInicializaStructura(listadoDeProductos, MAXIMOPRODUCTO);
	do
	{
		printf("1. Alta\n");
	    printf("2. Mostrar\n");
	    printf("3. Borrar producto\n");
	    printf("4. Modificar Producto\n");
	    printf("5. Ordenado Por Precio\n");
	    printf("6. Ordenado Por Modelo\n");
	    /*printf("7- ordenar por iphon eeuu\n");*/
	    //opcion = IngresarEntero("Elija una opcion ewe\n");
		printf("8- Salir\n");
		scanf("%d",&opcion);//Seleccion de usuario
		fflush(stdin);//Por si ingresa caracter

		switch(opcion)
		{
		//case 1 :
			/*//valida=utnPuntoUnoDeCargaProducto(listadoDeProductos,&numeroAlta, MAXIMOPRODUCTO);//MAXIMOPRODUCTO es la cantidad de listado productos que asigne mas arriba (eProducto listadoDeProductos[MAX];)

			if(valida==RETORNOPOSITIVO)
			{
				printf("Se dio de alta correctamente con el numero: %d \n ",numeroAlta);
			}
			break;*/

		case 2 :
			valida=utnBuscaEspacioUtilizado(listadoDeProductos, MAXIMOPRODUCTO);
			if(valida==RETORNOPOSITIVO)
			{
				MostrarListadoProducto(listadoDeProductos, MAXIMOPRODUCTO);
			}
			break;

		case 3:
			valida=utnGetNumero(&auxiliar, "Ingrese el numero de alta a borrar. \n", "Error" ,"Seguir?", 1, 50, 5);
			if(valida==0)
			{

				valida=utnBorrarProducto(listadoDeProductos, auxiliar, MAXIMOPRODUCTO);
			}
			else
			{
				puts("Se cancela el borrado");
			}

			break;

		case 4:
			valida=utnGetNumero(&auxiliar, "Ingrese el numero de alta a Modificar. \n", "Error" ,"Seguir?", 1, 50, 5);
			if(valida==0)
			{
				//printf("\n%d \n%d\n",valida,auxiliar);
				valida=utnBuscarModificarProducto(listadoDeProductos,auxiliar, MAXIMOPRODUCTO);
			}
			else
			{
				puts("Se cancela la modificacion");
			}

			break;

		case 5:
			utnOrdenarPoPrecio(listadoDeProductos, MAXIMOPRODUCTO);

			break;
		case 6:
			utnOrdenarPorModelo(listadoDeProductos, MAXIMOPRODUCTO);
			break;

		}//fin Switch

	}while(salida!='s');


	return EXIT_SUCCESS;
}
