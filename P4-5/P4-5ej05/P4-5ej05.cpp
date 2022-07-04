//============================================================================
// Name        : P4-5ej05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Candado.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int p1[] = {3,2,1}, p2[] = {1,2,3};
	Candado c1 = Candado(p1);
	Candado c2 = Candado(p2);
	c1.alterarDigito(0,3);
	c1.alterarDigito(1,2);
	c1.alterarDigito(2,1);
	if(c1.puedeAbrir())
		cout << "El candado se puede abrir\n";
	else
		cout << "El candado no se puede abrir\n";
	if(c1.mismaCombinacionActual(c2))
		cout << "Los dos candados tienen la misma combinacion actual\n";
	else
		cout << "Los dos candados no tienen la misma combinacion actual\n";
	return 0;
}
