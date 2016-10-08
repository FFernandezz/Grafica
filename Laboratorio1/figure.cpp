#include "figure.h"

vector<Point<float> > Figure::drawPolygonAuxiliar(int lados)
{
	int angulo=360/lados;
	vector<Point<float> > points;
	vector<Point<float> > aristas;

	Auxiliar A;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	for (int i=0; i<360; i+=angulo)
	{
		float angulo = i*3.14159f/180.0f; // grados a radianes
		Point<float> point(cos(angulo), sin(angulo), 0.0f);
		points.push_back(point);
	}
	for(unsigned int i=0;i<points.size()-1;i++)
	{
		A.drawLineOpenGL(points[i].m_x, points[i].m_y, points[i].m_z,points[i+1].m_x, points[i+1].m_y,points[i+1].m_z);
		aristas.push_back(points[i]);
		aristas.push_back(points[i+1]);
	}
	
	A.drawLineOpenGL(points[lados-1].m_x, points[lados-1].m_y, points[lados-1].m_z, points[0].m_x, points[0].m_y,points[0].m_z);
	aristas.push_back(points[lados-1]);
	aristas.push_back(points[0]);

	return aristas;
}

void Figure::drawPolygon(int lados)
{
	int angulo=360/lados;
	vector<Point<float> > points;
	Auxiliar A;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	for (int i=0; i<360; i+=angulo)
	{
		float angulo = i*3.14159f/180.0f; // grados a radianes
		Point<float> point(cos(angulo), sin(angulo), 0.0f);
		points.push_back(point);
	}
	for(unsigned int i=0;i<points.size()-1;i++)
	{
		A.drawLineOpenGL(points[i].m_x, points[i].m_y, points[i].m_z,points[i+1].m_x, points[i+1].m_y,points[i+1].m_z);
	}
	
	A.drawLineOpenGL(points[lados-1].m_x, points[lados-1].m_y, points[lados-1].m_z, points[0].m_x, points[0].m_y,points[0].m_z);
	

}

void Figure::drawLineIncremental()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();

	Point<float> point1(-0.5f,0.5f,0.0f);
	Point<float> point2(0.5f,-0.5f,0.0f);
	
	Auxiliar A;
	A.drawLineOpenGL(point1.m_x, point1.m_y, point1.m_z,point2.m_x, point2.m_y, point2.m_z);
    
	float x,y;
	float a;
	a=(point2.m_y - point1.m_y)/(point2.m_x - point1.m_x);
	for(x=point1.m_x;x<=point2.m_x;x+=0.1)
	{
		y=(point1.m_y + a * (x- point1.m_x));
		cout<<x<<" "<<y<<endl;
		A.drawPointOpenGL(x, y, 0.0f);
	}
}

void Figure::drawLineMiddlePoint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();

	//puntos creados
	Point<float> point1(0.0f,0.0f,0.0f);
	Point<float> point2(0.7f,0.3f,0.0f);
	Auxiliar A;
	A.drawLineOpenGL(point1.m_x, point1.m_y, point1.m_z,point2.m_x, point2.m_y, point2.m_z);

	float x, y;
	float dx,dy, incE, incNE, d ;
	dx = point2.m_x - point1.m_x;
	dy = point2.m_y - point1.m_y;
	d = 2 * dy-dx;
	incE = 2 * dy;
	incNE = 2 * (dy - dx);
	x = point1.m_x;
	y = point1.m_y;

	A.drawPointOpenGL(x, y, 0.0f);

	while(x < point2.m_x)
	{
		if(d <= 0)
		{
			d = d + incE;
			x = x + 0.01f;
		}
		else
		{
			d = d + incNE;
			x = x + 0.01f;
			y = y + 0.01f;
		}

		cout<<x<<" "<<y<<endl;
		A.drawPointOpenGL(x, y, 0.0f);
	}
}