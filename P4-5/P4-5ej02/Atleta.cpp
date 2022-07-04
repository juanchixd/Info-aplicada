/*
 * Atleta.cpp
 *
 *  Created on: 29 may. 2022
 *      Author: juan
 */

#include "Atleta.h"
using namespace std;

Atleta::Atleta() {

}
Atleta::Atleta(string nom, string nac, double t, int n){
	nombre = nom;
	nacionalidad = nac;
	tiempo = t;
	numero = n;
}

void Atleta::toString(){
	cout << "Nombre: " << nombre << "\tNacionalidad " << nacionalidad << "\tTiempo: " << tiempo << "\tNumero: " << numero << endl;
}

double Atleta::getTime(){
	return tiempo;
}
string Atleta::getName(){
	return nombre;
}
