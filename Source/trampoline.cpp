#include "trampoline.h"

trampoline::trampoline(int xx1, int yy1, int xx2, int yy2)
{
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
}

int trampoline::getLeftX()
{
	return x1;
}

int trampoline::getRightX()
{
	return x2;
}

int trampoline::getTopY()
{
	return y2;
}

int trampoline::getBotY()
{
	return y1;
}