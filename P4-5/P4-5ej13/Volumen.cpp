/*
 * Volumen.cpp
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#include "Volumen.h"
#include <iostream>
#include <cstring>
using namespace std;
Volumen::Volumen(char* t, char* i, int n) {
	title = new char[strlen(t)+1];
	strcpy(title, t);
	isbn = new char[strlen(t)+1];
	strcpy(isbn, i);
	nroejemplares = n;
}

Volumen::Volumen(const Volumen& v){
	title = new char[strlen(v.title)+1];
	strcpy(title, v.title);
	isbn=new char [strlen(v.isbn)+1];
	strcpy(isbn, v.isbn);
	nroejemplares = v.nroejemplares;
}
char * Volumen::getTitle(void){
	return title;
}

char * Volumen::getIsbn(void){
	return isbn;
}
void Volumen::mostrarDatos(void){
	cout << "El titulo del volumen es: " << title << " y el ISBN: " << isbn << "\n";
}
int Volumen::getNroEjemplares(void){
	return nroejemplares;
}
Volumen::~Volumen(void) {}
