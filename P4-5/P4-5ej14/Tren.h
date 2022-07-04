/*
 * Tren.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef TREN_H_
#define TREN_H_
#define NoPuedeSuperar 35
#include "Vagon.h"

class Tren{
private:
	Vagon **vagones;
	int ind;
	int cantMaxvagones;
public:
	Tren();
	Tren(int);
	bool añadirVagon(Vagon*);
	void mostrar();
	double volumenTotal(void);
	virtual ~Tren();
};

#endif /* TREN_H_ */
