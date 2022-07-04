/*
 * Carriage.cpp
 *
 *  Created on: 29 may. 2022
 *      Author: juan
 */

#include "Carriage.h"
#include <iostream>
using namespace std;
Carriage::Carriage(){
}

Carriage::Carriage(bool prim) {
	primera = prim;
	for(int i=0; i < 40; i++)
		seats[i]=0;
}
void Carriage::ocupar(){
	for(int i = 0; i< 40; i++){
		int prob = rand() %100;
		if(primera == 1 && prob < 10)
			seats[i]=1;
		else if (primera == 0 && prob < 40)
			seats[i]=1;
	}
}

void Carriage::mostrar(){
	if(primera == 1)
		cout << "Es un vagon de primera clase" << endl;
	else
		cout << "Es un vagon de segunda clase" << endl;
	for(int i = 0; i< 40; i++){
		if(seats[i] == 1)
			cout << (i+1) << "\t->\t" << "ocupado\n" << endl;
		else
			cout << (i+1) << "\t->\t" << "libre\n" << endl;
	}
}

int Carriage::getSeats(){
	int ocupados=0;
	for(int i=0; i<40; i++)
		if(seats[i]==1)
			ocupados++;
	return ocupados;
}
