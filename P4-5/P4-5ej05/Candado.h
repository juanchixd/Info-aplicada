/*
 * Candado.h
 *
 *  Created on: 6 jun. 2022
 *      Author: juan
 */

#ifndef CANDADO_H_
#define CANDADO_H_

class Candado {
public:
	Candado(int []);
	void alterarDigito(int i, int nro);
	bool puedeAbrir()const;
	bool mismaCombinacionActual(const Candado c)const;
	~Candado();
private:
	int programado[3];
	int actual[3];
};

#endif /* CANDADO_H_ */
