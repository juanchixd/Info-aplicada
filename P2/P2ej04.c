/*
 ============================================================================
 Name        : P2ej02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TipoPunto{
	double abscisa;
	double ordenada;
};
struct TipoCiudad{
	struct TipoPunto situacion;
	char nombre[50];
};

double modulo(struct TipoPunto c1, struct TipoPunto c2){
	double dist = sqrt(pow((c1.abscisa-c2.abscisa),2)+pow((c1.ordenada-c2.abscisa),2));
	return dist;
}
void Reordenar(struct TipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]){
	int k;
	struct TipoCiudad temp;
	double dist1, dist2;
	for (int i=0; i<num_ciudades; i++){
		if(strcmp(nombre_ciudad_referencia, ciudades[i].nombre) == 0){
			temp = ciudades[0];
			ciudades[0] = ciudades[i];
			ciudades[i] = temp;
			break;
		}
	}
	for(int i=1; i<num_ciudades-1; i++){
		dist1 = modulo(ciudades[0].situacion, ciudades[i].situacion);
		k = i;
		for(int j=i+1; j<num_ciudades; j++){
			dist2 = modulo(ciudades[0].situacion, ciudades[j].situacion);
			if(dist2 < dist1){
				dist1 = dist2;
				k=j;
			}
		}
		temp = ciudades[i];
		ciudades[i] = ciudades[k];
		ciudades[k] = temp;
	}
}

int main(void) {
	int num = 5;
	char nombre[30] = "Casa";
	struct TipoCiudad ciudades[5];
	strcpy(ciudades[0].nombre, "Rosario");
	ciudades[0].situacion.abscisa = -32;
	ciudades[0].situacion.ordenada = -60;
	strcpy(ciudades[1].nombre, "Buenos Aires");
	ciudades[1].situacion.abscisa = -10;
	ciudades[1].situacion.ordenada = -4;
	strcpy(ciudades[2].nombre, "Casa");
	ciudades[2].situacion.abscisa = -3;
	ciudades[2].situacion.ordenada = -8;

	for(int i=0; i<3;i++){
		printf("%s, %f, %f\n", ciudades[i].nombre, ciudades[i].situacion.abscisa,ciudades[i].situacion.ordenada);
	}
	Reordenar(ciudades, num, nombre);
	printf("Aca lo tenes ordenado boludo:\n");
	for(int i=0; i<4;i++){

		printf("%s, %f, %f\n", ciudades[i].nombre, ciudades[i].situacion.abscisa,ciudades[i].situacion.ordenada);
	}


	return EXIT_SUCCESS;
}
