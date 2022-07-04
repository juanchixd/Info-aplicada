/*
 * Vagon.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef VAGON_H_
#define VAGON_H_
class Vagon {
private:
	double longitud;
public:
	Vagon();
	Vagon(double);
	virtual double volumen(void)=0;
	double getLongitud();
	void setLongitud(double);
	virtual void mostrar();
	virtual ~Vagon();
};

#endif /* VAGON_H_ */
