#ifndef VECTOR_H
#define VECTOR_H

#include "globalgl.h"
#include "Utils.h"
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>

// ******** Point Class ********
class point {
	friend point getMidpoint(const point&, const point&);
	friend double getDistance(const point&, const point&);
	friend point getWindowCenter();
public:
	point();
	point(double x_pos, double y_pos, double z_pos=0.0);
	void draw();
	void print();
	void operator=(const point&);
	GLdouble x;
	GLdouble y;
	GLdouble z;
};

// ******** Vector Class ********

class Vector {
	friend Vector operator+(const Vector&, const Vector&);
	friend Vector operator-(const Vector&, const Vector&);
	friend point operator+(const point&, const Vector&);
	friend Vector operator*(const GLdouble&, const Vector&);
	friend Vector operator-(const point&, const point&);
public:
	Vector();
	Vector(double x_comp, double y_comp, double z_comp=0.0);
	void operator=(const Vector&);
	GLdouble dot(const Vector&);
	Vector cross(const Vector&);
	Vector perp(); // only 2D
	GLdouble magnitude();
	Vector norm();
	void print();
	GLdouble x;
	GLdouble y;
	GLdouble z;
};
#endif