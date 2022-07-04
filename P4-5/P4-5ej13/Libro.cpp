/*
 * Libro.cpp
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#include "Libro.h"
#include <iostream>
#include <cstring>
using namespace std;
using std::cout;
using std::endl;

Libro::Libro(char* t, char* i, char* a, char* e, int n):Volumen(t, i, n) {
	autor = new char[strlen(a)+1];
	strcpy(autor, a);
	editorial = new char[strlen(e)+1];
	strcpy(editorial, e);
}
Libro::Libro(const Libro& l):Volumen(l){
	autor = new char[strlen(l.autor)+1];
	strcpy(autor, l.autor);
	editorial = new char[strlen(l.editorial)+1];
	strcpy(editorial, l.editorial);
}

char* Libro::getautor(void){
	return autor;
}
char* Libro::geteditorial(void){
	return editorial;
}
void Libro::mostrarDatos(void){
	Volumen::mostrarDatos();
	cout << "El autor del libro es: " << autor << ", la editorial: " << editorial << "y la cantidad de volumenes: " << nroejemplares << "\n";
}
void Libro::setDatos(char* t, char* i, char* a, char* e, int n){
	Volumen::setDatos(t,i,n);
	autor = new char[strlen(a)+1];
	strcpy(autor, a);
	editorial = new char[strlen(e)+1];
	strcpy(editorial, e);
}
Libro::~Libro(void) {}
