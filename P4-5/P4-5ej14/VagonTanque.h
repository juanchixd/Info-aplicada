/*
 * VagonTanque.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef VAGONTANQUE_H_
#define VAGONTANQUE_H_

#include "Vagon.h"
#define PI 3.1415

class VagonTanque: public Vagon {
	double radio;
public:
	VagonTanque();
	VagonTanque(double, double);
	virtual double volumen(void);
	void mostrar();
	virtual ~VagonTanque();
};

#endif /* VAGONTANQUE_H_ */
