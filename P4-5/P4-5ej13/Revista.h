/*
 * Revista.h
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#ifndef REVISTA_H_
#define REVISTA_H_

#include "Volumen.h"
class Revista: public Volumen {
public:
	Revista(char* t="", char* i="", int a=0, int nror=0, int n=1);
	int getaño(void);
	int getnrorevista(void);
	virtual void mostrarDatos(void);
	void setDatos(char* t, char* i, int a, int nror, int n);
	~Revista(void);
private:
	int año;
	int nrorevista;
};
#endif /* REVISTA_H_ */
