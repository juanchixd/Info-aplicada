/*
 ============================================================================
 Name        : P0ej16.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print_binary(int number){
	if(number){
		print_binary(number >> 1);
		putc((number & 1) ? '1' : '0', stdout);
	}
}
//recibe un byte, y el numero de linea que sera forzada a nivel logico 1,
//devolviendo por el nombre el resusltado de la operacion
unsigned char Set(unsigned char Datos, short Linea){
	((Datos) |= (1 << (Linea)));
	return Datos;
}

//recibe un byte, y el numero de linea que sera forzada a nivel logico 0,
//devolviendo por el nombre el resusltado de la operacion
unsigned char Clear(unsigned char Datos, short Linea){
	((Datos) &= ~(1 < (Linea)));
	return Datos;
}

int main(void) {
	char datos = 0b01010101;
	short linea = 1;
	printf("Numero inicial: %i numero cambiado: %i, en binario original:̣̣ ", datos, Set(datos, linea));
	print_binary(datos);
	printf(", en binario numero nuevo: ");
	print_binary(Set(datos, linea));
	printf("\n");
	linea = 2;
	printf("Numero inicial: %i numero cambiado: %i, en binario original:̣̣ ", datos, Clear(datos, linea));
	print_binary(datos);
	printf(", en binario numero nuevo: ");
	print_binary(Clear(datos, linea));
	printf("\n");
	return EXIT_SUCCESS;
}
