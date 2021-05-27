#include "newPlatform.h"

newPlatform::newPlatform(int xx1, int yy1, int xx2, int yy2)
{
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
}

int newPlatform::getLeftX()
{
	return x1;
}

int newPlatform::getRightX()
{
	return x2;
}

int newPlatform::getBotY()
{
	return y1;
}

int newPlatform::getTopY()
{
	return y2;
}