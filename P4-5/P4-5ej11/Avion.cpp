/*
 * Avion.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "Avion.h"
#include <cstring>
#include <string.h>
#include <iostream>

using std::cout;
using std::string;
Avion::Avion(string nv, char* d){
//	nombrevuelo=nv;
//	nombrevuelo=new char[strlen(nv)+1];
	strncpy(nombrevuelo,nv);
	destino=new char[strlen(d)+1];
	strncpy(destino, d, strlen(d)+1);
}
char* Avion::getDestino(void){
	return destino;
}
char* Avion::getNombreVuelo(void){
	return nombrevuelo;
}
void Avion::setDestino(char* d){
	delete [] destino;
	destino=new char[strlen(d)+1];
	strcpy(destino, d);
}
void Avion::setNombreVuelo(char* nv){
	delete [] nombrevuelo;
	nombrevuelo=new char[strlen(nv)+1];
	strcpy(nombrevuelo,nv);
}
void Avion::mostrarDatos(void){
	cout<<"El vuelo se llama: "<<nombrevuelo<<" y tiene destino: "<<destino<<"\n";
}
Avion::~Avion(void){
	delete[]destino;
}
