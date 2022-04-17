/*
 ============================================================================
 Name        : static.c
 Author      : Ivan Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*---------------------------------------------------------------------/

Funcion que permite obtener y conservar un valor "contador".
Dicho valor se le asigna en esta funcion a una variable x.
La mimsa, se imprime y luego se le suma un +1.
La variable x cambia de valor , y para la proxima vuelta , no sera 0.

---------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
void contadorEnFuncion();
int main(void) {
	contadorEnFuncion();
	contadorEnFuncion();
	contadorEnFuncion();
	return EXIT_SUCCESS;
}
void contadorEnFuncion() {
	static int x = 0;
	printf("%d\n", x);
	x = x + 1;
}
