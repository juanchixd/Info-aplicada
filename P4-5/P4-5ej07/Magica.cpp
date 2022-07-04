/*
 * Magica.cpp
 *
 *  Created on: 27 may. 2022
 *      Author: juan
 */

#include "Magica.h"

Magica::Magica(int **m, int f, int c){
	filas=f;
	columnas=c;
	//reservo espacio para el vector que apunta a las filas
	matriz=new int*[f];
	//reservo memoria para las columnas de cada fila
	for(int i=0;i<c;i++)
		matriz[i]=new int[c];
	//llena con datos
	for(int i=0;i<filas;i++)
		for(int j=0;j<columnas;j++)
			matriz[i][j]=m[i][j];
}
bool Magica::esCuadrada()const{
	if(filas==columnas)return true;
	else return false;
}
int Magica::sumafilai(int i)const{
	int suma=0;
	for(int j=0;j<columnas;j++)
		suma+=matriz[i][j];
	return suma;
}
int Magica::sumacolumnai(int i)const{
	int suma=0;
	for(int j=0;j<filas;j++)
		suma+=matriz[j][i];
	return suma;
}
int Magica::sumadiagpcipal()const{
	int suma=0;
	for(int i=0;i<filas;i++)
		suma+=matriz[i][i];
	return suma;
}
int Magica::sumadiagsec()const{
	int suma=0;
	for(int i=0;i<filas;i++)
		suma+=matriz[0][filas-1-i];
	return suma;
}
bool Magica::esMagica()const{
	int suma=0;
	for(int i=0;i<columnas;i++)
		suma+=matriz[0][i];
	int i;
	for(i=1;i<filas;i++)
		if(suma!=sumafilai(i))return false;
	for(i=0;i<columnas;i++)
		if(suma!=sumacolumnai(i))return false;
	if(suma!=sumadiagpcipal())return false;
	if(suma!=sumadiagsec())return false;
	return true;
}
Magica::~Magica(void){
	//libera la memoria de la matriz
	for(int i=0;i<filas;i++)
		delete[]matriz[i];//libera columnas
	delete[]matriz;//libera filas
}
