/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void PedirNumero(char mensaje[],float* refNumeroIngresado);
void CalcularCostos(float kilometros, float precioAerolineas, float precioLatam,float* aerolineasConDebito,
		float* latamConDebito,float* aerolineasConCredito,float* latamConCredito,float* precioPorKmLatam,
		float* precioPorKmAerolineas);
void CostoDebito(float precioInicial,float* precioConDescuento);
void CostoCredito(float precioInicial,float* precioConRecargo);
void CostoUnitario(float precioInicial, float km, float* precioPorKm);
void MostrarResultados(float kilometros, float precioAerolineas, float precioLatam,float aerolineasConDebito,
		float latamConDebito,float aerolineasConCredito,float latamConCredito,float precioPorKmLatam,
		float precioPorKmAerolineas);
//void CostoConBitcoin(float precioInicial, float* precioBitcoin);
/*void BaseDeDatos(float precioAerolineas, float precioLatam, float aerolineasConDebito, float latamConDebito,
float aerolineasConCredito, float latamConCredito, float precioPorKmLatam, float precioPorKmAerolineas);*/

int main(void) {
	setbuf(stdout, NULL);
	char salir;
	float aerolineasConDebito;
	float latamConDebito;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	float aerolineasConCredito;
	float latamConCredito;
	float KM;
	float precioLatam;
	float precioAerolineas;
	int flagKm=0;
	int flagVuelos=0;
	int opcion;

	do{
		printf("1-Ingrese (KM=");
		if(flagKm!=0)
		{
			printf("%2.f)\n",KM);
		}
		else
		{
			printf("X)\n");
		}//Vista de KM

		printf("2-Ingresar Precio de Vuelos \n");
		if(flagVuelos!=0)
		{
			printf("(Aerolineas=%2.f , LATAM=%2.f) \n",precioAerolineas, precioLatam);
		}
		else
		{
			printf("(Aerolineas=X , LATAM=Y)\n");
		}//Vista de precios

		printf("3- Calcular costos del vuelo\n");

		printf("4- Mostrar Costos \n");


		scanf("%d",&opcion);//Seleccion de usuario

		switch(opcion)
		{
		case 1:
			PedirNumero("Ingrese los KM a recorrer",&KM);
			flagKm++;
			break;
		case 2:
			PedirNumero("Ingrese precio del vuelo de AEROLINEAS",&precioAerolineas);
			PedirNumero("Ingrese precio del vuelo de LATAM",&precioLatam);
			flagVuelos++;
			break;
		case 3:
			if(flagKm !=0 && flagVuelos!=0)
			{
				CalcularCostos(KM,precioAerolineas,precioLatam,&aerolineasConDebito,&latamConDebito,
								&aerolineasConCredito,&latamConCredito,&precioPorKmLatam,
								&precioPorKmAerolineas);
			}
			else
			{
				printf("Aun faltan cargar Datos");
			}
			break;
		case 4:
			if(flagKm !=0 && flagVuelos!=0)
			{
				MostrarResultados(KM,precioAerolineas,precioLatam,aerolineasConDebito,latamConDebito,
						aerolineasConCredito,latamConCredito,precioPorKmLatam,
						precioPorKmAerolineas);

			}
			else
			{
				printf("Aun faltan cargar Datos");
			}
			break;
		case 6:
			printf("Seguro desea salr ? \n");
			fflush(stdin);
			scanf("%c",&salir);
			salir=tolower(salir);

			if(salir=='s')
			{
				printf("\n ADIOS \n");
			}

			break;

		}//fin swhitch
	}while(salir!='s');
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

void CalcularCostos(float kilometros, float precioAerolineas, float precioLatam,float* aerolineasConDebito,
		float* latamConDebito,float* aerolineasConCredito,float* latamConCredito,float* precioPorKmLatam,
		float* precioPorKmAerolineas)
{
	float aeroConDebito;
	float latamDebito;
	float aeroCredito;
	float latamCredito;
	float latamXKm;
	float aeroXKm;

	CostoDebito(precioAerolineas,&aeroConDebito);
	*aerolineasConDebito=aeroConDebito;
	CostoDebito(precioLatam,&latamDebito);
	*latamConDebito=latamDebito;

	CostoCredito(precioAerolineas,&aeroCredito);
	*aerolineasConCredito=aeroCredito;
	CostoCredito(precioLatam,&latamCredito);
	*latamConCredito=latamCredito;

	CostoUnitario(precioLatam,kilometros,&latamXKm);
	*precioPorKmLatam=latamXKm;
	CostoUnitario(precioAerolineas,kilometros,&aeroXKm);
	*precioPorKmAerolineas=aeroXKm;
}

void CostoCredito(float precioInicial, float* precioConRecargo)
{
	*precioConRecargo=(float)precioInicial*1.25;
}
void CostoDebito(float precioInicial,float* precioConDescuento )
{
	*precioConDescuento=(float)precioInicial*0.9;
}
void CostoUnitario(float precioInicial, float km, float* precioPorKm)
{
	int precioUnitario;
	precioUnitario=precioInicial/km;
	*precioPorKm=precioUnitario;
}
void MostrarResultados(float kilometros, float precioAerolineas, float precioLatam,float aerolineasConDebito,
		float latamConDebito,float aerolineasConCredito,float latamConCredito,float precioPorKmLatam,
		float precioPorKmAerolineas)
{
	printf("Latam:\n");
	printf("Precio con tarjeta de débito: %.2f\n"
			"Precio con tarjeta de crédito: %.2f\n"
			"Precio Unitario: %.2f\n",latamConDebito,latamConCredito,precioPorKmLatam);
	printf("Aerolineas:\n");
	printf("Precio con tarjeta de débito: %.2f\n"
			"Precio con tarjeta de crédito: %.2f\n"
			"Precio Unitario: %.2f\n",aerolineasConDebito,aerolineasConCredito,precioPorKmAerolineas);

}
