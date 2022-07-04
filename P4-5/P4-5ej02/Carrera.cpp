/*
 * Carrera.cpp
 *
 *  Created on: 29 may. 2022
 *      Author: juan
 */

#include "Carrera.h"

Carrera::Carrera() {
}

Carrera::Carrera(int d){
	distancia = d;
}
//
//void Carrera::detallesWinner(){
//	cout << "El ganador es: " << endl;
//	winner.toString();
//}
//void Carrera::setWinner(Atleta g){ winner = g;}
//
//void Carrera::setWinner(string n){
//	winnerName = n;
//}
//string Carrera::getWinner(){
//	return winnerName;
//}

void Carrera::setCompetidor(Atleta c){
	competidores[n] = c;
	n++;
}

Atleta Carrera::winner(){
	int mejor=0, posicion;
	for(int i=0; n!=0 && i<n; i++){
		if(i==0){
			mejor = competidores[i].getTime();
		}
		if(i!=0 && competidores[i].getTime() < mejor){
			mejor = competidores[i].getTime();
			posicion = i;
		}
	}
	return competidores[posicion];
}
