/*
 ============================================================================
 Name        : P1ej04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char dias[7][10] = {"Lunes",
					"Martes",
					"Miercoles",
					"Jueves",
					"Viernes",
					"Sabado",
					"Domingo"
};

char* numdia(unsigned char d){
	return(char*)(dias + d - 1);
}

int main(void) {
	unsigned char i = 0;
	printf("Ingrese el numero del dia:");
	scanf("%hhd", &i);
	printf("%s", numdia(i));
	return EXIT_SUCCESS;
}
