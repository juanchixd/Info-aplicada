/*
 * Candado.cpp
 *
 *  Created on: 6 jun. 2022
 *      Author: juan
 */

#include "Candado.h"

Candado::Candado(int c[]) {
	for(int i = 0; i < 3; i++){
		programado[i] = c[i];
		actual[i] = 0;
	}
}

void Candado::alterarDigito(int i, int nro){
	actual[i] = nro;
}

bool Candado::puedeAbrir()const{
	for(int i = 0; i < 3; i++)
		if(programado[i] != actual[i])
			return false;
	return true;
}

bool Candado::mismaCombinacionActual(const Candado c)const{
	for(int i = 0; i < 3; i++)
		if(actual[i] != c.actual[i])
			return false;
	return true;
}

Candado::~Candado(void) {}
