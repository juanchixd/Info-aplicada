/*
 * Volumen.h
 *
 *  Created on: 9 jun. 2022
 *      Author: juan
 */

#ifndef VOLUMEN_H_
#define VOLUMEN_H_

class Volumen {
public:
	Volumen(char* t="", char* i="", int n=1);
	Volumen(const Volumen& v);
	char *getTitle(void);
	char *getIsbn(void);
	int getNroEjemplares(void);
	virtual void mostrarDatos(void);
	void setDatos(char *t, char *i, int n);
	~Volumen(void);
protected:
	char* title;
	char* isbn;
	int nroejemplares;
};

#endif /* VOLUMEN_H_ */
