/*
 ============================================================================
 Name        : P0ej5.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Separar una frase con y sin funciones estandar
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void a(char *frase){
	for(int i = 0; i < 100; i++){
		if(frase[i] != ' '){
			printf("%c", frase[i]);
		}
		else{
			printf("\n");
		}
	}
}

void b(char *frase){
	char delimitar[] = " ";
	char *palabras = strtok(frase, delimitar);
	if (palabras != NULL){
		while(palabras != NULL){
			printf("%s\n", palabras);
			palabras = strtok(NULL, delimitar);
		}
	}
}

int main(void) {
	char frase[100] = "Pablito clavo un clavito, que clavito clavo pablito";
	//descomentar la opcion a usar
	//a(frase);
	//b(frase);
	return EXIT_SUCCESS;
}
