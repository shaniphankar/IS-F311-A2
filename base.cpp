#include <iostream>
#include <GL/glut.h>
using namespace std;
double angle=-45.0f;
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

void changeSize(int w, int h) 
{
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);
}

void myDisplay(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle,0.0f,1.0f,0.0f);
	gluLookAt(0.0f,0.0f,5.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glRotatef(-1*angle,0.0f,1.0f,0.0f);
	angle+=1.0f;
	if(angle>=45.0f)
	{
		angle-=90.0f;
	}
	drawEmptyClass();
    glutSwapBuffers();
}
void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}
void update(int data)
{
	glutTimerFunc(30,update,0);
	glutPostRedisplay();
}
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(changeSize);
	glutTimerFunc(30,update,0);
	myinit();
	glutMainLoop();
	return 1;
}