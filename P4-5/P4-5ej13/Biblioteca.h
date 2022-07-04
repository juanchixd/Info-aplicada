/*
 * Biblioteca.h
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include "Volumen.h"

class Biblioteca: public Volumen {
public:
	Biblioteca(void);
	void mostrarDatos(void);
	bool añadirVolumen(Volumen* v);
	~Biblioteca(void);
private:
	static const int MAX=100;
	Volumen* volumenes[MAX];
	int i;
};
#endif /* BIBLIOTECA_H_ */
