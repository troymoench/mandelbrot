#include "Classes.h"
#include "Vector.h"
#include <math.h>
#include <float.h>
#include <complex>

// Mandelbrot Set

using namespace std;
const double SH = 540.0;
const double SW = 810.0;
complex<double> topLeft(-2, 1); // top left corner of complex plane
double planeWidth = 3; // width of the complex plane
int maxIteration = 50;
bool drawn = false;
bool animate = false;

typedef struct {
	double red;
	double green;
	double blue;
} COLOR;

vector<COLOR> colors;

void setColorPalette(vector<COLOR> &clrs, int max) {
	COLOR clr;
	double inc = 1.0 / max;
	clrs.clear();

	clr.red = 0;
	clr.green = 0;
	clr.blue = 1;
	clrs.push_back(clr);

	for (int i = 0; i < max; i++) {
		clr.red += inc;
		clr.green += inc;
		clrs.push_back(clr);
	}
}

complex<double> pixelToComplex(const double &i,const double &j, const complex<double> &p, const double &width, const int &cols) {
	// map the pixels of the display to the complex plane
	return complex<double>(p.real() + (i / cols)*width, p.imag() - (j/ cols)*width);
}

void numIterations(const complex<double> &c, const int &max, int &iterations) {
	iterations = 0;
	complex<double> z(0,0);
	while ((z.real()*z.real() + z.imag()*z.imag() < 4) && iterations < max) {
		z = z*z + c;
		iterations++;
	}
	// return iterations;
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);  // bg color bright white
	glPointSize(1.0);
	glLineWidth(1.0);
	setWorldWin(0.0, SW, 0.0, SH);
	setViewPort(0, SW, 0, SH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void) {

	if (animate) { // use idle function?
		if (maxIteration < 50) {
			maxIteration++;
			drawn = !drawn;
		}
		else animate = false;
	}

	if (!drawn) { 
		glClear(GL_COLOR_BUFFER_BIT);
		setColorPalette(colors, maxIteration);
	int rows = SH;
	int cols = SW;
	complex<double> c;
	point p;
	int iteration;

	
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < cols; i++) {
			p.x = i;
			p.y = j;

			c = pixelToComplex(i, j, topLeft, planeWidth, cols);

			numIterations(c, maxIteration, iteration);

			if (iteration == maxIteration) { // point lies in the set
				glColor3f(0.0f, 0.0f, 0.0f);
			}
			else { // point does not lie in set
				// glColor3f(1.0f, 1.0f, 1.0f);
				glColor3f(colors[iteration].red, colors[iteration].green, colors[iteration].blue);
			}
			p.draw();
		}
	}
		drawn = true;
	}
	if (animate) glutPostRedisplay(); // use idle function?
	glFlush();

}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
	switch (theKey) {
	case '+':
		maxIteration += 5;
		drawn = !drawn;
		break;
	case '-':
		if (maxIteration > 0) {
			maxIteration -= 5;
			drawn = !drawn;
		}
		break;
	case 'a': // start animation of max iterations
		animate = true;
		maxIteration = 2;
		break;
	case 'r': // reset the image
		topLeft = complex<double> (-2,1);
		planeWidth = 3;
		maxIteration = 50;
		drawn = !drawn;
		break;
	case 27: exit(-1);	      //terminate the program
	default:
		break;	      // do nothing
	}
	glutPostRedisplay();
}


int main(int argc, char **argv) {
	cout << "Press '+' or '-' to increase or decrease max iterations" << endl;
	cout << "Press 'a' to begin animation" << endl;
	cout << "Press 'r' to reset the image" << endl;
	cout << "Press 'esc' to quit" << endl;



	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // double buffer?
	glutInitWindowSize(SW, SH);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Mandelbrot Set");
	myInit();
	glutDisplayFunc(myDisplay);		// register the redraw function
	glutKeyboardFunc(myKeyboard);   // register the keyboard action function
	glutMainLoop();	                // go into a perpetual loop
}
