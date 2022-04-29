/*
 ============================================================================
 Name        : P1ej08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 200
#define MAXLINES 20


int etline(char s[], int lim){
	int c, i;
	for(i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++){
		s[i]=c;
	}
	if (c == '\n'){
		s[i]=c;
		i++;
	}
	s[i] = '\0';
	return i;
}

int readlines(char *linea[], int max){
	int nlines, len;
	char * p;
	char line[MAXLINES];
	nlines = 0;
	while ((len = etline(line, MAXLINES)) > 1){
		p = (char *) malloc(len*sizeof(char));
		if (nlines >=max || p ==NULL){
			return -1;
		}
		else{
			line[len -1] = '\0';
			strcpy(p, line);
			linea[nlines] = p;
			nlines++;
		}
	}
	return nlines;
}


int main(void) {
	int i,j;
	char c;
	int cuenta[256] = {0};
	char *line[MAXLINES];
	int cantlineas = readlines(line, MAXLINES);
	for (i=0; i < cantlineas; i++){
		j = 0;
		while((c = line[i][j])){
			cuenta[c]++;
			j++;
		}
	}
	for(i=0; i < 256; i++){
		printf("\t%c - %d", i, cuenta[i]);
		if(!(i%4)){
			printf("\n");
		}
	}
}
