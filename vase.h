#ifndef VASE_H
#define VASE_H

#include <GL/glut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawTree(float x1,float y1,float x2,float y2,int depth);
void drawVase();

#endif