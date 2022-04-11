/*
 ============================================================================
a-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void PedirNumero(char mensaje[],float* refNumeroIngresado);
void realizarDescuento(float precioInicial,float* precioConDescuento );
int ValidarNumero(int numero);
int main(void) {
	float numero1;
	int retornoValidacion;
	float precioDescuento;

	retornoValidacion=ValidarNumero(numero1);
	if(retornoValidacion==1)
	{
		printf("El numero esta entre el 10 y 100\n");
	}
	else
	{
		printf("No esta entre 10 y 100\n");
	}
	realizarDescuento(numero1,&precioDescuento);
	printf("Con descuento %.2f\n",precioDescuento);


	return EXIT_SUCCESS;
}
void realizarDescuento(float precioInicial,float* precioConDescuento )
{
	*precioConDescuento=(float)precioInicial*0.95;
}
int ValidarNumero(int numero)
{
	int retorno=0;
	if(numero>=10&&numero<=100)
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
