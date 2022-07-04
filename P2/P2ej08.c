/*
 ============================================================================
 Name        : P2ej08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union ascii{
	unsigned char c;
	struct{
		unsigned char bit0 : 1;
		unsigned char bit1 : 1;
		unsigned char bit2 : 1;
		unsigned char bit3 : 1;
		unsigned char bit4 : 1;
		unsigned char bit5 : 1;
		unsigned char bit6 : 1;
		unsigned char bit7 : 1;
		}A;
}ASCII;


char *cambiar_pares(char *s){
	ASCII as;
	char *p;
	p = (char*) malloc(strlen(s)+1);
	strcpy(p,s);
	for(int i=0; i < strlen(s);i++){
		as.c = s[i];
		as.A.bit0 = ~as.A.bit0;
		as.A.bit2 = ~as.A.bit2;
		as.A.bit4 = ~as.A.bit4;
		as.A.bit6 = ~as.A.bit6;
		p[i]=as.c;
	}
	return p;
}

int main(void) {
	char algo[] = "a";
	char *p = cambiar_pares(algo);
	printf("%s", p);
	return EXIT_SUCCESS;
}
