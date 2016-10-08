#include <iostream>
#include "figure.cpp"


using namespace std;
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void init()
{
 	glClearColor(0,0,0,0);
}

void display()
{
	Figure figure_;
	figure_.drawLineMiddlePoint();
	//figure_.drawLineIncremental();
	//figure_.drawPolygon(3);

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

//Compilar: g++ -std=c++11 -Wall -Wextra -Werror lab01.cpp -o gl -lGL -lGLU -lglut
