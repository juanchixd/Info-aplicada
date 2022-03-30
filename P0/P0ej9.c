/*
 ============================================================================
 Name        : P0ej9.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//pone a 1 el bit b del numero a
#define BitSet(a,b) ((a) |=(1<<(b)))
//pone a 0 el bit b del numero a
#define BitClear(a,b) ((a) &= ~(1<<(b)))
//verifica si el bit b del numero a es un 0 o un 1
#define BitCheck(a,b) ((a) &= (1<<(b)))
//cambia el bit b del numero a por su valor complementario
//si el bit es 0 lo pone a 1 y si es 1 lo pone a 0
#define BitToggle(a,b) ((a) ^= (1<<(b)))

void print_binary(int number){
	if(number){
		print_binary(number >> 1);
		putc((number & 1) ? '1' : '0', stdout);
	}
}
int main(void) {
	unsigned int 	//entrada = 879797,
					salida  = 0,
					pin		= 0;
	pin = 4;
	BitSet(salida, pin);

	pin = 2;
	BitSet(salida, pin);

	pin = 4;
	BitClear(salida, pin);
	printf("El pin %d de la entrada esta en:", pin);
	print_binary(pin);

	return EXIT_SUCCESS;
}
