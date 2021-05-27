#include <iostream>

using namespace std;

#pragma once

class projectile
{
public:
	projectile();
	~projectile() {};
	void create(bool, int, int);
	void travel();
	bool getDirection();
	bool detectCollision(int,int,int,int);
	bool checkOffScreen();
	int getX();
	int getY();

	void destroy();

private:
	// True = left, False = Right
	bool direction;
	int x;
	int y;



};