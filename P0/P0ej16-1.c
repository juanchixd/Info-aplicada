/*
 ============================================================================
 Name        : P0ej16-1.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum band{
	FM,
	AM
};

long Potencia(long numero, long potencia){
    if (potencia <= 0){
        return 1;
    }
    else{
        return numero * Potencia(numero, potencia-1);
    }
}

int get_synthesizer_divider(unsigned char dato){
	int su = 1;
	for(int i = 1; i < 6 ; i++){
		((dato) & (1 << (i)))? (su = su + Potencia(2, i-1)) : (su = su);
	}
	return su;
}

int get_band(unsigned char data){
  return ((data) & (1<<(6))) ? FM : AM;
}

int main(void) {
	char dato = 0b10111110;
	printf("El factor divisor es: %d\n", get_synthesizer_divider(dato));
	if (get_band(dato) == 1)
		printf("La banda es: AM\n");
	else{
		printf("La banda es: FM\n");
	}
	return EXIT_SUCCESS;
}
