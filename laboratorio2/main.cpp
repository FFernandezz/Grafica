#include <GL/glut.h>
#include <iostream>

#include "point.h"
#include <vector>
#include <map>
#include <math.h>

using namespace std;

#define PI 3.1416

int width=600;
int height=600;
vector<Point<float> > listPoints;

void render(void);
void reshape(int width_, int height_);

void keyboard(unsigned char c, int x, int y);
void arrowKey(int key, int x, int y);
void mouse(int button, int state, int x, int y);

void draw();
void scale();
void rotation();
void traslationX(float d);
void traslationY(float d);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//glutInitWindowPosition(70,70);
	glutInitWindowSize(width,height);
	glutCreateWindow("Aplicación");
	
	glutDisplayFunc(render);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrowKey);
	glutMouseFunc(mouse);
	glutMainLoop();
	
}

void reshape(int width_, int height_)
{
	glViewport(0, 0, width_, height_);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
	glOrtho(-width/2,width/2 ,-height/2, height/2, -1, 1);
	glMatrixMode(GL_MODELVIEW);

}

void arrowKey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_RIGHT:
			traslationX(1);
			draw();
			break;

		case GLUT_KEY_LEFT:
			traslationX(-1);
			draw();
			break;

		case GLUT_KEY_UP:
			traslationY(1);
			draw();
			break;

		case GLUT_KEY_DOWN:
			traslationY(-1);
			draw();
			break;		
	}
}

void keyboard(unsigned char c, int x, int y)
{
	if(c == 27){
		exit(0);
	}
	if(c == 32)
	{
		if(!listPoints.empty()){
			listPoints.clear();
		}	
	}
	if(c == 45)
	{
		scale();
		draw();
	}
	if(c == 43){cout<<"+"<<endl;}
	if(c == 114)
	{
		rotation();
		draw();
	}
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_RIGHT_BUTTON){
		draw();
	}
	if(button == GLUT_LEFT_BUTTON)
	{
		float x_=x-width/2;
		float y_=(height/2)-y;
		float z_=0.0;
		Point<float> p(x_,y_,0);
		listPoints.push_back(p);

		cout<<x_<<" "<<y_<<endl;
	}
}

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
	for(unsigned int i=0;i<listPoints.size();i+=2)
	{
		glVertex3f(listPoints[i].m_x,listPoints[i].m_y,listPoints[i].m_z);
	}

	glEnd();
	glutSwapBuffers();
}

void scale()
{
	float factor=0.1;
	for(unsigned int i=0;i<listPoints.size();i+=2)
	{
		Point<float> p(listPoints[i].m_x*factor,listPoints[i].m_y*factor,listPoints[i].m_z*factor);
		listPoints[i]=p;
	}


}
void rotation()
{
	float angulo=45;
	float coseno=cos(angulo * PI/180.0);
	float seno=sin(angulo * PI/180.0);
	for(unsigned int i=0;i<listPoints.size();i+=2)
	{
		float x_=(listPoints[i].m_x*coseno) - (listPoints[i].m_y *seno);
		float y_=(listPoints[i].m_x*seno) - (listPoints[i].m_y *coseno);
		Point<float> p(x_,y_,listPoints[i].m_z);
		listPoints[i]=p;
	}

}

void traslationX(float d)
{
	for(unsigned int i=0;i<listPoints.size();i+=2)
	{
		float x_=listPoints[i].m_x+d;
		Point<float> p(x_,listPoints[i].m_y,listPoints[i].m_z);
		listPoints[i]=p;
	}

}

void traslationY(float d)
{
	for(unsigned int i=0;i<listPoints.size();i+=2)
	{
		float y_=listPoints[i].m_y+d;
		Point<float> p(listPoints[i].m_x,y_,listPoints[i].m_z);
		listPoints[i]=p;
	}

}