#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>

using namespace std;

class Player
{
public:
	Player(int, int);
	~Player(){};

	void refreshChecks();
	void checkAround(int,int,int,int);
	bool detectSpikeBox(int,int,int,int);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void screenSwapLeft();
	void screenSwapRight();
	void screenSwapUp();
	void screenSwapDown();

	bool isFacingLeft();
	void turnLeft();
	void turnRight();

	void jump();
	bool isJumping();
	bool isGrounded();

	void trampolineJump();

	int getX();
	int getY();
	int getLeftX();
	int getRightX();
	int getTopY();
	int getBotY();

	void setScreenNumber(int);
	int getScreenNumber();

private:
	int playerLeftX;
	int playerRightX;
	int playerTopY;
	int playerBotY;
	int centerX;
	int centerY;

	bool grounded;
	bool facingLeft;

	int leftValue;
	int rightValue;
	int upValue;
	int downValue;

	int rightMoveValue;

	bool jumping;
	int jumpHeight;
	int jumpCount;

	int screenNumber;
};

#endif PLAYER_H