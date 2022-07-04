/*
 * AvionHidrante.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "AvionHidrante.h"
#include <iostream>
using namespace std;
using std::cout;
AvionHidrante::AvionHidrante(char* nv, char* d, int c):Avion(nv, d){
	capacidad=c;
	litrosAgua=c;
}
void AvionHidrante::descargarAgua(int l){
	litrosAgua -=l;
}
void AvionHidrante::descargarAgua(){
	litrosAgua=0;
}
void AvionHidrante::mostrarDatos(){
	Avion::mostrarDatos();
	cout<<"La capacidad en litros de agua es: "<<capacidad<<". Actualmente le quedan: "<<litrosAgua<<"litros de agua\n";
}
AvionHidrante::~AvionHidrante(void){
}

