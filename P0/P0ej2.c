/*
 ============================================================================
 Name        : P0ej2.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Leer numeros enteros distintos de cero y luego lea una secuencia de valores
 enteros indicando si estan entre los diez valores leidos. Cuando se lea el valor
 cero, el programa finalizara.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANT_NUMEROS 3

int main(void) {
	int *valores, valor = 1, i = 0, cond = 1;
	valores = (int*) calloc(CANT_NUMEROS,sizeof(int));
	printf("Ingrese 10 numeros enteros distinto de 0\n");
	while (i < CANT_NUMEROS){
		scanf("%i", &valor);
		if(valor != 0){
			printf("El numero ingresado es %i \n", valor);
			valores[i] = valor;
			i = i + 1;
		}
		else{
			printf("ERROR, NUMERO INGRESADO ES UN CERO\n");
		}
	}
	while (valor != 0){
		printf("Ingrese un valor distinto de 0 o 0 para terminar\n");
		scanf("%i", &valor);
		for(int j=0; j < CANT_NUMEROS; j++){
			if(valores[j]==valor){
				printf("El valor ingresado se encuentra en el arreglo, en la posicion: %d\n", j);
			}
			else{
				cond = 0;
			}
		}
		if (cond == 0){
			printf("No se encontro el valor");
		}
	}
	printf("FIN PROGRAMA");
	return EXIT_SUCCESS;
}
