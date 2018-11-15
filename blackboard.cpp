#include "blackboard.h"

/*! This function draws the Black(Green,Really)board of the class. To improve the school's international ranking, the chalkboard has been made out of slate deposits from South America.
*/
void drawBoard(){

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

}