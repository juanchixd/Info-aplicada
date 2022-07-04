/*
 * AvionHidrante.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef AVIONHIDRANTE_H_
#define AVIONHIDRANTE_H_
#pragma once
#include "Avion.h"
class AvionHidrante :public Avion
{
private:
	int litrosAgua;
	int capacidad;
public:
	AvionHidrante(char* nv, char* d, int l);
	void descargarAgua(int l);
	void descargarAgua();
	void mostrarDatos(void);
	~AvionHidrante(void);
};
#endif /* AVIONHIDRANTE_H_ */
