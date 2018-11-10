#include <iostream>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "chair.h"
#include "table.h"
#include "clock.h"
using namespace std;
//! The angle specifies the magnitude to which we are looking up or down. Calculated w.r.t x-axis 
double pitch=0.0f;
//! The angle specifies the magnitude to which we are looking left or right. Calculated w.r.t y-axis 
double yaw=-90.0f;
//! This angle defines how much we can see of the scene.
double fov=45.0f;
//! 3D vector that contains the position of camera i.e the PRP
glm::dvec3 cameraPos=glm::dvec3(0.0f,0.0f,10.0f);
//! 3D vector that contains the direction of PRP w.r.t VRP
glm::dvec3 directionSight=glm::dvec3(0.0f,0.0f,-1.0f);
//! 3D vector that contains the direction that defines what direction is UP
glm::dvec3 upVec=glm::dvec3(0.0f,1.0f,0.0f);
//*! This function draws an empty Brown Cube which was the original prototype for our classroom*/
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
	glColor3f(0.5f,0.35f,0.05f);//FRONT
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
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
	glColor3f(0.0f,0.0f,0.0f);//FRONT TOP
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT BOTTOM
	glVertex3f(-1.0f,-1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT LEFT
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);//FRONT RIGHT
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
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
/*! This function is the reshape function that is called everytime an OpenGL window is generated
\param w The width of the window.
\param h The height of the window.
*/
void changeSize(int w, int h) 
{
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(fov,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);
}
/*! This function is the display function that is registered with our OpenGL instance.This routine is redrawn everytime the OpenGL window is refreshed
*/
void myDisplay(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(cameraPos[0],cameraPos[1],cameraPos[2],cameraPos[0]+directionSight[0],cameraPos[1]+directionSight[1],cameraPos[2]+directionSight[2],upVec[0],upVec[1],upVec[2]);
	// drawEmptyClass();
	drawClock();
    glutSwapBuffers();
}
/*! This function provides the initial settings for our OpenGL window
*/
void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

/*! This function details the time intervals at which to redraw the scene in OpenGL
*/
void update(int data)
{
	glutTimerFunc(45,update,0);
	glutPostRedisplay();
}
/*! This function details how to process all the keys for which ASCII values exist
\param key The key that has been pressed.
\param x Integer parameter
\param y Integer parameter
*/
void processNormalKeys(unsigned char key, int x,int y)
{
	double sensitivityX=1.5f;
	double sensitivityY=1.5f;
	// double sensitivityFOV=1.0f;
	if(key==27)
	{
		exit(0);
	}
	if(key=='W'||key=='w')
	{
		pitch+=sensitivityY;
	}
	if(key=='A'||key=='a')
	{
		yaw-=sensitivityX;
	}
	if(key=='S'||key=='s')
	{
		pitch-=sensitivityY;
	}
	if(key=='D'||key=='d')
	{
		yaw+=sensitivityX;
	}
	// if(key=='+')
	// {
	// 	fov+=sensitivityFOV;
	// }
	// if(key=='-')
	// {
	// 	fov-=sensitivityFOV;
	// }
	// if(fov<=1.0f)
	// 	fov=1.0f;
	// if(fov>=90.0f)
	// 	fov=90.0f;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    if(yaw > 0.0f)
        yaw = 0.0f;
    if(yaw < -179.0f)
        yaw = -179.0f;
	glm::dvec3 tempDir;
	tempDir[0]=cos(glm::radians(yaw))*cos(glm::radians(pitch));
	tempDir[1]=sin(glm::radians(pitch));
	tempDir[2]=sin(glm::radians(yaw))*cos(glm::radians(pitch));
	directionSight=glm::normalize(tempDir);
}

/*! This function details how to process all the keys for which ASCII values do not exist
\param key The key that has been pressed.
\param x Integer parameter
\param y Integer parameter
*/
void processSpecialKeys(int key, int x,int y)
{
	double fraction=0.1f;
	if(key==GLUT_KEY_LEFT)
	{
		cameraPos-=fraction*glm::normalize(glm::cross(directionSight,upVec));
	}
	if(key==GLUT_KEY_RIGHT)
	{
		cameraPos+=fraction*glm::normalize(glm::cross(directionSight,upVec));	
	}
	if(key==GLUT_KEY_UP)
	{
		cameraPos+=fraction*directionSight;
	}
	if(key==GLUT_KEY_DOWN)
	{
		cameraPos-=fraction*directionSight;
	}
}
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Classroom");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutTimerFunc(45,update,0);
	myinit();
	glutMainLoop();
	return 1;
}