/*
 * VagonTanque.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "VagonTanque.h"
#include <iostream>
using namespace std;

VagonTanque::VagonTanque(){
	radio = 1;
}

VagonTanque::VagonTanque(double l, double r):Vagon(l){
	radio=r;
}

double VagonTanque::volumen(void){
	return PI*radio*radio*getLongitud();
}

void VagonTanque::mostrar(){
	Vagon::mostrar();
	cout<<"tipo Tanque, volumen: "<<volumen()<<endl;
}
VagonTanque::~VagonTanque() {
	// TODO Auto-generated destructor stub
}

