#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
float _angle = -70.0f;
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Reset transformations
  glLoadIdentity();

  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included

  glRotatef(-45, 1.0f, 0.0f, 0.0f);
  glRotatef(45, 0.0f, 0.0f, 1.0f);


  // //Multi-colored side - FRONT
  // glBegin(GL_POLYGON);
  //
  // glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
  // glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
  // glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
  // glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple
  //
  // glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.1 );
  glVertex3f(  0.5,  0.5, 0.1 );
  glVertex3f( -0.5,  0.5, 0.1 );
  glVertex3f( -0.5, -0.5, 0.1 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.5, -0.5, -0.1 );
  glVertex3f( 0.5,  0.5, -0.1 );
  glVertex3f( 0.5,  0.5,  0.1 );
  glVertex3f( 0.5, -0.5,  0.1 );
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.1 );
  glVertex3f( -0.5,  0.5,  0.1 );
  glVertex3f( -0.5,  0.5, -0.1 );
  glVertex3f( -0.5, -0.5, -0.1 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.1 );
  glVertex3f(  0.5,  0.5, -0.1 );
  glVertex3f( -0.5,  0.5, -0.1 );
  glVertex3f( -0.5,  0.5,  0.1 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.1 );
  glVertex3f(  0.5, -0.5,  0.1 );
  glVertex3f( -0.5, -0.5,  0.1 );
  glVertex3f( -0.5, -0.5, -0.1 );
  glEnd();

  glRotatef(_angle,0.0f, 0.0f, 1.0f);

  // hands of the Clock
  glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);//BACK TOP

  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void update(int value) {
    _angle += 1.5f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Request display update
  glutPostRedisplay();

}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);

  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // Create window
  glutCreateWindow("Clock");
  glLineWidth(50);
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);

  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  update(0);
  // idle function
  // glutIdleFunc(display);

  //  Pass control to GLUT for events
  glutMainLoop();

  //  Return to OS
  return 0;

}
