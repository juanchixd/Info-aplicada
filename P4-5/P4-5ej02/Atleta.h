/*
 * Atleta.h
 *
 *  Created on: 29 may. 2022
 *      Author: juan
 */

#ifndef ATLETA_H_
#define ATLETA_H_
#include <string>
#include <iostream>
using namespace std;

class Atleta {
private:
	string nombre;
	string nacionalidad;
	double tiempo;
	int numero;
public:
	Atleta(string nom, string nac, double t, int n);
	Atleta();
	void toString();
	double getTime();
	string getName();
};

#endif /* ATLETA_H_ */
