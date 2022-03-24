/*
 ============================================================================
 Name        : P0ej4.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Matrices, traza, transpuesta y producto
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
double ** Introducir(int *, int *, int);

int menu(){
	int opc;
	printf("\n------------------Menu------------------");
	printf("\nElija que ejercicio quiere acceder\n");
	printf("1) Calculo de la traza de una matriz cuadrada.\n");
	printf("2) Calculo de la matriz transpuesta.\n");
	printf("3) Calculo de producto de matrices.\n");
	printf("Elija opcion 1, 2 o 3, sino 0 para salir.\n");
	scanf("%d", &opc);
	while(opc != 0 && opc != 1 && opc!= 2 && opc != 3){
		printf("------------------Menu------------------");
		printf("\nElija que ejercicio quiere acceder\n");
		printf("1) Calculo de la traza de una matriz cuadrada.\n");
		printf("2) Calculo de la matriz transpuesta.\n");
		printf("3) Calculo de producto de matrices.\n");
		printf("Elija opcion 1, 2 o 3, sino 0 para salir.\n");
		scanf("%d", &opc);
	}
	return opc;
}

double ** Introducir (int *f, int *c, int con){
    double **matriz;
    int i, j, cond = 0;
    while(cond != 1){
    	printf ("\nIndique numero de filas: ");
    	scanf ("%d",f);
    	printf ("\nIndique numero de columnas:");
    	scanf ("%d",c);
    	if (*f == 0 || *c == 0){
    		break;
    	}
    	else if (*f < 1 || *c < 1){
    		printf("INGRESE UN TAMAÑO VALIDO O 0 PARA SALIR\n");
    	}
    	else{
    		cond = 1;
    	}
    }
    matriz = (double **)calloc(*f,sizeof(double*));
    for (i=0 ; i<*f ; i++) {
    	matriz[i] = (double *)calloc(*c,sizeof(double));
    }
    if (con == 0){
    	for (i=0 ; i<*f ; i++) {
        	for (j=0 ; j<*c ; j++) {
            	printf ("\nIntroduzca valor de la posición %d - %d: ",i+1,j+1);
            	scanf("%lf",&matriz[i][j]);
        	}
    	}
    }
    else{
    	for (i=0 ; i<*c ; i++) {
          	for (j=0 ; j<*f ; j++) {
    	       	printf ("\nIntroduzca valor de la posición %d - %d: ",i+1,j+1);
    	       	scanf("%lf",&matriz[j][i]);
    	   	}
    	}
    }
    return matriz;
}

void eja(){
	int n=0;
	double valor, traza = 0;
	while(n < 1){
		printf("Ingrese tamaño de la matriz:");
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		else if(n < 1){
			printf("INGRESE UN VALOR VALIDO O 0 PARA SALIR");
		}
	}
	for(int i = 0; i < n; i++){
		printf("\nIngrese el valor de la posicion %i fila %i columna:", i+1, i+1);
		scanf("%lf", &valor);
		traza += valor;
	}
	printf("\nLa traza es igual a %f\n\n", traza);
}

void ejb(){
	int f=0, c=0, j, i, con = 1;
	double **matriz;
	while(f < 1 || c < 1){
		matriz = Introducir(&f, &c, con);
		printf("\n");
		if (f == 0 || c == 0){
			break;
		}
	}
	printf("\nMatriz original");
	for(i=0; i < f; i++){
		printf("\n|\t");
		for(j=0; j < c; j++){
			printf("%lf\t",matriz[i][j]);
		}
		printf("|");
	}
	printf("\n\nMatriz transpuesta");
	for(i=0; i < c; i++){
		printf("\n|\t");
		for(j=0; j < f; j++){
			printf("%lf\t",matriz[j][i]);
		}
		printf("|");
	}
	for(int i = 0; i < f; i++){
		free(matriz[i]);
	}
	free(matriz);
}

void ejc(){
	int f1, f2, c1, c2, j, i, cond = 0, con = 1;
	double valor;
	double **matriz1, **matriz2, **matriz;
	while(cond != 1){
		matriz1 = Introducir(&f1, &c1, con);
		matriz2 = Introducir(&f2, &c2, con);
		if (f1 == 0 || f2 == 0 || c1 == 0 || c2 == 0){
			break;
		}
		else if(f1 < 1 || f2 < 1 || c1 < 1 || c2 < 1){
			printf("INGRESE UN VALOR VALIDO O 0 PARA SALIR");
		}
		else if(c1 != f2){
			printf("NO SE PUEDE RESOLVER LA PRODUCTO DE MATRICES DE MATRICES");
		}
		else{
			cond = 1;
		}
	}
	matriz  = (double **) calloc(f1,sizeof(double*));
	for (i=0 ; i<f1 ; i++) {
	   	matriz[i] = (double *)calloc(c2,sizeof(double));
	}
	for(i=0; i < f1; i++){
		for(j=0; j < c2; j++){
			valor = 0;
			for(int k = 0; k < c2; k++){
				valor += matriz1[i][k]*matriz2[k][j];
			}
			matriz[i][j] = valor;
		}
	}
	printf("\n\nResultado");
	for(i=0; i < f1; i++){
		printf("\n|\t");
		for(j=0; j < c2; j++){
			printf("%lf\t",matriz[i][j]);
		}
		printf("|");
	}
	for(int i = 0; i < f1; i++) {
	    free(matriz1[i]);
	    free(matriz[i]);
	}
	for(int i = 0; i < f2; i++){
		free(matriz2[i]);
	}
	free(matriz1);
	free(matriz2);
	free(matriz);
}

int main(void) {
	int opc = 1;
	while(opc != 0){
		opc = menu();
		switch (opc){
		case 1:
			eja();
			break;
		case 2:
			ejb();
			break;
		case 3:
			ejc();
			break;
		case 0:
			printf("PROGRAMA FINALIZADO.");
			break;
		}
	}
	return EXIT_SUCCESS;
}
