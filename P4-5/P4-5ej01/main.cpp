/*
 * main.cpp
 *
 *  Created on: 26 may. 2022
 *      Author: juan
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include "Point3D.h"

using std::cout;
using std::endl;
using std::stringstream;

Point3D::Point3D(int low, int high) {
	x = low + int ((rand()/2000)) * (high-low);
	y = low + int ((rand()/2000)) * (high-low);
	z = low + int ((rand()/2000)) * (high-low);
}

int Point3D::getX() const { return x; }
int Point3D::getY() const { return y; }
int Point3D::getZ() const { return z; }
void Point3D::setX (int tx) { x = tx; }
void Point3D::setY (int ty) { y = ty; }
void Point3D::setZ (int tz) { z = tz; }

bool Point3D::equals(Point3D q) const{
	return(x == q.x && y == q.y && z == q.z);
}

bool Point3D::equals(int x1, int y1, int z1) const{
	return(x == x1 && y == y1 && z == z1);
}

void Point3D::shiftX(int tx){
	x += tx;
}

void Point3D::shiftY(int ty){
	y += ty;
}

void Point3D::shiftZ(int tz){
	z += tz;
}

void Point3D::translate(int tx, int ty, int tz){
	x += tx;
	y += ty;
	z += tz;
}

double Point3D::distanceOrigin() const{
	return sqrt(pow((double)x, 2)+ pow((double)y, 2) + pow((double)z, 2));
}

double Point3D::distanceToPoint(Point3D q) const {
	return sqrt(pow(double(x - q.x), 2) + pow(double(y - q.y), 2) + pow(double(z - q.z), 2));
}
int Point3D::scalarProduct(Point3D q) const {
	return x * q.x + y * q.y + z * q.z;
}

string Point3D::whichSpace() const {
	string message = "Este punto esta: ";
	if (equals(0, 0, 0)) // origen
		message = "El punto es el origen!";
	else {
		message += "en el ";
		if (x >= 0) // derecha
			message += "semiplano derecho, ";
		else
			message += "semiplano izquierdo, ";
		if (y >= 0) // arriba
			message += "superior, ";
		else
			message += "inferior, ";
		if (z >= 0) // delante
			message += "y delante.";
		else
			message += "y detrás.";

	}
	return message;
}
bool Point3D::inBox (int xbox, int ybox, int zbox, int width, int height, int depth) const {
	return (x >= xbox) && (x <= xbox + width) // rango de x
			&& (y <= ybox) && (y >= ybox - height) // rango de y
			&& (z <= zbox) && (z >= zbox - depth); // rango de z

}
bool Point3D::inSphere(Point3D center, int radius) const {
	return distanceToPoint(center) <= radius;
}
int main() {
	int a1 = 10, b1 = -5, c1 = 4; // para constructor
	int a2 = 9, b2 = 8, c2 = -6; // para actualizar coordenadas
	int shift1X = 3,shift1Y = -3,shift1Z = 7,shift2X = 6, shift2Y = 11,shift2Z = -13;
	int low = 5, high = 15; // para constructor
	int xBox = -12, yBox = 20, zBox = 8;// borde superior izquierdo y delante de una caja
	int width = 24, height = 40, depth = 35; // de la caja
	int xCenterSphere = 1, yCenterSphere = 2, zCenterSphere = 5;// centro de esfera
	int radius = 50; // radio de esfera
	// declaracion referencia a puntos 3D
	Point3D pt1, pt2(a1, b1, c1), pt3(low, high);
	// mostrar
	cout << "Punto 1 es: (" << pt1.getX() << ", " << pt1.getY() << ", " << pt1.getZ() << ")" <<	endl;
	cout << "Punto 2 es: (" << pt2.getX() << ", " << pt2.getY() << ", " << pt2.getZ() << ")" <<	endl;
	cout << "Punto 3 es: (" << pt3.getX() << ", " << pt3.getY() << ", " << pt3.getZ() << ")" <<	endl;
	// muestra coordenadas del punto 3
	printf("\n\nLas coordenadas del punto 3 son: %d, %d, %d", pt3.getX(), pt3.getY(), pt3.getZ());
	// cambia coordenadas de pt2
	pt2.setX(a2);
	pt2.setY(b2);
	pt2.setZ(c2);
	cout << endl << "Punto 2 ahora es: ( " << pt2.getX() << ", " << pt2.getY() << ", " << pt2.getZ() << ")" << endl;
	// mueve pt1 y chequea si es igual a pt2
	pt1.shiftX(shift1X);
	pt1.shiftY(shift1Y);
	pt1.shiftZ(shift1Z);
	cout << "Punto 1 ahora es: ( "<< pt1.getX() << ", " << pt1.getY() << ", " << pt1.getZ() << ")" << endl;
	cout << "Es pt1 igual a pt2? --> "<< pt1.equals(pt2) << endl;
	// mueve pt1 de nuevo y chequea si es igual a pt2
	pt1.translate(shift2X, shift2Y, shift2Z);
	Point3D pt4(pt1);
	cout << endl << "Punto 1 trasladado, ahora pt4 es: ( " << pt1.getX() << ", " << pt1.getY() <<", " << pt1.getZ() << ")" << endl;
	cout << "Es este nuevo punto transladado pt4 igual a pt2? --> " << pt4.equals(pt2.getX(),pt2.getY(), pt2.getZ()) << endl;
	// distancia de pt3 al origen
	cout << "Distancia de pt3 al origen es: " << pt3.distanceOrigin() << endl;
	// distancia pt1 - pt3
	cout << "Distancia entre pt1 y pt3 es: " << pt1.distanceToPoint(pt3) << endl;
	// producto escalar de vectores pt1 , pt2
	cout << "Producto escalar de pt1, pt2 es: " << pt1.scalarProduct(pt2) << endl;
	// en qué espacios están pt1, pt2, pt3?
	cout << "Para pt1 --> " << pt1.whichSpace() << endl;
	cout << "Para pt2 --> " << pt2.whichSpace() << endl;
	cout << "Para pt3 --> " << pt3.whichSpace() << endl;
	// está pt2 en una caja?
	cout << "Está pt2 en la caja dada? --> " << pt2.inBox(xBox, yBox, zBox, width, height, depth)<< endl;
	// está pt1 en la esfera?
	Point3D center(xCenterSphere, yCenterSphere, zCenterSphere);
	cout << "Está pt1 dentro de la esfera? ---> " << pt1.inSphere(center, radius) << endl;
	// Imprimir todos los puntos
	cout << endl << "Punto 1 es ( " << pt1.getX() << ", " << pt1.getY() << ", " << pt1.getZ() << ")" << endl;
	cout << endl << "Punto 2 es ( " << pt2.getX() << ", " << pt2.getY() << ", " << pt2.getZ() << ")" << endl;
	cout << endl << "Punto 3 es ( " << pt3.getX() << ", " << pt3.getY() << ", " << pt3.getZ() << ")" << endl;
}
