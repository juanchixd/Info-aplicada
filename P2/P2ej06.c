/*
 ============================================================================
 Name        : P2ej06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	unsigned char R, G, B;
}RGB;

typedef struct{
	int ancho, alto;
	RGB **pixel;
}ImagenRGB;

typedef unsigned char Gris;

typedef struct{
	int ancho, alto;
	Gris **pixel;
}ImagenGris;

ImagenRGB * creaImagenRGB(int ancho, int alto){
	ImagenRGB * imagen = (ImagenRGB *) malloc(sizeof(ImagenRGB));
	if (imagen == NULL){
		printf("No reserve");
		return -1;
	}
	imagen->alto = alto;
	imagen->ancho = ancho;
	imagen->pixel = (RGB **) malloc(alto * sizeof(RGB*));
	for(int i=0; i<alto; i++){
		imagen->pixel[i]= (RGB*) malloc(ancho * siezeof(RGB));
	}
	return imagen;
}

void setPixelRGB(ImagenRGB *im, int fila, int columna, RGB *pix){
	im->pixel[fila][columna].R=pix->R;
	im->pixel[fila][columna].G=pix->G;
	im->pixel[fila][columna].B=pix->B;
}

RGB * getPixelRGB(ImagenRGB *im, int fila, int columna){
	return(&(im->pixel[fila][columna]));
}
int main(void) {
	int ancho, alto;
	ImagenRGB *im = creaImagenRGB(ancho, alto);
	return EXIT_SUCCESS;
}
