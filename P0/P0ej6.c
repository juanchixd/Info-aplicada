/*
 ============================================================================
 Name        : P0ej6.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
	char a;
	short int b;
	int c;
	long int d;
	unsigned char e;
	unsigned short int f;
	unsigned int g;
	unsigned long int h;
	float i;
	double j;
	long double k;
	printf ("Longitud de cada uno de los tipos basicos \n\n");
	printf ("La longitud de char a= %d\n",sizeof(a));
	printf ("La longitud de short int b= %d\n",sizeof(b));
	printf ("La longitud de int c= %d\n",sizeof(c));
	printf ("La longitud de long int d= %d\n",sizeof(d));
	printf ("La longitud de unsigned char e= %d\n",sizeof(e));
	printf ("La longitud de unsigned short int f= %d\n",sizeof(f));
	printf ("La longitud de unsigned int g= %d\n",sizeof(g));
	printf ("La longitud de unsigned long int h= %d\n",sizeof(h));
	printf ("La longitud de float i= %d\n",sizeof(i));
	printf ("La longitud de double j= %d\n",sizeof(j));
	printf ("La longitud de long double k= %d\n",sizeof(k));
	printf("\nValores minimos y maximos de cada uno de los tipos\n\n");
	printf ("Minimo y maximo de char a= %d\t\t%d\n",CHAR_MIN,CHAR_MAX);
	printf ("Minimo y maximo de short int b=%d\t\t%d\n",SHRT_MIN,SHRT_MAX);
	printf ("Minimo y maximo de int c= %d\t\t%d\n",INT_MIN,INT_MAX);
	printf ("Minimo y maximo de long int d=%d\t\t%d\n",LONG_MIN,LONG_MAX);
	printf ("Maximo de unsigned char e= %d\n",UCHAR_MAX);
	printf ("Maximo de unsigned short int f= %d\n",USHRT_MAX);
	printf ("Maximo de unsigned int g= %d\n",UINT_MAX);
	printf ("Maximo de unsigned long int h= %d\n",ULONG_MAX);
	printf ("Minimo y maximo de float i= %d\t\t%d\n",FLT_MIN,FLT_MAX);
	printf ("Minimo y maximo de double j= %d\t\t%d\n",DBL_MIN,DBL_MAX);
	printf ("Minimo y maximo de long double k=%d\t\t%d\n",LDBL_MIN,LDBL_MAX);
}
