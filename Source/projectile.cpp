#include "projectile.h"
#include <iostream>

using namespace std;

projectile::projectile(){}

void projectile::create(bool d, int _x, int _y)
{
	direction = d;
	x = _x;
	y = _y;
}

void projectile::travel()
{
	if (direction == true)
	{
		x -= 12;
	}
	else
	{
		x += 12;
	}
}

bool projectile::detectCollision(int l, int r, int u, int d)
{
	if (x >= l && x <= r &&  y <= u && y >= d)
		return true;
	else
		return false;
}

bool projectile::checkOffScreen()
{
	if (x >= 1152 || x <= 0)
		return true;
	else
		return false;
}

bool projectile::getDirection()
{
	return direction;
}

int projectile::getX()
{
	return x;
}

int projectile::getY()
{
	return y;
}

void projectile::destroy()
{
	x += 2500;
	y += 2500;
}