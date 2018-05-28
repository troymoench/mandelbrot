#include "Vector.h"

// ******** Point Class ********
point::point() {
	x = -1;
	y = -1;
	z = 0;
}

point::point(double x_pos, double y_pos, double z_pos) {
	x = x_pos;
	y = y_pos;
	z = z_pos;
}

void point::draw() {
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

void point::print() {
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

void point::operator=(const point& p) {
	x = p.x;
	y = p.y;
	z = p.z;
}

point getMidpoint(const point& a, const point& b) {
	return point((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
}

double getDistance(const point& a, const point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

point getWindowCenter() {
	GLdouble width = glutGet(GLUT_WINDOW_WIDTH);
	GLdouble height = glutGet(GLUT_WINDOW_HEIGHT);
	return point(width / 2.0, height / 2.0);
}


// ******** Vector Class ********

Vector::Vector() {
	x = -1;
	y = -1;
	z = -1;
}

Vector::Vector(double x_comp, double y_comp, double z_comp) {
	x = x_comp;
	y = y_comp;
	z = z_comp;
}

void Vector::operator=(const Vector& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector operator+(const Vector& a, const Vector& b) {
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

point operator+(const point& p, const Vector& v) {
	return point(v.x + p.x, v.y + p.y, v.z + p.z);
}

Vector operator-(const Vector& a, const Vector& b) {
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const GLdouble& k, const Vector& v) {
	return Vector(k*v.x, k*v.y, k*v.z);
}

Vector operator-(const point &a, const point &b) {
	return Vector(a.x - b.x, a.y - b.y);
}

GLdouble Vector::dot(const Vector& v) {
	return x*v.x + y*v.y + z*v.z;
}

Vector Vector::cross(const Vector& v) {
	return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

Vector Vector::perp() {
	return Vector(-y, x);
}

GLdouble Vector::magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::norm() {
	double mag = magnitude();
	return Vector(1/mag*x, 1/mag*y, 1/mag*z);
}

void Vector::print() {
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}