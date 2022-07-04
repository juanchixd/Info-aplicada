/*
 * Tren.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "Tren.h"

Tren::Tren() {
	// TODO Auto-generated constructor stub

}
Tren::Tren(int n){
	if(n>NoPuedeSuperar)
		cantMaxvagones =35;
	else
		cantMaxvagones=n;
	vagones = new Vagon*[cantMaxvagones];
	ind=0;
}

bool Tren::añadirVagon(Vagon *v1){
	bool dev=false;
	if(ind<cantMaxvagones){
		vagones[ind]=v1;
		ind++;
		dev=true;
	}
	return dev;
}
double Tren::volumenTotal(){
	double total=0;
	for(int i=0;i<ind;i++)
		total += vagones[i]->volumen();
	return total;
}

void Tren::mostrar(){
	for(int i=0; i<ind;i++)
		vagones[i]->mostrar();
}
Tren::~Tren() {
	delete []vagones;
}

