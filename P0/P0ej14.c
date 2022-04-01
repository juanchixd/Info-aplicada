/*
 ============================================================================
 Name        : P0ej14.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 14)Escriba un programa que intercambie el valor de dos enteros
 num1 y num2 sin utilizar variables temporales, usando el operador XOR.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num1 = 10, num2 = 30;
	printf("%d \t %d\n", num1, num2);
	num1 ^= num2;
	num2 ^= num1;
	num1 ^= num2;
	printf("%d \t %d", num1, num2);
	return EXIT_SUCCESS;
}
