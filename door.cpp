#include "door.h"


/*! This function draws the door that forms the entrance to our classroom. The door is made out of Warm Redwood straight out of the forests of California. It is as if the classroom is an entrance to Silicon Valley itself.*/
void drawDoor(){

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
  glColor3f(   0.5,  0.0, 0.0 );
  glVertex3f(  0.65, -0.4, -0.06 );
  glVertex3f(  0.65,  0.4, -0.06 );
  glVertex3f( 0.05,  0.4, -0.06 );
  glVertex3f( 0.05, -0.4, -0.06 );
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(   0.5,  0.0, 0.0 );
  glVertex3f(  -0.05, -0.4, -0.06 );
  glVertex3f(  -0.05,  0.4, -0.06 );
  glVertex3f( -0.65,  0.4, -0.06 );
  glVertex3f( -0.65, -0.4, -0.06 );
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

}

