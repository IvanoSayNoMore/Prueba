/*
 ============================================================================
 Name        : PromedioDosNotas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float PromedioNumeros(int nota1, int nota2);

void PedirNumero(char mensaje[], int* numero);

int main(void) {
	setbuf(stdout, NULL);

	int num1;
	int num2;
	float resultado;

	/*printf("Ingrese primer numero: ");
	scanf("%d",&num1);

	printf("Ingrese segundo numero: ");
	scanf("%d",&num2);*/

	PedirNumero("Ingrese numero 1: ",&num1);
	PedirNumero("Ingrese numero 2: ",&num2);

	resultado=PromedioNumeros(num1,num2);
	printf("El promedio es de: %.2f",resultado);

	return 0;
}
float PromedioNumeros(int nota1, int nota2)
{
	float promedio;
	//CASTEO
	//promedio=((float)nota1 + nota2)/2;
	promedio=(float)(nota1 + nota2)/2;

	return promedio;
}
void PedirNumero(char mensaje[],int* numero)
{
	setbuf(stdout, NULL);
	float numeroIngresado;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&numeroIngresado);
	*numero=numeroIngresado;

}
