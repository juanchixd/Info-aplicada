/*
 ============================================================================
 Name        : P0ej7.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#define TRUE 1

//FORMA 1

//#ifdef TRUE
//	#undef TRUE
//	#define TRUE 1
//#else
//	#define TRUE 1
//#endif

//FORMA 2

//#ifndef TRUE
//	#define TRUE 1
//#else
//	#undef TRUE
//	#define TRUE 1
//#endif

//FORMA 3

//#if defined(TRUE)
//	#undef TRUE
//	#define TRUE 1
//#else
//#endif

int main(void) {
	if(1 == TRUE){
		printf("La etiqueta fue reemplazada");
	}
	else{
		printf("Algo salio mal");
	}

	return EXIT_SUCCESS;
}
