#include "fan.h"
//! The angle specifies the amount by which the fan has been rotated 
float _angle2 = -70.0f;
/*! This function draws our multicolored fan. The fan was made using a composite alloy of multiple colored metals which gives it it's unique look.*/
void drawFan(){

 //Multi-colored side - FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0.0 );
  glVertex3f(  0.03, -0.03, -0.4 );      // P1 is red
  glVertex3f(  0.03,  0.03, -0.4 );      // P2 is green
  glVertex3f( -0.03,  0.03, -0.4 );      // P3 is blue
  glVertex3f( -0.03, -0.03, -0.4 );      // P4 is purple

  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.03, -0.03, 0.4 );
  glVertex3f(  0.03,  0.03, 0.4 );
  glVertex3f( -0.03,  0.03, 0.4 );
  glVertex3f( -0.03, -0.03, 0.4 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.03, -0.03, -0.4 );
  glVertex3f( 0.03,  0.03, -0.4 );
  glVertex3f( 0.03,  0.03,  0.4 );
  glVertex3f( 0.03, -0.03,  0.4 );
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.03, -0.03,  0.4 );
  glVertex3f( -0.03,  0.03,  0.4 );
  glVertex3f( -0.03,  0.03, -0.4 );
  glVertex3f( -0.03, -0.03, -0.4 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.03,  0.03,  0.4 );
  glVertex3f(  0.03,  0.03, -0.4 );
  glVertex3f( -0.03,  0.03, -0.4 );
  glVertex3f( -0.03,  0.03,  0.4 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.03, -0.03, -0.4 );
  glVertex3f(  0.03, -0.03,  0.4 );
  glVertex3f( -0.03, -0.03,  0.4 );
  glVertex3f( -0.03, -0.03, -0.4 );
  glEnd();

  glTranslatef( 0.0, 0.0, -0.4 );
  glRotatef(_angle2,0.0f, 0.0f, 1.0f);

  //Multi-colored side - FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0.0 );
  glVertex3f(  0.12, -0.12, -0.05 );      // P1 is red
  glVertex3f(  0.12,  0.12, -0.05 );      // P2 is green
  glVertex3f( -0.12,  0.12, -0.05 );      // P3 is blue
  glVertex3f( -0.12, -0.12, -0.05 );      // P4 is purple
  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.12, -0.12, 0.05 );
  glVertex3f(  0.12,  0.12, 0.05 );
  glVertex3f( -0.12,  0.12, 0.05 );
  glVertex3f( -0.12, -0.12, 0.05 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.12, -0.12, -0.05 );
  glVertex3f( 0.12,  0.12, -0.05 );
  glVertex3f( 0.12,  0.12,  0.05 );
  glVertex3f( 0.12, -0.12,  0.05 );
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.12, -0.12,  0.05 );
  glVertex3f( -0.12,  0.12,  0.05 );
  glVertex3f( -0.12,  0.12, -0.05 );
  glVertex3f( -0.12, -0.12, -0.05 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.12,  0.12,  0.05 );
  glVertex3f(  0.12,  0.12, -0.05 );
  glVertex3f( -0.12,  0.12, -0.05 );
  glVertex3f( -0.12,  0.12,  0.05 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.12, -0.12, -0.05 );
  glVertex3f(  0.12, -0.12,  0.05 );
  glVertex3f( -0.12, -0.12,  0.05 );
  glVertex3f( -0.12, -0.12, -0.05 );
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f( 1, 0, 0 ); // red
  glVertex3f( -0.15, 0.9, 0 );
  glVertex3f( 0.15, 0.9, 0 );
  glVertex3f( 0, 0 , 0);
  glEnd();

  glRotatef( 120, 0.0, 0.0, 1.0 );
  glBegin(GL_TRIANGLES);
  glColor3f( 1, 0, 0 ); // red
  glVertex3f( -0.15, 0.9, 0 );
  glVertex3f( 0.15, 0.9, 0 );
  glVertex3f( 0, 0 , 0);
  glEnd();

  glRotatef( 120, 0.0, 0.0, 1.0 );
  glBegin(GL_TRIANGLES);
  glColor3f( 1, 0, 0 ); // red
  glVertex3f( -0.15, 0.9, 0 );
  glVertex3f( 0.15, 0.9, 0 );
  glVertex3f( 0, 0 , 0);
  glEnd();
  _angle2 += 3.0f;
  if (_angle2 > 360) {
      _angle2 -= 360;
  }

}