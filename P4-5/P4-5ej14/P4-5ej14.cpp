//============================================================================
// Name        : P4-5ej14.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Tren.h"
#include "VagonTanque.h"
#include "VagonCaja.h"
#include <iostream>
using namespace std;
using std::cout;
int main() {
	VagonCaja VC1(2.3,5,8.9);
	VagonTanque VT1(2,3);
	VagonCaja VC2(2.6,5,9);
	VagonTanque VT2(3,6);
	VC1.mostrar();
	VT1.mostrar();
	Tren t(9);
	t.añadirVagon(&VC1);
	t.añadirVagon(&VC2);
	t.añadirVagon(&VT2);
	t.añadirVagon(&VT1);
	t.mostrar();
	return 0;
}
