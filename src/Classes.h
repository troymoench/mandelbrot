#ifndef CLASSES_H
#define CLASSES_H

#include "globalgl.h"
#include "Utils.h"
#include "Vector.h"
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>


// ******* PolyLine Class *******
class PolyLine {
	friend void drawTween(PolyLine a, PolyLine b, double &t, const double &increment);
	friend PolyLine tween(PolyLine a, PolyLine b, double t, const double &increment);
public:
	PolyLine();
	PolyLine(std::vector<point>);
	PolyLine(point[], int);
	unsigned int size(); // number of points
	void draw(int style=GL_LINE_STRIP);
	void insert(point); // insert point at end of points
	void clear();
	void print(); // prints out the points
private:
	std::vector<point> points;
};


// ***** Polygon Class ******
class polygon {
public:
	polygon();
	polygon(int, double, point, double init_angle=0.0); // sides, radius, center, initial angle in radians
	// polygon(const std::vector<point>&); // not necessarily a regular polygon
	void draw(int, bool semi=false);
	void rosette();
	std::vector<point> getPoints();
private:
	int sides;
	double radius;
	point center;
	double angle;
	// std::vector<point> points;
	// May refactor this class
};
#endif