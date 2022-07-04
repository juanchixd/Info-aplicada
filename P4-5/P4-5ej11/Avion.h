/*
 * Avion.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef AVION_H_
#define AVION_H_
#pragma once
#include <iostream>
using std::string;
class Avion{
public:
	Avion(string nv, char* d);
	virtual void mostrarDatos(void);
//	void mostrarDatos(void);
	char* getNombreVuelo(void);
	char* getDestino(void);
	void setDestino(char* d);
	void setNombreVuelo(char* nv);
	~Avion(void);
protected:
	char* nombrevuelo;
	char* destino;
};

#endif /* AVION_H_ */
