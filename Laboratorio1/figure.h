#include <iostream>
#include "point.h"
#include <vector>
#include <GL/glut.h>
#include <math.h>
#include "auxiliar.h"
#include <utility>

using namespace std;

class Figure
{
public:
	Figure(){}
	void drawPolygon(int lados);
	vector<Point<float> > drawPolygonAuxiliar(int lados);
	void drawLineIncremental();
	void drawLineMiddlePoint();
	void drawCircle();
	void fillingPolygons(int lados);

	
};
