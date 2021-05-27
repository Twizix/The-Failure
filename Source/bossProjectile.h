#ifndef BOSSPROJECTILE_H
#define BOSSPROJECTILE_H

class bossProjectile
{
public:
	bossProjectile(int, int,int,int);
	~bossProjectile(){};
	int getLeftX();
	int getRightX();
	int getTopY();
	int getBotY();

	int getX();
	int getY();

	void travel(int,int);
	void travel2(int, int);

private:
	int x1;
	int y1;
	int x2;
	int y2;
};

#endif BOSSPROJECTILE_H