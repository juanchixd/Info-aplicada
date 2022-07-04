/*
 * VagonCaja.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "VagonCaja.h"
#include <iostream>
using namespace std;

VagonCaja::VagonCaja():Vagon() {
	ancho = 1;
	alto = 1;
}

VagonCaja::VagonCaja(double l, double h, double a):Vagon(l){
	alto=h;
	ancho=a;
}

double VagonCaja::volumen(void){
	return alto*ancho*getLongitud();
}

void VagonCaja::mostrar(){
	Vagon::mostrar();
	cout<<"tipo Caja, volumen: "<<volumen()<<endl;
}
VagonCaja::~VagonCaja() {}
