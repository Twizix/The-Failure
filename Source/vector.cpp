#include "vector.h"
#include <cmath>
#include <stdio.h>
#include <iomanip>
vector::vector(int _x1, int _y1, int _x2, int _y2)
{
	x1 = _x1;
	x2 = _x2;
	y1 = _y1;
	y2 = _y2;
	slope = (y2 - y1) / (x2 - x1);
	magnitude = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

double vector::getMagnitude()
{
	return magnitude;
}

vector vector::add(vector v)
{
	vector result(x1,y1, v.x2, v.y2);
	return result;
}

vector vector::scalarMultiply(double scalar)
{
	vector result(x1,y1, scalar*x2, scalar*y2);
	return result;
}