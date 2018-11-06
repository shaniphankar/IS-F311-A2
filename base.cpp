#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <GL/glut.h>
#include "glRoutines.h"
using namespace std;
float angle=0.0f;
void drawEmptyClass()
{
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.35f,0.05f);//TOP
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(1.0f,1.0f,0.0f);
	glColor3f(0.5f,0.35f,0.05f);//BOTTOM
	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	glColor3f(0.5f,0.35f,0.05f);//BACK
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glColor3f(0.5f,0.35f,0.05f);//LEFT
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glColor3f(0.5f,0.35f,0.05f);//RIGHT
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0f,0.0f,0.0f);//BACK TOP
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BACK BOTTOM
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BACK LEFT
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BACK RIGHT
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//TOP LEFT
	glVertex3f(-1.0f,1.0f,0.0f); 
	glVertex3f(-1.0f,1.0f,-1.0f);
	glColor3f(0.0f,0.0f,0.0f);//BOTTOM LEFT
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//TOP RIGHT
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//BOTTOM RIGHT
	glVertex3f(1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glEnd();

      
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	// gluLookAt(0.0f,0.0f,0.0f,10.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glTranslatef(0.0f,0.0f,-2.5f);
	glRotatef(angle,0.0f,1.0f,0.0f);
	drawEmptyClass();
	glRotatef(-1*angle,0.0f,1.0f,0.0f);
	glTranslatef(0.0f,0.0f,2.5f);
	angle+=1.0f;
	if(angle>=360.0f)
	{
		angle-=360.0f;
	}
	// drawBoard();
	// drawChairs();
	// glutPostRedisplay();
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	if(height==0)
		height=1;
	GLfloat aspect=(GLfloat)width/(GLfloat)height;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,aspect,0.1f,100.0f);
}
void update(int data)
{
	glutTimerFunc(60,update,0);
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000,1000);
	glutInitWindowPosition(100,150);
	glutCreateWindow ("Classroom");
	glutDisplayFunc(myDisplay);	
	glutReshapeFunc(reshape);
	glutTimerFunc(60,update,0);
	// glutIdleFunc(myDisplay);
	myInit ();
	glutMainLoop();
}
