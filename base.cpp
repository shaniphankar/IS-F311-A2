#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <GL/glut.h>
#include "glRoutines.h"
using namespace std;

void myDisplay(void)
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	plot(100,100,10);
	glutSwapBuffers();
	
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000,1000);
	glutInitWindowPosition(100,150);
	glutCreateWindow ("Classroom");
	glutDisplayFunc(myDisplay);	
	glutMainLoop();
}
