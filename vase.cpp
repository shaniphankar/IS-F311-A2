#include "vase.h"
#define pi 3.14159265

/*! This function draws the fractal tree that we used in the 1st assignment. The plant was of a rare variety that costed too much for the school to bring in.*/
void drawTree(float x1,float y1,float x2,float y2,int depth){
	// if((x2-x1)==0)
	// 	midPointLineAlgoG(x1,y1,x2,y2);
	// else if(((y2-y1)/(x2-x1))>=1 || ((y2-y1)/(x2-x1)) <=-1)
	// 	midPointLineAlgoG(x1,y1,x2,y2);
	// else
	// 	midPointLineAlgoL(x1,y1,x2,y2);

	glBegin(GL_LINES);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
	glEnd();

	if(depth<=0){
		return;
	}
	else
	{
		float xb,xc,xd,yb,yc,yd;
		double angle=atan2((y2-y1),(x2-x1));
		double dist=sqrt(pow((y2-y1),2)+pow((x2-x1),2))*0.7;
		// cout<<angle;
		// if(option == 6 || option ==8){
			xb=x2+cos(angle+1.0472)*dist;
			yb=y2+sin(angle+1.0472)*dist;
			xc=x2+dist*cos(angle-1.0472);
			yc=y2+dist*sin(angle-1.0472);
		// }
		// else if(option == 5 || option ==7){
		// 	xb=x2+cos(angle+0.5235)*dist;
		// 	yb=y2+sin(angle+0.5235)*dist;
		// 	xc=x2+dist*cos(angle-0.5235);
		// 	yc=y2+dist*sin(angle-0.5235);
		// }
		// else if(option == 9){
		// 	xb=x2+cos(angle+1.5714)*dist;
		// 	yb=y2+sin(angle+1.5714)*dist;
		// 	xc=x2+dist*cos(angle-1.5714);
		// 	yc=y2+dist*sin(angle-1.5714);
		// }
		drawTree(x2,y2,xb,yb,depth-1);
		drawTree(x2,y2,xc,yc,depth-1);
	}
}
/*! This function draws a potted plant. Its sharpness is a result of being 3D printed using the latest Gel 3D Printing Technologies.*/
void drawVase(){

  glRotatef( 0, 1.0, 0.0, 0.0 );
  glRotatef( 0, 0.0, 1.0, 0.0 );

  //Multi-colored side - FRONT
  glBegin(GL_POLYGON);

	glColor3f( 1.0, 0.0, 0.0 );
	glVertex3f(  0.1, -0.1, -0.3 );
	glVertex3f(  0.1,  0.1, -0.3 );
	glVertex3f( -0.1,  0.1, -0.3 );
	glVertex3f( -0.1, -0.1, -0.3 );

  glEnd();

  // White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	glVertex3f(  0.5, -0.5, 0.5 );
	glVertex3f(  0.5,  0.5, 0.5 );
	glVertex3f( -0.5,  0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(  1.0,  0.0,  1.0 );
	glVertex3f( 0.1, -0.1, -0.3 );
	glVertex3f( 0.1,  0.1, -0.3 );
	glVertex3f( 0.5,  0.5,  0.5 );
	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  1.0,  0.0 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glVertex3f( -0.1,  0.1, -0.3 );
	glVertex3f( -0.1, -0.1, -0.3 );
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f(  0.5,  0.5,  0.5 );
	glVertex3f(  0.1,  0.1, -0.3 );
	glVertex3f( -0.1,  0.1, -0.3 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  0.0,  0.0 );
	glVertex3f(  0.1, -0.1, -0.3 );
	glVertex3f(  0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.1, -0.1, -0.3 );
	glEnd();

  // drawTree(0, 0, 0, 0.2, 8);
	float x, y, z;
	glBegin(GL_LINES);

	glColor3f(   0.0,  1.0,  0.0 );
	// All lines lie in the xy plane.
	y = 0.0f;
	for(float angle = 0.0f; angle <= pi; angle += (pi/20.0f))
	  {
	  // Top half of the circle
	  x = 0.4f*sin(angle);
	  z = 0.4f*cos(angle)+0.5;
	  glVertex3f(x, y, z);    // First endpoint of line

	  // Bottom half of the circle
	  x = 0.4f*sin(angle + pi);
	  z = 0.4f*cos(angle + pi)+0.5;
	  glVertex3f(x, y, z);    // Second endpoint of line
	  }

	// Done drawing points
	glEnd();

}
