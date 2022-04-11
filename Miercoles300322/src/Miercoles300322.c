/*
 ============================================================================
 Name        : Miercoles300322.c
 Author      : Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir 5 numeros y mstrar mayor y menor
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define LIMITE 5
int main(void) {
	setbuf(stdout, NULL);
	int numeroMayor;
	int numeroMenor;
	int numero;
	int i;
	//int flag =FALSE;

	for(i=0;i<LIMITE;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d",&numero);

		//if(flag==FALSE || numeroMayor<numero )
		if(i==0 || numeroMayor<numero)
		{
			numeroMayor=numero;
		}
		//if(flag==FALSE||numeroMenor>numero)
		if(i==0 || numeroMenor>numero)
		{
			numeroMenor=numero;
			//flag=TRUE;
		}
	}//Fin For

	printf("Numero Mayor fue %d\n",numeroMayor);
	printf("Numero Menor fue %d\n",numeroMenor);

	return 0;
}
