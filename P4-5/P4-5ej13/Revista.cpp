/*
 * Revista.cpp
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#include "Revista.h"
#include <iostream>
using std::cout;
using std::endl;
Revista::Revista(char* t, char* i, int a, int nror, int n):Volumen(t, i, n) {
	año = a;
	nrorevista=nror;
}
int Revista::getaño(void){
	return año;
}
int Revista::getnrorevista(void){
	return nrorevista;
}
void Revista::mostrarDatos(void){
	Volumen::mostrarDatos();
	cout << "El año de la revista es: " << año << ", el numero es: " << nrorevista <<
			" y la cantidad de ejemplares que hay es: " << nroejemplares << "\n";
}
void Revista::setDatos(char* t, char* i, int a, int nror, int n){
	Volumen::setDatos(t, i, n);
	año=a;
	nrorevista=nror;
}
Revista::~Revista() {}
