/*
 ============================================================================
b-Funciones
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- Valide los mismos entre 10 y 100
- Asigne a la variable operacion el valor solicitado al usuario
- Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void PedirNumero(char mensaje[],float* refNumeroIngresado);
void Suma(float numeroA, float numeroB,float* refResultadoSuma);
void Resta(float numeroA, float numeroB,float* refResultadoResta);

int main(void) {
	float numero1;
	float numero2;
	char operacion;
	float refResultadoSuma;
	float refResultadoResta;

	PedirNumero("Ingrese numero a:\n",&numero1);
	PedirNumero("Ingrese numero b:\n",&numero2);

	printf("Que operacion desea realizar S para suma R para resta\n");
	fflush(stdin);
	scanf("%c",&operacion);
	operacion=tolower(operacion);
	switch(operacion)
	{
	case 's':
		Suma(numero1,numero2,&refResultadoSuma);
		printf("El resultado de la suma : %.2f",refResultadoSuma);
		break;
	case 'r':
		Resta(numero1,numero2,&refResultadoResta);
		printf("El resultado de la resta : %.2f",refResultadoResta);
		break;
	}

	return EXIT_SUCCESS;
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

void Suma(float numeroA, float numeroB,float* refResultadoSuma)
{
	*refResultadoSuma=numeroA+numeroB;
}


void Resta(float numeroA, float numeroB,float* refResultadoResta)
{
	*refResultadoResta=numeroA-numeroB;
}
