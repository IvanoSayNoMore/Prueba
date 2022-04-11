/*
 ============================================================================
Clase 3
Ejercicio 3-1:
Crear una funci�n que permita determinar si un n�mero es par o no. La funci�n retorna 1 en caso afirmativo y 0
 en caso contrario. Probar en el main.
Ejercicio 3-2:
Crear una funci�n que muestre por pantalla el n�mero flotante que recibe como par�metro.
Ejercicio 3-3:
Crear una funci�n que pida el ingreso de un entero y lo retorne.
Ejercicio 3-4:
Realizar un programa en donde se puedan utilizar los prototipos de la funci�n Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void PedirNumero(char mensaje[],float* refNumeroIngresado);
int ParImpar(float numero);
int main(void) {
	float numero;
	int retornoParImpar;
	PedirNumero("Ingrese numero:\n",&numero);
	retornoParImpar=ParImpar(numero);

	if(retornoParImpar==1)
	{
		printf("Es par\n");
	}
	else
	{
		printf("Es impar\n");
	}

	return EXIT_SUCCESS;
}
int ParImpar(float numero)
{
	int retorno;
	float resto;
	retorno=0;
	resto=(int)numero%2;
	if(resto==0)
	{
		retorno=1;
	}
	return retorno;
}
void PedirNumero(char mensaje[],float* refNumeroIngresado)
{
	setbuf(stdout, NULL);
	float numeroIngresado;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&numeroIngresado);
	*refNumeroIngresado=numeroIngresado;
}
