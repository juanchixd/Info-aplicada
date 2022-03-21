/*
 ============================================================================
 Name        : P1ej1.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar intercambio de variables
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 10, y = 20, z = 30, aux;
	aux = z;
	z 	= y;
	y 	= x;
	x 	= aux;
	printf("%i %i %i", z, y, x);
	return EXIT_SUCCESS;
}
