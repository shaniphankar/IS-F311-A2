#include <iostream>
#include <GL/glut.h>
#include <glm/vec3.hpp>
using namespace std;
double angle=0.0f;
glm::vec3 cameraPos=glm::vec3(0.0f,0.0f,4.0f);
glm::vec3 directionSight=glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 upVec=glm::vec3(0.0f,1.0f,0.0f);
int flag=1;
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
	gluLookAt(cameraPos[0],cameraPos[1],cameraPos[2],0.0f,0.0f,0.0f,upVec[0],upVec[1],upVec[2]);
	// glRotatef(-1*angle,0.0f,1.0f,0.0f);
	// if(flag==1)
	// {
	// 	angle+=1.0f;	
	// }
	// else if(flag==-1)
	// {
	// 	angle-=1.0f;
	// }	
	// if(angle>=45.0f)
	// {
	// 	flag=-1;
	// }
	// if(angle<=-45.0f)
	// {
	// 	flag=1;
	// }
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
	glutTimerFunc(45,update,0);
	glutPostRedisplay();
}
void processNormalKeys(unsigned char key, int x,int y)
{
	if(key==27)
	{
		exit(0);
	}
}

void processSpecialKeys(int key, int x,int y)
{
	double fraction=0.1f;
	// if(key==GLUT_KEY_LEFT)
	// {

	// }
	// if(key==GLUT_KEY_RIGHT)
	// {
		
	// }
	if(key==GLUT_KEY_UP)
	{
		cameraPos[0]+=directionSight[0]*fraction;
		cameraPos[1]+=directionSight[1]*fraction;
		cameraPos[2]+=directionSight[2]*fraction;
	}
	if(key==GLUT_KEY_DOWN)
	{
		cameraPos[0]-=directionSight[0]*fraction;
		cameraPos[1]-=directionSight[1]*fraction;
		cameraPos[2]-=directionSight[2]*fraction;	
	}
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
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutTimerFunc(45,update,0);
	myinit();
	glutMainLoop();
	return 1;
}