#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

class Auxiliar
{
public:
	Auxiliar(){}
	void drawPointOpenGL(float x, float y, float z);
	void drawLineOpenGL(float x1, float y1, float z1,float x2, float y2, float z2);
	
	
};

void Auxiliar::drawPointOpenGL(float x, float y, float z)
{
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	glVertex3f(x, y, z);
	glEnd();
	glFlush(); 
}

void Auxiliar::drawLineOpenGL(float x1, float y1, float z1,float x2, float y2, float z2)
{
	glColor3f(1,1,1);
	glBegin(GL_LINES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
	glEnd();
	glFlush();
}