#ifndef TRAMPOLINE_H
#define TRAMPOLINE_H

class trampoline
{
public:
	trampoline(int, int, int, int);
	~trampoline(){};
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

#endif TRAMPOLINE_H