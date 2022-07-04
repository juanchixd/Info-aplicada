#include <iostream>
#include "Train.h"
using std::cout;
using std::endl;

int main() {
//	Carriage c(0);
//	c.ocupar();
//	c.mostrar();
	int n=20;
	Train t;
	t.setNumberVagones(n);
	t.setPrice(100, 50);
	t.setStation("Rosario", "Cordoba");
	t.total();
	return 0;
}
