/*
 * main.cpp
 *
 *  Created on: 19 may. 2022
 *      Author: juan
 */

#include <iostream>
#include "Atleta.h"
#include "Carrera.h"
using std::cout;
using std::endl;

Atleta mejorTiempo(Atleta a1, Atleta a2){
	if(a1.getTime()<a2.getTime())
		return a1;
	else if (a2.getTime()<a1.getTime())
		return a2;
}

int main() {
	Carrera c1(500);
	Atleta a1("Pedro", "Peru", 500, 10);
	Atleta a2("Felipe", "Colombia", 400, 9);
	Atleta a3("Roberto", "Argentina", 600, 11);
	Atleta a4("Rodolfo", "Brasil", 355, 9);
	a1.toString();
	a2.toString();
	a3.toString();
	a4.toString();
//	cout << "El ganador es: " << mejorTiempo(a1,a2).getName() << endl;
//	c1.setWinner(mejorTiempo(a1,a2));
//	c1.detallesWinner();
//	c1.setWinner(mejorTiempo(a1,a2).getName());
//	cout << "Ganador de la carrera: " << c1.getGanador() << endl;
	c1.setCompetidor(a1);
	c1.setCompetidor(a2);
	c1.setCompetidor(a3);
	c1.setCompetidor(a4);
	cout<< "El ganador entre los competidores essss::: " << c1.winner().getName() << endl;
	return 0;
}
