#include "Classes.h"


// ******* Polyline Class *******

PolyLine::PolyLine() {}

PolyLine::PolyLine(std::vector<point> p) {
	points = p;
}

PolyLine::PolyLine(point ar[], int size) {
	for (int i = 0; i < size; i++) {
		points.push_back(ar[i]);
	}
}

unsigned int PolyLine::size() {
	return points.size();
}

void PolyLine::draw(int style) {
	glBegin(style);
	for (unsigned int i = 0; i < points.size(); i++) {
		glVertex2d(points[i].x, points[i].y);
	}
	glEnd();
}

void PolyLine::clear() {
	points.clear();
}

void PolyLine::insert(point p) {
	points.push_back(p);
}

void PolyLine::print() {
	for (unsigned int i = 0; i < points.size(); i++) {
		points[i].print();
	}
}


// ***** Polygon Class ******

polygon::polygon() {
	sides = 0;
	radius = 0.0;
	center = *new point();
	angle = 0.0;
}

polygon::polygon(int num_sides, double rad, point cent, double init_angle) {
	if (num_sides <= 0) return;
	sides = num_sides;
	radius = rad;
	center = cent;
	angle = init_angle;
}


/*
polygon::polygon(const std::vector<point> &pnts) {
	points = pnts;
}
*/
void polygon::draw(int style, bool semi) {
	const double ANGLE_INC = 2 * PI / sides;
	double theta = angle;
	if (semi) sides = sides / 2 + 1;
	glBegin(style);
	for (int vert = 0; vert < sides; vert++) {
		glVertex2d(center.x + radius*cos(theta), center.y + radius*sin(theta));
		theta += ANGLE_INC;
	}
	glEnd();
}

std::vector<point> polygon::getPoints() {
	std::vector<point> points;
	point p;
	const double ANGLE_INC = 2 * PI / sides;
	double theta = angle;
	for (int vert = 0; vert < sides; vert++) {
		p.x = center.x + radius*cos(theta);
		p.y = center.y + radius*sin(theta);
		points.push_back(p);
		theta += ANGLE_INC;
	}
	return points;
}

void polygon::rosette() {
	std::vector<point> points;
	points = getPoints();
	glBegin(GL_LINES);
	for (int i = 0; i < sides; i++) {
		for (int j = 0; j < sides; j++) {
			glVertex2d(points[i].x, points[i].y);
			glVertex2d(points[j].x, points[j].y);
		}
	}
	glEnd();
}