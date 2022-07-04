/*
 * Point3D.h
 *
 *  Created on: 26 may. 2022
 *      Author: juan
 */

using std::string;
#ifndef POINT3D_H_
#define POINT3D_H_

class Point3D {
	int x;
	int y;
	int z;
public:
	Point3D() : x(0), y(0), z(0){}
	Point3D(int x1, int y1, int z1): x(x1), y(y1), z(z1){}
	Point3D(int low, int high);
	bool equals(Point3D q) const;
	bool equals(int x1, int y1, int z1) const;
	void shiftX(int tx); //desplaza coordenada x en tx
	void shiftY(int ty); //idem
	void shiftZ(int tz); //idem
	void translate(int tx, int ty, int tz); //desplaza el punto
	double distanceOrigin()const; //retornar la distancia al origen
	double distanceToPoint(Point3D q) const; //retorna la distancia al punto q
	int scalarProduct(Point3D q) const; //producto escalar del vector del origen al punto q con el vector formado por el punto actual
	string whichSpace() const;
	bool inBox (int xbox, int ybox, int zbox,int width, int height, int depth) const;
	bool inSphere(Point3D center, int radius) const;
	int getX() const;
	int getY() const;
	int getZ() const;
	void setX (int tx);
	void setY (int ty);
	void setZ (int tz);
};


#endif /* POINT3D_H_ */
