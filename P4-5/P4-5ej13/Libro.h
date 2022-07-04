/*
 * Libro.h
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include "Volumen.h"

class Libro: public Volumen {
public:
	Libro(char* t="", char* i="", char* a="", char* e="", int n=1);
	Libro(const Libro& otro);
	char* getautor();
	char* geteditorial();
	virtual void mostrarDatos(void);
	void setDatos(char* t, char* i, char* a, char* e, int n);
	~Libro(void);
private:
	char* autor;
	char* editorial;
};

#endif /* LIBRO_H_ */
