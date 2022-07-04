//============================================================================
// Name        : P4-5ej13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Biblioteca.h"
#include "Revista.h"
#include "Libro.h"
using namespace std;
using std::cout;
using std::endl;

int main() {
	Libro l("Programacion en lenguajes estructurados", "823-12312-5434", "MA. Asuncion Criado Clavero", "Alfaomega", 1);
	Revista r("Lugares", "9784113", 2011, 189, 2);
	Biblioteca b;
	b.añadirVolumen(&l);
	b.añadirVolumen(&r);
	b.mostrarDatos();
	return 0;
}
