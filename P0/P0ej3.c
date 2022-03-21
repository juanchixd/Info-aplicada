/*
 ============================================================================
 Name        : P0ej3.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Determinacion del dia de mayor lluvia, menor y promedio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_DIAS 30

int main(void) {
	int sum = 0, maxv, minv, max, min, valor;
	srand(time(NULL));
	for(int i = 0; i<CANT_DIAS; i++){
		//printf("Ingrese la cantidad de agua caida del dia %d:", i+1);
		//scanf("%i", &valor);
		valor = rand()%400;
		sum = sum + valor;
		if(i==0){
			maxv = valor;
			minv = valor;
			max = i + 1;
			min = i + 1;
		}
		else if (i != 0){
			if(valor > maxv){
				maxv = valor;
				max = i + 1;
			}
			else if (minv > valor){
				minv = valor;
				min = i + 1;
			}
			else continue;
		}
		else continue;
	}
	float prom = sum/CANT_DIAS;
	printf("El dia de mayor lluvia es %d y cayo una cantidad de %d mm\n", max, maxv);
	printf("El dia de menor lluvia es %d y cayo una cantidad de %d mm\n", min, minv);
	printf("El promedio de lluvia es %f\n", prom);
	return EXIT_SUCCESS;
}
