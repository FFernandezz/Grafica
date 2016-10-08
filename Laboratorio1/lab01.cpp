#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;



void drawPolygon(int lados)
{
	int angulo=360/lados;
	vector<int> point;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	for (int i=0; i<360; i+=angulo)
	{
		float angulo = i*3.14159f/180.0f; // grados a radianes
		glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(cos(angulo), sin(angulo), 0.0f);
		glEnd();
		glFlush();
	}

}


void init()
{
 	glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowPosition(50, 50);
	 glutInitWindowSize(600, 600);
	 glutCreateWindow("OpenGL");
	 init();
	 //glutDisplayFunc(display);
	 drawPolygon(3);
	 glutMainLoop();
	 return 0;
}

//Compilar: g++ lab01.cpp -o gl -lGL -lGLU -lglut
