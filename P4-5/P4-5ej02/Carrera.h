/*
 * Carrera.h
 *
 *  Created on: 29 may. 2022
 *      Author: juan
 */

#ifndef CARRERA_H_
#define CARRERA_H_
#include "Atleta.h"
using namespace std;
class Carrera {
private:
	int distancia, n=0;
//	Atleta winner;
	Atleta competidores[100];
//	string winnerName;
public:
	Carrera();
	Carrera(int d);
	void detallesWinner();
	void setWinner(Atleta g);
	void setWinner(string n);
	string getWinner();
	void setCompetidor(Atleta c);
	Atleta winner();
};

#endif /* CARRERA_H_ */
