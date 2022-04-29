/*
 ============================================================================
 Name        : P1ej11.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** Matriz_generar(int *fil, int *col, int *esc);

int ** Matriz_generar(int *fil, int *col, int *esc){
	int i, j, cond = 0;
	while(cond != 1){
		printf ("\nIndique el numero de filas de la matriz: ");
		scanf ("%d", fil);
		printf ("\nIndique el numero de columnas de la matriz: ");
		scanf ("%d", col);
		if (*fil == 0 || *col == 0){
			break;
		}
		else if (*fil < 1 || *col < 1){
			printf("INGRESE UN TAMAÑO VALIDO O 0 PARA SALIR\n");
		}
		else{
			cond = 1;
		}
	}
	printf("\nIndique el escalar:");
	scanf("%d", esc);
	int **matriz = (int **)malloc(*fil * sizeof(int*));
	for (i=0 ; i<*col ; i++) {
		matriz[i] = (int *)malloc(*col * sizeof(int));
	}
	if (matriz == NULL){
		printf("NO PUDE RESERVAR MEMORIA. FIN");
		return -1;
	}
	srand(time(NULL));
	for (i=0 ; i<*fil ; i++) {
		for (j=0 ; j<*col ; j++) {
			matriz[i][j] = rand() % 20;
		}
	}
	return matriz;
}

void mostrar(int ** matriz, const int fil, const int col) {
	printf("La matriz original de tamaño %i * %i es:\n", fil, col);
	int i, j;
	for(i = 0; i < fil; i++) {
		printf("|");
		for(j = 0; j < col; j++)
			printf(" %i \t", matriz[i][j]);
		printf("| \n");
	}
}

int **producto_Escalar_matriz(int fil, int col, int esc, int **matriz){
	for (int i=0 ; i<fil ; i++) {
		for (int j=0 ; j<col ; j++) {
			matriz[i][j] = matriz[i][j] * esc;
		}
	}
	return matriz;
}

int main(void) {
	int **matriz = NULL;
	int fil, col, escalar;
	matriz = Matriz_generar(&fil, &col, &escalar);
	mostrar(matriz, fil, col);
	mostrar(producto_Escalar_matriz(fil, col, escalar, matriz), fil, col);
//	for(int i=0; i<col; i++){
//		free(matriz[i]);
//	}
//	free(matriz);
	return EXIT_SUCCESS;
}
