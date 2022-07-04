//============================================================================
// Name        : P4-5ej6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Polinomio.h"
using std::cout;
using std::endl;
int main(void)
{
	double v[]={-2, 3.3, -1.5, 3};
	Polinomio p(3, v);
	cout << endl << "p(x) = " << p << endl;
	double v1[] = {2.0, -1.3, 1.5, -3};
	Polinomio p1(3, v1);
	cout << endl << "p1(x) = " << p1 << endl;
	Polinomio p2(p + p1); // usa sobrecarga de + y constructor de copia
	cout << endl << "p2(p + p1) = " << p2 << endl; // usa sobrecarga de <<
	p2 = p1; // usa sobrecarga de =
	cout << endl << "p(x) += p1(x) = " << (p += p1) << endl; // usa sobrecarga de << yde +=
	Polinomio p3(-p); // usa constructor de copia y sobrecarga de - unario
	cout << endl << "p3(-p) = " << p3 << endl;
	// sobrecarga de < (un polinomio p es menor que otro polinomio p1 si p evaluado en0 da un valor menor que p1 evaluado en 0)
	cout << endl << "p(0) < p1(0) = " << (p < p1) << endl;
	return 0;
}
