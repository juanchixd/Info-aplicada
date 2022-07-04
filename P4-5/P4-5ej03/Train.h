/*
 * Train.h
 *
 *  Created on: 2 jun. 2022
 *      Author: juan
 */

#ifndef SRC_TRAIN_H_
#define SRC_TRAIN_H_
#include "Carriage.h"
#include <string>
#include <iostream>
class Train : public Carriage {
private:
	Carriage *vagones;
	int precio1=0, precio2=0, nvagones=1;
	string estEnd = "Llegada", estInit = "Partida";
public:
	Train();
	void setPrice(int p1, int p2);
	void setStation(string e1, string e2);
	void setNumberVagones(int n);
	void total();
};

#endif /* SRC_TRAIN_H_ */
