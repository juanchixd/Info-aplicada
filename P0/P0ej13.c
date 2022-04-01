/*
 ============================================================================
 Name        : P0ej13.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 13)Generar una función unsigned getBits(unsigned x,int p, int n)
 que retorne los n bits de x (ajustado a la derecha) que principia en la
 posición p. Se supone que la posición del bit 0 está en el borde derecho y que
 n y p son valores positivos adecuados. Por ejemplo, getbits(x,4,3) regresa los
 3 bits que están en la posición 4, 3 y 2, ajustados a la derecha. (ver si puede
 sintetizar la operación en una sola instrucción).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned getBits(unsigned x, int p, int n){
	return (x >> (p)) & ~ (~0 << n);
}

void print_binary(int number){
	if(number){
		print_binary(number >> 1);
		putc((number & 1) ? '1' : '0', stdout);
	}
}

int main(void) {
	unsigned int x=0xB7;//en decimal 183
	printf("El numero x en binario es: ");
	print_binary(x);
	printf("\n");
	printf("Los %d bits a la izquierda de la posicion %d generan el numero:",5,2);
	print_binary(getBits(x,2,5));
	printf("\n");
	return EXIT_SUCCESS;
}
