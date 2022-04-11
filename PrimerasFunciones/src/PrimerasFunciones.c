/*
 ============================================================================
 Name        : PrimerasFunciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

void PromedioNumeros(float nota1, float nota2, float* promedio);
void PedirNumero(char mensaje[], float* numero);
void Suma(float numA, float numB, float* resultado);
void Resta(float numA, float numB, float* resultado);
void Multiplicacion(float numA, float numB, float* resultado);
int Division(float numA, float numB, float* resultado);


int main(void) {
	setbuf(stdout, NULL);
	float num1;
	float num2;
	float resultadoPromedio;
	float resultadoSuma;
	float resultadoMult;
	float resultadoResta;
	float retornoDivision;
	float resultadoDivision;

	PedirNumero("Ingrese numero 1: ",&num1);
	PedirNumero("Ingrese numero 2: ",&num2);

	PromedioNumeros(num1,num2,&resultadoPromedio);
	printf("El promedio es de: %.2f\n",resultadoPromedio);


	Suma(num1,num2,&resultadoSuma);
	printf("El resultado de la suma es : %2.f\n",resultadoSuma);

	Resta(num1,num2,&resultadoResta);
	printf("El resultado de la resta es : %2.f\n",resultadoResta);

	Multiplicacion(num1,num2,&resultadoMult);
	printf("El resultado de su multiplicacion ess : %2.f\n",resultadoMult);

	retornoDivision=Division(num1,num2,&resultadoDivision);
	if(retornoDivision!=0)
	{
		printf("El resultado de la division ess : %2.f\n",resultadoDivision);
	}
	else
	{
		printf("No se puede dividir por 0.\n");
	}



	return 0;

}
void PromedioNumeros(float nota1, float nota2, float* promedio)
{
	*promedio=(float)(nota1 + nota2)/2;


}
void PedirNumero(char mensaje[],float* numero)
{
	setbuf(stdout, NULL);
	float numeroIngresado;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&numeroIngresado);
	*numero=numeroIngresado;

}
void Suma(float numA, float numB, float* resultado)
{
	*resultado=numA+numB;

}
void Multiplicacion(float numA, float numB, float* resultado)
{
	*resultado=numA*numB;
}
void Resta(float numA, float numB, float* resultado)
{
	*resultado=numA-numB;
}
int Division(float numA, float numB, float* resultado)
{
	int retorno=0;
	if(numB!=0)
	{
		*resultado=(float)numA/numB;

		retorno=1;
	}
	return retorno;
}
