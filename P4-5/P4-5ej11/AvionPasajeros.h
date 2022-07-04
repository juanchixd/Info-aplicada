/*
 * AvionPasajeros.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef AVIONPASAJEROS_H_
#define AVIONPASAJEROS_H_
#pragma once
#include "Avion.h"
class AvionPasajeros :
		public Avion
{
public:
	AvionPasajeros(char* nv, char* d, int du, double p);
	void mostrarDatos(void);
	~AvionPasajeros(void);
private:
	int duracionVuelo; //en minutos
	double pesoEquipaje;
};
#endif /* AVIONPASAJEROS_H_ */
