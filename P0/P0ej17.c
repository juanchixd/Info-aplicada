/*
 ============================================================================
 Name        : P0ej17.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//RGB 0xFFCCAA
char rojo(unsigned int dato){
	return (dato >> (16));
}
char verde(unsigned int dato){
	return (dato >> (8)) & ~ (~0 << 16);
}

char azul(unsigned int dato){
	return (dato >> (0)) & ~ (~0 << 8);
}
void componentesRGB(unsigned int dato){
	printf("Cantidad de rojo: %d\n", rojo(dato));
	printf("Cantidad de verde: %d\n", verde(dato));
	printf("Cantidad de azul: %d\n", azul(dato));
}
int main(void) {
	unsigned  int dato = 0x112233;
	componentesRGB(dato);
	return EXIT_SUCCESS;
}
