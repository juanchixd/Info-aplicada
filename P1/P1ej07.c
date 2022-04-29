/*
 ============================================================================
 Name        : P1ej07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int general(int num, int base, char * buffer) {
	int i = 0;
	int cociente = num;
	while(cociente > (base - 1)) {
		buffer[i++] = cociente%base + (cociente%base > 9 ? 'A' - 10 : '1' - 1);
		cociente /= base;
	}
	buffer[i++] = cociente + (cociente%base > 9 ? 'A' - 10 : '1' - 1);
	buffer[i] = '\0';
	return i;
}

int bin(int num, char *buffer){
	int i = 0;
	int cociente = num;
	while(cociente > (2 - 1)){
		buffer[i++] = cociente%2 + (cociente%2 > 9 ? 'A' - 10 : '1' - 1);
		cociente /= 2;
	}
	buffer[i++] = cociente + (cociente%2 > 9 ? 'A' - 10 : '1' - 1);
	buffer[i]='\0';
	return i;
}

int dec(int num, char *buffer){
	int i = 0;
	int cociente = num;
	while(cociente > (10 - 1)){
		buffer[i++] = cociente%10 + (cociente%10 > 9 ? 'A' - 10 : '1' - 1);
		cociente /= 10;
	}
	buffer[i++] = cociente + (cociente%10 > 9 ? 'A' - 10 : '1' - 1);
	buffer[i]='\0';
	return i;
}

int oct(int num, char *buffer){
	int i = 0;
	int cociente = num;
	while(cociente > (8 - 1)){
		buffer[i++] = cociente%8 + (cociente%8 > 9 ? 'A' - 10 : '1' - 1);
		cociente /= 8;
	}
	buffer[i++] = cociente + (cociente%8 > 9 ? 'A' - 10 : '1' - 1);
	buffer[i]='\0';
	return i;
}

int hex(int num, char *buffer){
	int i = 0;
	int cociente = num;
	while(cociente > (16 - 1)){
		buffer[i++] = cociente%16 + (cociente%16 > 9 ? 'A' - 10 : '1' - 1);
		cociente /= 16;
	}
	buffer[i++] = cociente + (cociente%16 > 9 ? 'A' - 10 : '1' - 1);
	buffer[i]='\0';
	return i;
}


int main(void) {
	int i;
	char buffer[40];
	char * buf;
	//int len = general(1234, 2, buffer);
	int len = hex(1234, buffer); //bin, dec, oct, hex
	buf = (char *) malloc(len);
	if(buf == NULL){
		printf("Che, no pude reservar memoria");
		return -1;
	}
	printf("\n\n");
	buf[len] = buffer[len];
	for(i = len - 1; i >= 0; i--) buf[len-1-i] = buffer[i];
	printf("%s", buf);
}
