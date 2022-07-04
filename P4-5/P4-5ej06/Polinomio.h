/*
 * Polinomio.h
 *
 *  Created on: 26 may. 2022
 *      Author: juan
 */

#ifndef POLINOMIO_H_
#define POLINOMIO_H_
#include <iostream>
using namespace std;
class Polinomio
{
public:
	Polinomio();
	Polinomio(const Polinomio& p);
	Polinomio(int n, double []);
	int getOrden()const;
	double getCoef(int p)const;
	double* calcular(int limite);
	double evaluar (double) const;
	~Polinomio(void);
	Polinomio& operator= (const Polinomio& p);
	Polinomio operator+ (const Polinomio&) const;
	Polinomio& operator+= (const Polinomio& p);
	bool operator< (const Polinomio& p) const;
	bool operator== (const Polinomio& p);
	friend ostream& operator<< (ostream& o, const Polinomio& p);
	friend Polinomio operator- (const Polinomio& p);
private:
	int orden;
	double *coef;
};
#endif /* POLINOMIO_H_ */
