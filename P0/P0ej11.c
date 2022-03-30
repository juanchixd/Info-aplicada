/*
 ============================================================================
 Name        : P0ej11.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 11)Generar una función unsigned rightRot(unsigned x,int n) que
 rote a derecha los últimos n bits de x. Asumir que el bit menos significativo
 de x, ocupa la posición cero y que n siempre asume valores positivos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned rightRot(unsigned x, int n){
	for(int i = 0; i < n; i++){
		if ((x & 1) == 0){ //ultimo bit es 0
			x = x >> 1; //lleno con 0 en el bit mas significativo
		}
		else{ //ultimo bit es 1
			x = x >> 1;
			x = x | 0x80; //lleno con un 1 en el bit mas significativo
		}
	}
	return x;
}

int main(void) {
	unsigned x = 0xB7;
	int n = 5;
	printf("Numero rotado en %u lugares: %u\n", n, rightRot(x,n));
	return EXIT_SUCCESS;
}
