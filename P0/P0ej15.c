/*
 ============================================================================
 Name        : P0ej15.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 15)Escriba una función que determine si existe, por lo menos
 un bit entre las posiciones baja y alta (con baja<=alta) con valor 1, de un
 número entero llamado num pasado a dicha función como argumento. Si es así
 dicha función debe retornar un 1, en caso contrario retornará 0.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int existeuno(int num, int baja, int alta){
	int a = num >> baja;
	int b = alta - baja + 1;
	int existe = 0, i;
	for (i = 0; i < b; i++){
		if((a & 1) == 1){
			existe = 1;
		}
	}
	return existe;
}

int main(void) {
	int a = 167131, baja = 3, alta = 5;
	if (existeuno(a, baja, alta) == 1){
		printf("Existen un uno entre la posicion %d y %d del numero %d\n", baja, alta, a);
	}
	else{
		printf("No existen unos");
	}

	return EXIT_SUCCESS;
}
