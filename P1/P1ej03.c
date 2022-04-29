/*
 ============================================================================
 Name        : P1ej03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float *arreglo;
	int cont = 0;
	char n = 0;
	printf("Ingrese el numero de valores reales a almacenar: ");
	scanf("%hhd", &n);
	arreglo = (float*)malloc(sizeof(float)*n);
	if(arreglo==NULL){
		printf("No se pudo reservar memoria para el arreglo");
		return -1;
	}
	while(cont < n){
		printf("Ingrese un numero real:");
		scanf("%f", arreglo+cont);
		cont = cont + 1;
	}
	printf("ORDEN INVERSO\n");
	for(int i = cont; i > 0; i--){
		printf("%f \n", *(arreglo + i -1));
	}
	free(arreglo);
	return EXIT_SUCCESS;
}
