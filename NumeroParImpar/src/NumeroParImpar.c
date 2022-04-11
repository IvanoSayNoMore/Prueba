/*
 ============================================================================
 Name        : NumeroParImpar.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int ParImpar(int numero);

int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int parOimpar;

	printf("Ingrese un numero");
	scanf("%d",&numeroIngresado);

	parOimpar=ParImpar(numeroIngresado);

	if(parOimpar==1)
	{
		printf("Es par");

	}else
	{
		printf("Es impar");
	}

	return EXIT_SUCCESS;
}
int ParImpar(int numero){
	int resultado;

	resultado=numero%2;

	if(resultado==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
