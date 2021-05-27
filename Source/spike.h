#ifndef SPIKE_H
#define SPIKE_H

class spike
{
public:
	spike(int, int,int,int);
	~spike(){};
	int getLeftX();
	int getRightX();
	int getTopY();
	int getBotY();
private:
	int x1;
	int y1;
	int x2;
	int y2;
};

#endif SPIKE_H