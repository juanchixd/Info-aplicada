/*
 * Magica.h
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#ifndef MAGICA_H_
#define MAGICA_H_

#pragma once
class Magica{
public:
	Magica(int **m, int f, int c);
	bool esCuadrada()const;//true es cuadrada, false no es cuadrada
	int sumafilai(int i)const;
	int sumacolumnai(int i)const;
	int sumadiagpcipal()const;
	int sumadiagsec()const;
	bool esMagica()const;
	~Magica(void);
private:
	int** matriz;
	int filas;
	int columnas;
};

#endif /* MAGICA_H_ */
