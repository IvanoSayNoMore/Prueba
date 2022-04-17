/*
 ============================================================================
 Name        : parcialito.c
 Author      : Ivan Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int funcionParcialito(int numA, int numB, int* numC);
int main(void) {
	int numD;
	int numeroA=12;
	int numeroB=14;
	int numeroC;

	numD=funcionParcialito(numeroA, numeroB,&numeroC);

	printf("%d \n %d\n",numD,numeroC);
	return EXIT_SUCCESS;
}
int funcionParcialito(int numA, int numB, int* numC)
{
	int retorno;
	if(numA>numB)
	{
		*numC=numA;
		retorno=numB;
	}
	else
	{
		*numC=numB;
		retorno=numA;
	}
	return retorno;
}
