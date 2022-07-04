/*
 * Carriage.h
 *
 *  Created on: 29 may. 2022
 *      Author: juan
 */

#ifndef SRC_CARRIAGE_H_
#define SRC_CARRIAGE_H_
#include <cmath>
using namespace std;
class Carriage {
private:
	bool seats[40];
	bool primera;
public:
	Carriage();
	Carriage(bool prim);
	int getSeats();
	bool getPrimera(){
		return primera;
	}
	void setPrimera(bool p){
		primera = p;
	}
	void ocupar();
	void mostrar();
};

#endif /* SRC_CARRIAGE_H_ */
