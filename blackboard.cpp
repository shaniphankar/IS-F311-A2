#include "blackboard.h"

// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
// void display();
// void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
// double rotate_y=0;
// double rotate_x=0;

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void drawBoard(){

  //  Clear screen and Z-buffer
  // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // // Reset transformations
  // glLoadIdentity();

  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( 0, 1.0, 0.0, 0.0 );
  glRotatef( 0, 0.0, 1.0, 0.0 );

  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included

  //colored side - FRONT
  glBegin(GL_POLYGON);
  glColor3f(   0.3,  0.0, 0.0 );
  glVertex3f(  0.8, -0.5, -0.05 );
  glVertex3f(  0.8,  0.5, -0.05 );
  glVertex3f( -0.8,  0.5, -0.05 );
  glVertex3f( -0.8, -0.5, -0.05 );
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.4, 0.0 );
  glVertex3f(  0.7, -0.4, -0.06 );
  glVertex3f(  0.7,  0.4, -0.06 );
  glVertex3f( -0.7,  0.4, -0.06 );
  glVertex3f( -0.7, -0.4, -0.06 );
  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   0.3,  0.0, 0.0 );
  glVertex3f(  0.8, -0.5, 0.05 );
  glVertex3f(  0.8,  0.5, 0.05 );
  glVertex3f( -0.8,  0.5, 0.05 );
  glVertex3f( -0.8, -0.5, 0.05 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(   0.3,  0.0, 0.0 );
  glVertex3f( 0.8, -0.5, -0.05 );
  glVertex3f( 0.8,  0.5, -0.05 );
  glVertex3f( 0.8,  0.5,  0.05 );
  glVertex3f( 0.8, -0.5,  0.05 );
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.3,  0.0, 0.0 );
  glVertex3f( -0.8, -0.5,  0.05 );
  glVertex3f( -0.8,  0.5,  0.05 );
  glVertex3f( -0.8,  0.5, -0.05 );
  glVertex3f( -0.8, -0.5, -0.05 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.3,  0.0, 0.0 );
  glVertex3f(  0.8,  0.5,  0.05 );
  glVertex3f(  0.8,  0.5, -0.05 );
  glVertex3f( -0.8,  0.5, -0.05 );
  glVertex3f( -0.8,  0.5,  0.05 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.3,  0.0, 0.0 );
  glVertex3f(  0.8, -0.5, -0.05 );
  glVertex3f(  0.8, -0.5,  0.05 );
  glVertex3f( -0.8, -0.5,  0.05 );
  glVertex3f( -0.8, -0.5, -0.05 );
  glEnd();

  // glFlush();
  // glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
// void specialKeys( int key, int x, int y ) {

//   //  Right arrow - increase rotation by 5 degree
//   if (key == GLUT_KEY_RIGHT)
//     rotate_y += 5;

//   //  Left arrow - decrease rotation by 5 degree
//   else if (key == GLUT_KEY_LEFT)
//     rotate_y -= 5;

//   else if (key == GLUT_KEY_UP)
//     rotate_x += 5;

//   else if (key == GLUT_KEY_DOWN)
//     rotate_x -= 5;

//   //  Request display update
//   glutPostRedisplay();

// }

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
// int main(int argc, char* argv[]){

//   //  Initialize GLUT and process user parameters
//   glutInit(&argc,argv);

//   //  Request double buffered true color window with Z-buffer
//   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

//   // Create window
//   glutCreateWindow("Awesome Cube");

//   //  Enable Z-buffer depth test
//   glEnable(GL_DEPTH_TEST);

//   // Callback functions
//   glutDisplayFunc(display);
//   glutSpecialFunc(specialKeys);

//   //  Pass control to GLUT for events
//   glutMainLoop();

//   //  Return to OS
//   return 0;

// }
