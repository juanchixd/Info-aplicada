//============================================================================
// Name        : P4-5ej11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "AvionHidrante.h"
#include "AvionPasajeros.h"
#include <iostream>
using std::cout;
int main(void){
	AvionPasajeros ap("AZ19B2", "Londres", 2400, 270.5);
	AvionHidrante ah("BT3533P8", "Bariloche", 500);
	ap.mostrarDatos();
	ah.mostrarDatos();
	ah.descargarAgua(300);
	ah.mostrarDatos();
	ah.descargarAgua();
	ah.mostrarDatos();
	Avion **AA =new Avion*[2];
	AA[0]=&ap;
	AA[1]=&ah;
	cout<<"ahora muestro con los punteros\n";
	AA[0]->mostrarDatos();
	AA[1]->mostrarDatos();
	delete[]AA;

	return 0;
}
