/*
 ============================================================================
 Name        : P1ej10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float determinante_matriz(const int n, float **matriz);
float ** Introducir(int *n);

float ** Introducir (int *n){
	int i, j, cond = 0;
	while(cond != 1){
		printf ("\nIndique el orden de la matriz: ");
		scanf ("%d", n);
		if (*n == 0){
			break;
		}
		else if (*n < 1){
			printf("INGRESE UN TAMAÑO VALIDO O 0 PARA SALIR\n");
		}
		else{
			cond = 1;
		}
	}
	float **matriz = (float **)malloc(*n * sizeof(float*));
	for (i=0 ; i<*n ; i++) {
		matriz[i] = (float *)malloc(*n * sizeof(float));
	}
	if (matriz == NULL){
		printf("NO PUDE RESERVAR MEMORIA. FIN");
		return -1;
	}
	for (i=0 ; i<*n ; i++) {
		for (j=0 ; j<*n ; j++) {
			printf ("\nIntroduzca valor de la posición %d - %d: ",i+1,j+1);
			scanf("%f",&matriz[i][j]);
		}
	}
	return matriz;
}

float determinante_matriz(int n,float **matriz){
	float det = 0, aux = 0;
	int c;
	if(n==2){
		return matriz[0][0]*matriz[1][1] - matriz[1][0]*matriz[0][1];
	}
	else{
		for(int i=0; i<n; i++){
			float **menor = (float **)malloc(sizeof(float)*(n-1));
			for(int j=0; j<(n-1); j++) menor[j] = (float *)malloc(sizeof(float)*(n-1));
			if (menor == NULL){
				printf("NO PUDE RESERVAR MEMORIA. FIN");
				return -1;
			}
			for(int j=1; j<n; j++){
				c = 0;
				for(int l=0; l<n; l++){
					if(l!=i){
						menor[j-1][c] = matriz[j][l];
						c++;
					}
				}
			}
			aux = pow(-1, 2+i)*matriz[0][i]*determinante_matriz(n-1, menor);
			det += aux;
//			for(int q = 0; q<(n-1); q++){
//				free(menor[q]);
//			}
//			free(menor); ALGUN DIA VER PORQUE SE ROMPE
		}
		return det;
	}
}

void mostrar(float ** matriz, const int n) {
	printf("La matriz que ingresaste de orden %i es:\n", n);
	int i, j;
	for(i = 0; i < n; i++) {
		printf("|");
		for(j = 0; j < n; j++)
			printf(" %.1f \t", matriz[i][j]);
		printf("| \n");
	}
}

void mostrar_dir(float ** matriz, const int n) {
	printf("\nLas direcciones de la matriz que ingresaste de orden %i es:\n\n", n);
	int i, j;
	for(i = 0; i < n; i++) {
		printf("|");
		for(j = 0; j < n; j++){
			printf(" %p \t", &matriz[i][j]);
		}
		printf("| Rango de %p a %p\n", &matriz[i][0], &matriz[i][n-1]);
	}
	printf("\nRango de la matriz completa es de %p a %p\n", &matriz[0][0], &matriz[n-1][n-1]);
}

int main(void) {
	float **matriz=NULL;
	int n;
	matriz = Introducir(&n);
	mostrar(matriz, n);
	float det = determinante_matriz(n, matriz);
	printf("\nEl determinante de la matriz es: %f\n", det);
	mostrar_dir(matriz, n);
	for(int i = 0; i<(n-1); i++){
		free(matriz[i]);
	}
	free(matriz);
	return EXIT_SUCCESS;
}
