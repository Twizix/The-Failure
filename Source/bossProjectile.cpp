#include "bossProjectile.h"

bossProjectile::bossProjectile(int xx1, int yy1, int xx2, int yy2)
{
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
}

int bossProjectile::getLeftX()
{
	return x1;
}

int bossProjectile::getRightX()
{
	return x2;
}

int bossProjectile::getTopY()
{
	return y2;
}

int bossProjectile::getBotY()
{
	return y1;
}

int bossProjectile::getX()
{
	return (x1+x2)/2;
}

int bossProjectile::getY()
{
	return (y1+y2) / 2;
}


void bossProjectile::travel(int x, int y)
{
	if ((y > y1 && y < y2) || x1 < 1100)
	{
		x1 -= 10;
		x2 -= 10;
	}
	if (x2 < 0)
	{
		x1 = 1102;
		x2 = 1282;
	}

}

void bossProjectile::travel2(int x, int y)
{
	if ((y > y1 && y < y2) || x1 < 1100)
	{
		x1 -= 10;
		x2 -= 10;
	}
	if (x2 < 0)
	{
		x1 = 1128;
		x2 = 1184;
	}

}