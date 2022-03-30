/*
 ============================================================================
 Name        : P0ej8.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MINIMO2(a, b) ( (a) < (b) )? (a):(b)
#define MINIMO3(a, b, c) (MINIMO2(a,b) == a) ? MINIMO2(a,c):MINIMO2(b,c)
//#define MINIMO3(a, b, c) ((c) < (MINIMO2(a,b)))?c:MINIMO2(a,b)

int main(void) {
	printf("%d \n", MINIMO2(5,4));
	printf("%d", MINIMO3(5,4,9));
	return EXIT_SUCCESS;
}
