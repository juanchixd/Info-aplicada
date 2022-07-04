/*
 * VagonCaja.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef VAGONCAJA_H_
#define VAGONCAJA_H_

#include "Vagon.h"

class VagonCaja: public Vagon {
	double ancho;
	double alto;
public:
	VagonCaja();
	VagonCaja(double, double, double);
	virtual double volumen(void);
	void mostrar();
	virtual ~VagonCaja();
};

#endif /* VAGONCAJA_H_ */
