/*
 * Bibliotecas.h
 *
 *  Created on: 6 abr 2022
 *      Author: Usuario Programador
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

void utnCalcularCostos(float parametroPivot, float parametroA, float parametroB,float* parametroAconDescuento,
		float* parametroBconDescuento,float* parametroAconAumento,float* parametroBconAumento,float* valorPorUnidadParametroB,
		float* valorPorUnidadParametroA,float* difDeValores);
void utnCostoConDescuento(float precioInicial,float* precioConDescuento);
void utnCostoConAumento(float precioInicial,float* precioConRecargo);
void utnCostoUnitario(float precioInicial, float undiad, float* precioPorUnidad);
void utnDiferenciaDeValores(float valorA, float valorB, float* valorResultado);
void utnMostrarResultados(float parametroPivot, float parametroA, float parametroB,float parametroAconDescuento,
		float parametroBconDescuento,float parametroAconAumento,float parametroBconAumento,float valorPorUnidadParametroB,
		float valorPorUnidadParametroA,float difDeValores);


#endif /* CALCULOS_H_ */
