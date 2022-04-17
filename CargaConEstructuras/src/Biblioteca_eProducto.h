/*
 * Biblioteca_eProducto.h
 *
 *  Created on: 11 abr 2022
 *      Author: Usuario Programador
 */

#ifndef BIBLIOTECA_EPRODUCTO_H_
#define BIBLIOTECA_EPRODUCTO_H_
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFechaIngreso;

typedef struct
{
	int idProducto;
	int numeroDeAlta;
	char modelo[20];
	char madeIn[20];
	char tipo[20];
	int percio;
	int isEmpty;
	eFechaIngreso fechaDeIngreso;
}eProducto;

eProducto IngresarUnProducto();
void utnInicializaStructura(eProducto lista[],int TAM);
int utnEspacioLibreOno(eProducto lista[],int* espacioLibre,int TAM);
int utnPuntoUnoDeCargaProducto(eProducto lista[],int* numeroDeAlta,int TAM);
int utnBuscaEspacioUtilizado(eProducto lista[],int TAM);
int utnBorrarProducto(eProducto lista[],int espacioABorrar,int TAM);
void Alta(int* numeroAlta);
int buscaUnProducto(eProducto lista[],int numAltaProducto,int* indiceEnMemoria,int TAM);


int modificarProducto(eProducto lista[],int indice);
int utnBuscarModificarProducto(eProducto lista[],int altaAModificar, int TAM);
int modificarUnValorDelProducto(int numDeAlta,int valorAModificar);
void utnOrdenarPoPrecio(eProducto lista[],int TAM);
void utnOrdenarPorModelo(eProducto lista[],int TAM);
#endif /* BIBLIOTECA_EPRODUCTO_H_ */
