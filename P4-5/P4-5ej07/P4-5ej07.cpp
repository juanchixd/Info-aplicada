//============================================================================
// Name        : P4-5ej07.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Magica.h"
using namespace std;
using std::cout;
int main(void){
	int matriz[4][4]={{1,14,14,4},{11,7,6,9},{8,10,10,5},{13,2,3,15}};
	int **p;
	p=new int*[4];
	for(int i=0;i<4;i++)
		p[i]=new int[4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			p[i][j]=matriz[i][j];
	Magica c(p, 4,4);

	if(c.esCuadrada()){
		cout<<"La matriz es cuadrada\n";
		if(c.esMagica())
			cout<<"La suma de cualquier fila, columna o diagonal es:"<<c.sumadiagpcipal()<<"\n";
		else
			cout<<"La matriz no es magica\n";
	}
	else cout<<"La matriz no es cuadrada\n";
	return 0;
}
