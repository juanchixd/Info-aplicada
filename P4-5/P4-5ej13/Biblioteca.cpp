/*
 * Biblioteca.cpp
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca(void) {
	i=0;
}

bool Biblioteca::añadirVolumen(Volumen* v){
	bool agregado=false;
	if(i<MAX){
		volumenes[i]=v;
		i++;
		agregado=true;
	}
	return agregado;
}
Biblioteca::~Biblioteca(void) {}

