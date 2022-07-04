/*
 * Polinomio.cpp
 *
 *  Created on: 26 may. 2022
 *      Author: juan
 */

#include "Polinomio.h"
#include <math.h>
Polinomio::Polinomio(int n, double *v)
{
	orden=n;
	coef=new double[n+1];
	for(int i=0;i<(n+1);i++)
		coef[i]=v[i];

}
Polinomio::Polinomio(){ coef = 0;}
Polinomio::Polinomio(const Polinomio& p)
{
	orden = p.orden;
	coef = new double[orden+1];
	for(int i=0;i<orden+1;i++)
		coef[i]=p.coef[i];

}
int Polinomio::getOrden()const
{
	return orden;
}
double Polinomio::getCoef(int n) const
{
	return coef[n];
}
double Polinomio::evaluar(double d) const{
	double res = 0;
	for(int i = 0; i < orden + 1; i++)
		res += pow(d, i) * coef[i];
	return res;
}
bool Polinomio::operator< (const Polinomio& p) const {
	return this->evaluar(0.0) < p.evaluar(0.0);
}
double* Polinomio::calcular(int limite)//no puedo retornar array
{
	double *p=new double[limite+1];
	double suma;
	for(int i=0;i<=limite;i++){
		suma=0;
		for(int j=0;j<=orden;j++)
			suma+=pow((double)i,j)*coef[j];
		p[i]=suma;
	}
	return p;
}
Polinomio::~Polinomio(void)
{
	delete[] coef;
}
Polinomio& Polinomio::operator= (const Polinomio& p)
{
	if(this == &p) return *this;
	delete[] coef;
	coef = new double[p.orden + 1];
	for(int i=0;i<p.orden+1;i++)
		this->coef[i]=p.coef[i];
	this->orden = p.orden;
	return *this;
}
Polinomio& Polinomio::operator+= (const Polinomio& p)
			{
	*this = *this + p;
	return *this;
			}
bool Polinomio::operator== (const Polinomio& p)
			{
	if(this->orden != p.orden) return false;
	int i = 0;
	while((coef[i] == p.coef[i]) && (i < orden + 1)) i++;
	return (i == orden+1);
			}
Polinomio Polinomio::operator+ (const Polinomio& p) const {
	int sum_ord = this->orden > p.orden ? this->orden : p.orden;
	int ordenMin = this->orden < p.orden ? this->orden : p.orden;
	double * sum_coef = new double [sum_ord + 1];
	for (int i = 0; i < ordenMin + 1; i++) sum_coef[i] = this->coef[i] + p.coef[i];
	for (int i = ordenMin + 1; i < sum_ord + 1; i++)
		sum_coef[i] = this->orden > p.orden ? this->coef[i] : p.coef[i];
	int i = sum_ord;
	while(abs(sum_coef[i--]) < 1e-5) sum_ord--;
	return Polinomio(sum_ord, sum_coef);
}
Polinomio operator- (const Polinomio& p) {
	double * c = new double(p.getOrden() + 1);
	for (int i = 0; i < p.getOrden() + 1; i++)
		c[i] = -p.getCoef(i);
	return Polinomio(p.getOrden(), c);
}
ostream& operator<< (ostream& o, const Polinomio& p) {
	for (int i = p.orden; i > 0; i--)
		o << p.coef[i] << "x^" << i << " + ";
	o << p.coef[0];
	return o;
}
