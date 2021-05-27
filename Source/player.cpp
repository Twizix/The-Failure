#include "player.h"

// Contructor for the player object
Player::Player(int x, int y)
{
	centerX = x + 12;
	centerY = y + 18;
	playerLeftX = centerX - 7;
	playerRightX = centerX + 7;
	playerTopY = centerY + 17;
	playerBotY = centerY - 17;
	jumpHeight = 0;
	jumpCount = 0;
	jumping = false;
	grounded = true;
}


int Player::getX()
{
	return centerX;
}
int Player::getY()
{
	return centerY;
}

int Player::getLeftX()
{
	return playerLeftX;
}
int Player::getRightX()
{
	return playerRightX;
}
int Player::getTopY()
{
	return playerTopY;
}
int Player::getBotY()
{
	return playerBotY;
}

bool Player::isGrounded()
{
	return grounded;
}

void Player::setScreenNumber(int n)
{
	screenNumber = n;
}

int Player::getScreenNumber()
{
	return screenNumber;
}

void Player::screenSwapLeft()
{
	playerLeftX = 1151;
	playerRightX = 1165;
	playerTopY += 12;
	playerBotY += 12;
}

void Player::screenSwapRight()
{
	playerLeftX = -13;
	playerRightX = 1;
	playerTopY += 12;
	playerBotY += 12;
}

void Player::screenSwapDown()
{
	playerTopY = 872;
	playerBotY = 858;
}

void Player::screenSwapUp()
{
	playerTopY -= 864;
	playerBotY -= 864;
}

void Player::refreshChecks()
{
	leftValue = 6;
	rightValue = 6;
	upValue = 6;
	downValue = 6;
}

void Player::checkAround(int l, int r, int u, int d)
{
	// Checks for left wall collision
	if (leftValue == 6)
	{
		for (int value = 6; value > 0; value--)
		{
			if ((playerLeftX - value) <= r && (playerLeftX - value) >= l && playerTopY > d && playerBotY < u)
			{
				leftValue--;
			}
			else
				value = 0;
		}
	}

		// Checks for right wall collision
	if (rightValue == 6)
	{
		for (int value = 6; value > 0; value--)
		{
			if (playerRightX + value >= l && playerRightX + value <= r && playerTopY > d && playerBotY < u)
			{
				rightValue--;
			}
			else
				value = 0;
		}
	}

	// Checks for ceiling collision
	if (upValue != 0)
	{
		for (int value = 6; value > 0; value--)
		{
			if (playerTopY + value >= d && playerTopY + value <= u && playerRightX > l && playerLeftX < r)
			{
				upValue--;
			}
			else
				value = 0;
		}
	}

	// Checks for floor collision
	if (downValue != 0)
	{
		for (int value = 6; value > 0; value--)
		{
			if (playerBotY - value <= u && playerBotY - value >= d && playerRightX > l && playerLeftX < r)
			{
				downValue--;
			}
			else
				value = 0;
		}
	}


	grounded = false;
	if (downValue == 0)
	{
		jumpCount = 1;
		grounded = true;
	}
	if (upValue == 0)
		jumpHeight = 0;
}

bool Player::detectSpikeBox(int l, int r, int u, int d)
{
	if (playerRightX >= l && playerRightX < r && playerBotY < u && playerTopY > d)
		return true;
	else if (playerLeftX <= r && playerLeftX >= l && playerTopY > d && playerBotY < u)
		return true;
	else
		return false;
}


void Player::moveLeft()
{
	centerX -= leftValue;
	playerLeftX -= leftValue;
	playerRightX -= leftValue;
}

void Player::moveRight()
{
	centerX += rightValue;
	playerLeftX += rightValue;
	playerRightX += rightValue;
}

void Player::moveUp()
{
	centerY += upValue;
	playerTopY += upValue;
	playerBotY += upValue;
}

void Player::moveDown()
{
	centerY -= downValue;
	playerTopY -= downValue;
	playerBotY -= downValue;
}

bool Player::isJumping()
{
	if (jumpHeight > 0)
	{
		if (playerTopY >= 864)
			jumpHeight = 0;
		else
			jumpHeight -= 6;
	}
	else
		jumping = false;

	return jumping;
}

void Player::jump()
{
	if (jumping == false && jumpHeight == 0 && jumpCount == 1)
	{
		jumpCount--;
		jumpHeight = 300;
		jumping = true;
	}
}

void Player::trampolineJump()
{
		jumpHeight = 300;
		jumping = true;
}
