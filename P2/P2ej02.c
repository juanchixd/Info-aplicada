/*
 ============================================================================
 Name        : P2ej02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int n;
	double *coeficiente;
}Polinomio;

Polinomio * creaPolinomio(int orden){
	Polinomio *p=NULL;
	p = (Polinomio *) malloc(sizeof(Polinomio));
	p->n = orden;
	p->coeficiente = (double *) calloc((orden+1), sizeof(double));
	return p;
}

void setCoef(int n, double c, Polinomio * P){
	if(n<=P->n){
		P->coeficiente[n] = c;
	}
}

double getCoef(int n, Polinomio *p){
	return p->coeficiente[n];
}

double especializa(double x, Polinomio *p){
	double suma=0;
	for(int i=0; i<=p->n; i++){
		suma+=p->coeficiente[i]*pow(x,i);
	}
	return suma;
}

Polinomio *sum(Polinomio *p1, Polinomio *p2){
	Polinomio *ps, *mayor;
	int orden, menor;
	if(p1->n>=p2->n){
		orden = p1->n;
		menor = p2->n;
		mayor = p1;
	}
	else{
		orden = p2->n;
		menor = p1->n;
		mayor = p2;
	}
	ps = creaPolinomio(orden);
	for(int i=0; i <=menor ; i++){
		ps->coeficiente[i] += p1->coeficiente[i]+p2->coeficiente[i];
	}
	for(int i=menor + 1; i <= mayor->n; i++){
		ps->coeficiente[i] += mayor->coeficiente[i];
	}
	return ps;
}

Polinomio * mult(Polinomio *p1, Polinomio *p2){
	Polinomio *ps;
	int orden=p1->n+p2->n;
	ps=creaPolinomio(orden);
	for(int i=0; i <=p1->n; i++){
		for(int j=0; j<=p2->n; j++){
			ps->coeficiente[i+j]+=(p1->coeficiente[i])*(p2->coeficiente[j]);
		}
	}
	return ps;
}

void destruyePolinomio(Polinomio *p){
	free(p->coeficiente);
	free(p);
}

Polinomio *deriv(Polinomio *p){
	Polinomio *pd;
	int orden=p->n;
	pd=creaPolinomio(orden);
	for(int i = orden; i >=1; i--){
		pd->coeficiente[i-1]=i*p->coeficiente[i];
	}
	return pd;
}

double ceropol(Polinomio *p, double a, double b, double epsilon){
	double c, pa, pb, pc;
	while(fabs(a-b)>=epsilon){
		c=(a+b)/2;
		pa = especializa(a, p);
		pb = especializa(b, p);
		pc = especializa(c, p);
		if(pc == 0){
			return c;
		}
		if(pa * pc > 0){
			a = c;
		}
		else if(pa * pc < 0){
			b = c;
		}
	}
	return c;
}

int main(void) {
	Polinomio *p = creaPolinomio(2);
	setCoef(0, 4, p);
	setCoef(1, -12, p);
	setCoef(2, 32, p);
	setCoef(3, -55, p);
	printf("%lf ", especializa(1.0, p));

	return EXIT_SUCCESS;
}
