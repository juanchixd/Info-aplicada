/*
 ============================================================================
 Name        : P0ej12.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 12)Generar una función unsigned setbits(unsigned x, int p,
 int n, unsigned y) que regresa x con los n bits que principian en la posición
 p iguales a los n bits más a la derecha de y, dejando los otros bits sin cambio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y){
	return (~((~0 << p) & ~(~0 <<(p+n))) & x ) | (~(~0 << p+n) & (y << p));
}

int main(void) {
	unsigned num1 = 12, num2 = 22;
	int a = 1, b = 3;
	printf("%d", setbits(num1, a, b, num2));
	return EXIT_SUCCESS;
}
