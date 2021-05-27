#include "spike.h"

spike::spike(int xx1, int yy1,int xx2,int yy2)
{
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
}

int spike::getLeftX()
{
	return x1;
}

int spike::getRightX()
{
	return x2;
}

int spike::getTopY()
{
	return y2;
}

int spike::getBotY()
{
	return y1;
}