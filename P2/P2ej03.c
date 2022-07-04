/*
 ============================================================================
 Name        : P2ej03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct{
	char sign;
	unsigned char num_bytes;
	unsigned char * bytes;
}Apint;

//mi propio itoa
char * myitoa(int num, char *buffer, int base){
	int i = 0;
	int cociente = num;
	while(cociente > (base - 1)){
		buffer[i++] = cociente%base + (cociente%base > 9 ? 'A' - 10 : '1' - 1);
		cociente /= base;
	}
	buffer[i++] = cociente + (cociente%base > 9 ? 'A' - 10 : '1' - 1);
	buffer[i] = '\0';
	return buffer;
}
//impresion
void imprimir_Apint(Apint *e){
	char buffer[9];
	printf("%+dx ", e->sign);
	for (int i = e->num_bytes-1; i >= 0 ; i--){
		printf("%8s  ",	myitoa(e->bytes[i], buffer, 2));
	}
	printf("\n");
}
//suma
Apint * suma_Apint(Apint * i1, Apint * i2){
	unsigned short sum1 = 0, sum2 = 0, acar = 0, sum = 0;
	if(i1->num_bytes != i2->num_bytes){
		printf("ERROR! Distinto tamaño, no se soporta enteros de tamaño distinto.\n");
//		return NULL;
	}
	if(i1->sign != i2->sign){
		printf("ERROR! No soporta distinto signo por ahora. \n");
//		return NULL;
	}
	Apint *sum_ptr = (Apint *) malloc(sizeof(Apint));
	if(sum_ptr == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA LA SUMA");
//		return NULL;
	}
	sum_ptr->num_bytes = i1->num_bytes;
	sum_ptr->sign = i1->sign;
	sum_ptr->bytes = (unsigned char *) calloc(sum_ptr->num_bytes, sizeof(unsigned char));
	if(sum_ptr == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA LOS BYTES DE LA SUMA");
	}
	for(int i = 0; i < i1->num_bytes; i++){
		sum1 = (unsigned short) i1->bytes[i];
		sum2 = (unsigned short) i2->bytes[i];
		sum = acar + sum1 + sum2;
		acar = (sum >> (8));
		sum_ptr->bytes[i] = (unsigned char) sum;
	}
	return sum_ptr;
}

Apint * DI_Apint(Apint *e, int nbits){
	unsigned int byte_cero = nbits/8;
	unsigned int despla = nbits%8;
	unsigned char bits_sup = 0;
			unsigned char acarreo = 0;
	Apint *result = (Apint *) malloc(sizeof(Apint));
	if (result == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA RESULTADO");
//		return NULL;
	}
	result->sign = e->sign;
	result->num_bytes = e->num_bytes;
	result->bytes = (unsigned char *) calloc (result->num_bytes, sizeof(unsigned char));
	if(result->num_bytes == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA LOS BYTES DEL RESULTADO");
//		return NULL;
	}
	for(int i = byte_cero; i < result->num_bytes; i++){
		result->bytes[i] = e->bytes[i - byte_cero];
		bits_sup = (result->bytes[i]) & (~0 << (8 - despla));
		result->bytes[i] = ((result->bytes[i]) << despla) | acarreo;
		acarreo = bits_sup >> (8 - despla);
	}
	return result;
}

Apint * producto_Apint (Apint *i1, Apint *i2){
	Apint *result = (Apint *) malloc(sizeof(Apint));
	if(result == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA EL PRODUCTO.");
//		return NULL;
	}
	result->sign = i1->sign;
	result->num_bytes = i1->num_bytes;
	result->bytes = (unsigned char *) calloc(result->num_bytes, sizeof(unsigned char));
	if(result->bytes == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA LOS BYTES DEL PRODUCTO");
//		return NULL;
	}
	Apint *aux;
	for (int i = 0; i < i2->num_bytes; i++){
		for(int j = 0; j < 8; j++){
			if (i2->num_bytes & (1 << j)){
				aux = DI_Apint(i1, j+i*8);
				result = suma_Apint(result, aux);
				free(aux);
			}
		}
	}
	if (i1->sign != i2->sign){
		result->sign = -1;
	}
	else{
		result->sign = 1;
	}
	return result;
}

int main(void) {
	Apint *e1, *e2, *s;
	e1 = (Apint *) malloc(sizeof(Apint));
	if (e1 == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA e1.");
//		return NULL;
	}
	e1->sign = -1;
	e1->num_bytes = 2;
	e1->bytes = (unsigned char *) calloc(e1->num_bytes, sizeof(unsigned char));
	if (e1->bytes != NULL){
		e1->bytes[0] = 83;
		e1->bytes[1] = 4;
	}
	else{
		printf("NO PUDE RESERVAR MEMORIA PARA LOS BYTES DE e1.");
//		return NULL;
	}
	printf("E1:   ");
	imprimir_Apint(e1);

	e2 = (Apint *) malloc(sizeof(Apint));
	if (e2 == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA e1.");
//		return NULL;
	}
	e2->sign = -1;
	e2->num_bytes = 2;
	e2->bytes = (unsigned char *) calloc(e1->num_bytes, sizeof(unsigned char));
	if (e2->bytes != NULL){
		e2->bytes[0] = 6;
		e2->bytes[1] = 0;
	}
	else{
		printf("NO PUDE RESERVAR MEMORIA PARA LOS BYTES DE e1.");
//		return NULL;
	}
	printf("E2:   ");
	imprimir_Apint(e2);

	s = (Apint *)malloc(sizeof(Apint));
	if(s == NULL){
		printf("NO PUDE RESERVAR MEMORIA PARA LA SUMA");
//		return NULL;
	}
	s = suma_Apint(e1,e1);
	printf("\n");
	printf("Suma de E1 con E1: \n");
	printf("E1: ");
	imprimir_Apint(e1);
	printf("+\nE1: ");
	imprimir_Apint(e1);
	printf("---------------------------------\n");
	printf("Suma: ");
	imprimir_Apint(s);
	//desplazamientos
	Apint *D5, *D10;
	D5 = DI_Apint(e1, 5);
	D10 = DI_Apint(e1, 10);
	printf("\n");
	printf("Desplazamiento: \n");
	printf("E1:   ");
	imprimir_Apint(e1);
	printf("---------------------------------\n");
	printf("D5:   ");
	imprimir_Apint(D5);
	printf("---------------------------------\n");
	printf("D10: ");
	imprimir_Apint(D10);
	//producto
	Apint *prod;
	prod = producto_Apint(e1, e2);
	printf("\n");
	printf("Producto entre E1 con E2\n");
	printf("E1:  ");
	imprimir_Apint(e1);
	printf("*\nE2:  ");
	imprimir_Apint(e2);
	printf("---------------------------------\n");
	printf("P:   ");
	imprimir_Apint(prod);
	free(e1->bytes);
	free(e1);
	free(e2->bytes);
	free(e2);
	free(s->bytes);
	free(s);
	free(D5->bytes);
	free(D5);
	free(D10->bytes);
	free(D10);
	free(prod->bytes);
	free(prod);
	return EXIT_SUCCESS;
}
