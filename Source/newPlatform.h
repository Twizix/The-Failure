#ifndef NEWPLATFORM_H
#define NEWPLATFORM_H
#include <iostream>
using namespace std;

class newPlatform
{
public:
	newPlatform(int,int,int,int);
	~newPlatform(){};
	int getLeftX();
	int getRightX();
	int getTopY();
	int getBotY();
private:
	int x1;
	int x2;
	int y1;
	int y2;
};

#endif NEWPLATFORM_H