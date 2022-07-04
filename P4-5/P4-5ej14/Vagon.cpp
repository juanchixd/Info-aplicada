/*
 * Vagon.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "Vagon.h"
#include <iostream>
using namespace std;
Vagon::Vagon() {
	longitud=1;
}

Vagon::Vagon(double l){
	longitud=l;
}
double Vagon::getLongitud(){return longitud;} //devuelve la longitud
void Vagon::setLongitud(double l){longitud=l;} //setea la longitud en l
void Vagon::mostrar(){cout<<"Es un vagon de longitud:"<<longitud<<", " ;} //muestra la longitud del vagon

Vagon::~Vagon() {
}

