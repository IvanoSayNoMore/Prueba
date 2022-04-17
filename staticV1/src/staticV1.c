/*
 ============================================================================
 Name        : staticV1.c
 Author      : Ivan Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
static void func(int* num);
static void func(int* num)
{
	static int x=0;
	printf("%d\n\n",x);
	x++;
	printf("%d\n\n",x);
	*num=x;
}
int main(void)
{
	int aux;
	func(&aux); // muestra 0
	printf("aa%d\n\n",aux);
	func(&aux); // muestra 1
	printf("bb%d\n\n",aux);
	func(&aux); // muestra 2
	printf("cc%d\n\n",aux);
	return EXIT_SUCCESS;
}
