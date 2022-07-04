/*
 * AvionPasajeros.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "AvionPasajeros.h"
#include <iostream>
using std::cout;
AvionPasajeros::AvionPasajeros(char* nv, char* d, int du, double p):Avion(nv,d){
	duracionVuelo=du;
	pesoEquipaje=p;
}
void AvionPasajeros::mostrarDatos(void){
	Avion::mostrarDatos();//reutilizo código
	cout<<"La duracion del mismo: "<<duracionVuelo<<" minutos, con capacidad maxima para equipaje: "<<pesoEquipaje<<"\n";
}
AvionPasajeros::~AvionPasajeros(void){
}
