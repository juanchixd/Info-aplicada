/*
 ============================================================================
 Name        : P1ej09.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float ** identidad(const int n) {
	int i;
	float ** matriz = (float **) calloc(n , sizeof (float *));
	for(i = 0; i < n; i++) {
		matriz[i] = (float *) calloc(n, sizeof(float));
		matriz[i][i] = 1;
	}
	return matriz;
}

void mostrar(float ** matriz, const int n) {
	printf("La matriz que pediste de orden %i es:\n", n);
	int i, j;
	for(i = 0; i < n; i++) {
		printf("|");
		for(j = 0; j < n; j++)
			printf(" %.1f \t", matriz[i][j]);
		printf("| \n");
	}
}

int main(void) {
	int n  = 10;
	mostrar(identidad(n), n);
	return EXIT_SUCCESS;
}
