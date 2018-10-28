#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include "glRoutines.h"
using namespace std;

void plot(int x,int y,int z)
{
	glBegin(GL_POINTS);
	glVertex3i(x,y,z);
	glEnd();
}

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500.0, 500.0, -500.0, 500.0,-50.0,50.0);
}

