/*
 ============================================================================
 Name        : P0ej10.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 10)Escribir la función paridad_par que recibe un byte y retorna
 un byte. El byte devuelto debe ser igual al byte recibido o, igual al byte
 recibido con el bit más significativo modificado, de forma tal que la
 configuración del byte entregado contenga un número par de unos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned char paridad_par(unsigned char x){
	int paridad_par = 0;
	unsigned char aux = x;
	while (x > 0){
		paridad_par = (paridad_par + (x & 1)) % 2;
		x >>= 1;
	}
	if (paridad_par){
		aux = aux^0x80;
	}
	return aux;
}

void print_binary(int number){
	if(number){
		print_binary(number >> 1);
		putc((number & 1) ? '1' : '0', stdout);
	}
}

int main(void) {
	unsigned int i;
	for (i = 0; i < 256; i++){
		printf("Numero: %u\tParidad par: %u \t\t\t En binario: ", i, paridad_par(i));
		print_binary(i);
		printf("\n");
	}
	return EXIT_SUCCESS;
}
