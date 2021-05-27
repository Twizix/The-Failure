#include "checkpoint.h"

checkpoint::checkpoint(int xx1, int yy1, int xx2, int yy2)
{
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
}

int checkpoint::getLeftX()
{
	return x1;
}

int checkpoint::getRightX()
{
	return x2;
}

int checkpoint::getTopY()
{
	return y2;
}

int checkpoint::getBotY()
{
	return y1;
}