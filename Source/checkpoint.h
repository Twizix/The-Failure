#ifndef CHECKPOINT_H
#define CHECKPOINT_H

class checkpoint
{
public:
	checkpoint(int, int, int, int);
	~checkpoint(){};
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

#endif CHECKPOINT_H