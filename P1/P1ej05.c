/*
 ============================================================================
 Name        : P1ej05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void calcular(float peso, float precio, float *monto, float *montodesc){
	*monto = peso * precio;
	if (*monto > 100){
		*montodesc = *monto * 0.9;
	}
	else{
		*montodesc = 0;
	}
}

int main(void) {
	float peso = 2, precio = 20, monto, montodesc;
	calcular(peso, precio, &monto, &montodesc);
	if(montodesc != 0){
		printf("El precio total es: %.2f, con descuento: %.2f", monto, montodesc);
	}
	else{
		printf("El precio total es: %.2f", monto);
	}
	return EXIT_SUCCESS;
}
