#ifndef DESUTILS_H
#define DESUTILS_H

const double PI = 3.141592654;

extern void setWorldWin(GLdouble left, GLdouble right,
	GLdouble bottom, GLdouble top);

extern void setViewPort(GLint left, GLint right, GLint bottom, GLint top);

extern GLdouble getWorldWinAspect();

#endif