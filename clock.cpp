#include "clock.h"

//! The angle specifies the position of the seconds hand 
float angle1 = 0.0f;
//! The angle specifies the position of the minutes hand 
float angle2 = 60.0f;
//! The angle specifies the position of the hours hand  
float angle3 = 300.0f;


/*! This function draws the wall clock adorning the classroom. Frequent experimentation by the physics department has thrown it's space-time equations out of whack. Due to this, it moves at a much faster pace than the corporeal world.*/
void drawClock(){

  glRotatef( 180, 0.0, 1.0, 0.0 );

  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f( -0.5, -0.5, 0.1 );
  glVertex3f( -0.5,  0.5, 0.1 );
  glVertex3f(  0.5,  0.5, 0.1 );
  glVertex3f(  0.5, -0.5, 0.1 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.5, -0.5,  0.1 );
  glVertex3f( 0.5,  0.5,  0.1 );
  glVertex3f( 0.5,  0.5, -0.1 );
  glVertex3f( 0.5, -0.5, -0.1 );
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5, -0.1 );
  glVertex3f( -0.5,  0.5, -0.1 );
  glVertex3f( -0.5,  0.5,  0.1 );
  glVertex3f( -0.5, -0.5,  0.1 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f( -0.5,  0.5,  0.1 );
  glVertex3f( -0.5,  0.5, -0.1 );
  glVertex3f(  0.5,  0.5, -0.1 );
  glVertex3f(  0.5,  0.5,  0.1 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f( -0.5, -0.5, -0.1 );
  glVertex3f( -0.5, -0.5,  0.1 );
  glVertex3f(  0.5, -0.5,  0.1 );
  glVertex3f(  0.5, -0.5, -0.1 );
  
  glEnd();

  
  // hands of the Clock
  glRotatef(angle1,0.0f, 0.0f, 1.0f);
  glBegin(GL_LINES);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glEnd();
  glRotatef(-1*angle1,0.0f, 0.0f, 1.0f);
  glRotatef(angle2,0.0f, 0.0f, 1.0f);
  glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glEnd();
  glRotatef(-1*angle2,0.0f, 0.0f, 1.0f);
  glRotatef(angle3,0.0f, 0.0f, 1.0f);
  glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.25f, 0.0f);
  glEnd();
  glRotatef(-1*angle3,0.0f, 0.0f, 1.0f);


  angle1 += 6.0f;
    if (angle1 > 360) {
        angle1 -= 360;
        angle2 += 6.0f;
    }
    if(angle2 > 360)
    {
      angle2 -= 360;
      angle3 += 6.0f;
    }
}
