/*
 ============================================================================
 Name        : P1ej02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
	char x = 'a', pal [] ="texto en c";
	int *pi;
	char *pc;
	printf("variable i  | direccion: %p | valor: %d\n", &i, i);
	pi = &i;
	printf("variable pi | direccion: %p | valor: %d\n", pi, *pi);
	for(int k = 0; k < sizeof(j)/sizeof(int); k++){
		printf("valor: %d | direccion:%p\n", j[k], &j[k]);
	}
	printf("\n");
	pi = &j;
	for(int k = 0; k < sizeof(j)/sizeof(int); k++){
		printf("valor: %d | direccion:%p\n", *(pi+k), pi+k);
	}
	pc = &pal;
	for(int k = 0; k< strlen(pal); k++){
		printf("%8d | Direccion: %10p - Valor: %3c | Direccion: %10p - Valor = %3c \n",k,&pal[k],pal[k],(pc+k),*(pc+k));
	}
	return EXIT_SUCCESS;
}
