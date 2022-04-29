/*
 ============================================================================
 Name        : P1ej01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 8, *pi=&i;
	long long l = 8, *pl=&l;
	float f = 102.8f, *pf=&f;
	double d = 678.44, *pd=&d;
	int vec[100];
	vec[0] = 44;
	printf("Variable int,\t tam.bytes: %d \tdir.&i: %p \t\tvalor: %d\n", sizeof(i), &i, i);
	printf("Puntero int,\t tam.bytes: %d \tdir.&pi: %p \tvalor: %p\n", sizeof(pi), &pi, pi);
	printf("Variable long,\t tam.bytes: %d \tdir.&l: %p \t\tvalor: %ld\n", sizeof(l), &l, l);
	printf("Puntero long,\t tam.bytes: %d \tdir.&pl: %p \tvalor: %p\n", sizeof(pl), &pl, pl);
	printf("Variable float,\t tam.bytes: %d \tdir.&f: %p \t\tvalor: %.1f\n", sizeof(f), &f, f);
	printf("Puntero float,\t tam.bytes: %d \tdir.&pf: %p \tvalor: %p\n", sizeof(pf), &pf, pf);
	printf("Variable double, tam.bytes: %d \tdir.&d: %p \t\tvalor: %.2lf\n", sizeof(d), &d, d);
	printf("Puntero double,\t tam.bytes: %d \tdir.&pd: %p \tvalor: %p\n", sizeof(pd), &pd, pd);
	printf("Variable array,\t tam.bytes: %d \tdir.&vec[0]: %p \tvalor: %d\n", sizeof(vec[0]), &vec[0], vec[0]);
	printf("Puntero array,\t tam.bytes: %d dir.&vec: %p \tvalor: %p\n", sizeof(vec), &vec, vec);
	return EXIT_SUCCESS;
}
