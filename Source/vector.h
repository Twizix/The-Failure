#ifndef VECTORCLASS_H
#define VECTORCLASS_H

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

class vector
{
public:
	vector(int, int, int, int);
	double getMagnitude();
	vector add(vector);
	vector scalarMultiply(double);
	double dotProduct(vector);
	int getX1();
	int getX2();
	int getY1();
	int getY2();
private:
	int x1;
	int x2;
	int y1;
	int y2;
	double slope;
	double magnitude;
};

#endif VECTORCLASS_H