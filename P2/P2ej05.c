/*
 ============================================================================
 Name        : P2ej05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	short filas, col;
	int **matriz;
}matrix;

//matrix * alojar(short n,short m){
//	matrix *ptr = (matrix*) malloc(sizeof(matrix));
//	ptr->col = n, ptr->filas = m;
//	ptr->matriz = (int**)malloc(ptr->filas * sizeof(int**));
//	for(int i=0; i< ptr->filas; i++){
//		ptr->matriz[i] = (int*)malloc(ptr->col * sizeof(int));
//	}
//	return ptr;
//}

void generacion(matrix * M, int m, int n){
	M->col = m, M->filas = n;
	M->matriz = (int **) malloc(m*sizeof(int*));
	for (int i=0; i<m; i++){
		M->matriz[i] = (int*) malloc(n*sizeof(int));
	}
	if(M->matriz == NULL){
		printf("NO PUDE");
	}
}

void llenar(matrix *M){
	srand(time(NULL));
	for (int i=0 ; i<M->filas ; i++) {
		for (int j=0 ; j<M->col ; j++) {
			M->matriz[i][j] = rand() % 80;
		}
	}
}

matrix * suma(matrix *M1, matrix *M2){
	matrix *s = malloc(sizeof(matrix));
	generacion(s, M1->col, M2->filas);
	for(int i=0; i<s->filas; i++){
		for(int j=0; j<s->col; j++){
			s->matriz[i][j] = M1->matriz[i][j] + M1->matriz[i][j];
		}
	}
	return s;
}

void mostrar(matrix *M) {
	for(int i = 0; i < M->filas; i++) {
		printf("|");
		for(int j = 0; j < M->col; j++)
			printf(" %i \t", M->matriz[i][j]);
		printf("| \n");
	}
	printf("\n");
}

void libera(matrix *M){
	for(int i=0; i<M->col; i++){
		free(M->matriz[i]);
	}
	free(M->matriz);
	free(M);
}

int main(void) {
	int m=2, n=2;
	matrix *M1 = (matrix *)malloc(sizeof(matrix));
	matrix *M2 = (matrix *)malloc(sizeof(matrix));
	matrix *RE = (matrix *)malloc(sizeof(matrix));
//	matrix *M1 = alojar(n,m);
	generacion(M1, m, n);
	llenar(M1);
	printf("La matriz original de tamaño %i * %i es:\n", M1->filas, M1->col);
	mostrar(M1);
	generacion(M2, m, n);
	llenar(M2);
	printf("La matriz original de tamaño %i * %i es:\n", M2->filas, M2->col);
	mostrar(M2);
	RE = suma(M1, M2);
	printf("La matriz suma es igual a\n");
	mostrar(RE);
	libera(M1), libera(M2), libera(RE);
	return EXIT_SUCCESS;
}
