/*
 * Train.cpp
 *
 *  Created on: 2 jun. 2022
 *      Author: juan
 */

#include "Train.h"
using namespace std;
Train::Train() {
}
void Train::setNumberVagones(int n){
//	cout << "Este tren tiene" << n << "vagones" << endl;
	nvagones = n;
	vagones = new Carriage[n];
	for (int i=0; i<n; i++){
		int v=rand()%2;
		vagones[i].setPrimera(v);
		vagones[i].ocupar();
//		vagones[i].mostrar();
	}
}

void Train::setStation(string e1, string e2){
	estInit += e1;
	estEnd += e2;
}

void Train::setPrice(int p1, int p2){
	precio1 = p1, precio2 = p2;
}

void Train::total(){
	int clase1=0, clase2=0, asientos1=0, asientos2=0;
	for(int i=0; i <nvagones; i++){
		if(vagones[i].getPrimera()==1){
			clase1++;
			asientos1 += vagones[i].getSeats();
		}
		else{
			clase2++;
			asientos2 += vagones[i].getSeats();
		}
	}
	cout << "Este tren tiene " << clase1 << " vagones de clase 1 y " << clase2 << " vagones de clase 2 " << endl;
	cout << "En primera clase se ocuparon " << asientos1 << " asientos y se recaudo " << (asientos1*precio1) << endl;
	cout << "En segunda clase se ocuparon " << asientos2 << " asientos y se recaudo " << (asientos2*precio2) << endl;
	cout << "Total: " << (asientos1*precio1+asientos2*precio2) << endl;
}
