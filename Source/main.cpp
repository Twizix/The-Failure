// The MIT License (MIT)
// 
// Copyright (c) 2016 Anastasios Stamadianos
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <iostream>
#include <Fizzle\Fizzle.h>
#include "player.h"
#include "newPlatform.h"
#include "spike.h"
#include "projectile.h"
#include "trampoline.h"
#include "checkpoint.h"
#include "bossProjectile.h"
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <array>
#include <sstream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <string>

using namespace std; 

// Initializes all the global scope function the game uses
void save(int,int,int,int,int);
void load(int&,int&,int&,int&,int&);
string getTextFileNameWorld1(int);
string getTextFileNameWorld2(int);
int world1();
int world2();

int mainMenu()
{
	FzlSpriteHandle menu = FzlLoadSprite("../../../Assets/sprite/menuscreen.png", 1152, 864);
	FzlSpriteHandle options = FzlLoadSprite("../../../Assets/sprite/options.png", 1152, 864);
	FzlSpriteHandle credits = FzlLoadSprite("../../../Assets/sprite/credits.png", 1152, 864);

	int menuFrame = 0;
	int num = 0;
	bool exit = false;
	bool credit = false;
	bool option = false;

	while (exit == false)
	{
		if (FzlGetKey(FzlKeyUpArrow) && menuFrame > 0)
		{
			++num;
			if (num >= 5)
			{
				menuFrame -= 1;
				num = 0;
			}
		}
		else if (FzlGetKey(FzlKeyDownArrow) && menuFrame < 4)
		{
			++num;
			if (num >= 5)
			{
				menuFrame += 1;
				num = 0;
			}
		}
		// Pressing Enter in Menu
		else if (FzlGetKey(FzlKeyEnter) && menuFrame == 0) // continue
		{
			exit = true;
		}
		else if (FzlGetKey(FzlKeyEnter) && menuFrame == 1) // new game
		{
			save(101, 72, 792, 1, 0);
			exit = true;
		}
		else if (FzlGetKey(FzlKeyEnter) && menuFrame == 2) //options
		{
			option = true;
		}
		else if (FzlGetKey(FzlKeyEnter) && menuFrame == 3) // credits
		{
			credit = true;
		}
		else if (FzlGetKey(FzlKeyEnter) && menuFrame == 4) // exit
		{
			return 1;
		}
		else if (FzlGetKey(FzlKeyEscape)) // exit
		{
			credit = false;
			option = false;
		}
		if (credit == true)
		{
			FzlDrawSprite(credits, 576, 432, 0);
		}
		else if (option == true)
		{
			FzlDrawSprite(options, 576, 432, 0);
		}
		else
			FzlDrawAnimatedSprite(menu, 0, menuFrame, 576, 432, 0);


		FzlSwapBuffers();
	}

	FzlDeleteSprite(menu);
	FzlDeleteSprite(credits);
	return 0;
}

// Determines which text file the game wants to use in world 1
string getTextFileNameWorld1(int screen)
{
	string screenTxt;
	if (screen == 101)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen1.txt";
	}
	else if (screen == 111)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen2.txt";
	}
	else if (screen == 112)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen3.txt";
	}
	else if (screen == 113)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen4.txt";
	}
	else if (screen == 114)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen5.txt";
	}
	else if (screen == 122)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen6.txt";
	}
	else if (screen == 132)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen7.txt";
	}
	else if (screen == 133)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen8.txt";
	}
	else if (screen == 134)
	{
		screenTxt = "../../../Assets/txtFiles/world1Screen9.txt";
	}
	else if (screen == 135)
	{
		screenTxt = "../../../Assets/txtFiles/world1Boss.txt";
	}
	return screenTxt;
};


// Determines which text file the game wants to use in world 1
string getTextFileNameWorld2(int screen)
{
	string screenTxt;
	if (screen == 201)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen1.txt";
	}
	else if (screen == 202)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen2.txt";
	}
	else if (screen == 212)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen3.txt";
	}
	else if(screen == 222)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen4.txt";
	}
	else if(screen == 223)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen5.txt";
	}
	else if(screen == 224)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen6.txt";
	}
	else if(screen == 221)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen7.txt";
	}
	else if (screen == 231)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen8.txt";
	}
	else if (screen == 232)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen9.txt";
	}
	else if (screen == 242)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen10.txt";
	}
	else if (screen == 252)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen11.txt";
	}
	else if (screen == 253)
	{
		screenTxt = "../../../Assets/txtFiles/world2Screen12.txt";
	}
	
	return screenTxt;
};



// Saves your players current screen, x position and y position to the userData text file
void save(int screen, int x, int y, int d, int pc)
{
	ofstream save;
	save.open("../../../Assets/userData.txt");
	save << flush;
	save << screen;
	save << endl;
	save << x;
	save << endl;
	save << y;
	save << endl;
	save << d;
	save << endl;
	save << pc;
	save.close();
}

// Loads your players current screen, x position and y position from the userData text file
void load(int& screen, int& x, int& y, int& d, int& pc)
{
	ifstream load;
	load.open("../../../Assets/userData.txt");
	load >> screen;
	load >> x;
	load >> y;
	load >> d;
	load >> pc;
	load.close();
}




// Function to handle all maps within the first world
int world1()
{

	// Creates variables to load and store the players screen and position
	int screen;
	int playerX;
	int playerY;
	int direction;
	int pencilCase;
	load(screen, playerX, playerY, direction, pencilCase);

	// Creates a player object with the loaded position
	Player player(playerX, playerY);

	// Deals with setting up the level
	string txtName = getTextFileNameWorld1(screen);
	ifstream levelTextFile;
	levelTextFile.open(txtName);
	char read;
	int platformCount = 0;
	int spikeCount = 0;
	int trampolineCount = 0;
	int checkpointCount = 0;
	int bossProjectileCount = 0;

	// Creates vector to hold all the platform and spike objects
	std::vector<newPlatform> platforms;
	std::vector<spike> spikes;
	std::vector<trampoline> trampolines;
	std::vector<checkpoint> checkpoints;
	std::vector<bossProjectile> bossProjectiles;

	// Clears the vectors of all objects
	platforms.clear();
	spikes.clear();
	trampolines.clear();
	checkpoints.clear();
	bossProjectiles.clear();

	// Creates all the collision based objects in the level (reads text file and creates objects accordingly
	for (int i = 35; i >= 0; i--)
	{
		for (int j = 0; j < 48; j++)
		{
			levelTextFile >> read;
			if (read == 'P')
			{
				newPlatform temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				platforms.push_back(temp);
				platformCount++;
			}
			else if (read == 'S')
			{
				spike temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				spikes.push_back(temp);
				spikeCount++;
			}
			else if (read == 'T')
			{
				trampoline temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				trampolines.push_back(temp);
				trampolineCount++;
			}
			else if (read == 'C')
			{
				checkpoint temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				checkpoints.push_back(temp);
				checkpointCount++;
			}
			else if (read == 'F')
			{
				bossProjectile temp(j * 24, (i * 24)+5, (j * 24) + 180, (i * 24) + 38);
				bossProjectiles.push_back(temp);
				bossProjectileCount++;
			}
		}
	}
	levelTextFile.close();

	// Creates all the sprites needed in the world
	FzlSpriteHandle left = FzlLoadSprite("../../../Assets/sprite/left.png", 24, 36);
	FzlSpriteHandle right = FzlLoadSprite("../../../Assets/sprite/right.png", 24, 36);
	FzlSpriteHandle aaronLeft = FzlLoadSprite("../../../Assets/sprite/aaronLeft.png", 24, 36);
	FzlSpriteHandle aaronRight = FzlLoadSprite("../../../Assets/sprite/aaronRight.png", 24, 36);
	FzlSpriteHandle projectileLeft = FzlLoadSprite("../../../Assets/sprite/projectileLeft.png", 19, 5);
	FzlSpriteHandle projectileRight = FzlLoadSprite("../../../Assets/sprite/projectileRight.png", 19, 5);
	FzlSpriteHandle pencilCaseSprite = FzlLoadSprite("../../../Assets/sprite/pencilCase.png", 90, 90);
	FzlSpriteHandle screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen1.png", 1152, 864);
	FzlSpriteHandle boss1ProjectileSprite = FzlLoadSprite("../../../Assets/sprite/boss1Projectile.png", 216, 48);
	FzlSpriteHandle boss1Sprite = FzlLoadSprite("../../../Assets/sprite/boss1Sprite.png", 824, 796);
	FzlSpriteHandle fail = FzlLoadSprite("../../../Assets/sprite/fail.png", 824, 796);


	FzlSpriteHandle full = FzlLoadSprite("../../../Assets/sprite/100.png", 1152, 864);
	FzlSpriteHandle kindafull = FzlLoadSprite("../../../Assets/sprite/75.png", 1152, 864);
	FzlSpriteHandle half = FzlLoadSprite("../../../Assets/sprite/50.png", 1152, 864);
	FzlSpriteHandle almost = FzlLoadSprite("../../../Assets/sprite/25.png", 1152, 864);
	FzlSpriteHandle done = FzlLoadSprite("../../../Assets/sprite/0.png", 1152, 864);


	FzlSoundHandle walking = FzlLoadSound("../../../Assets/sound/Footsteps.wav", false);


	bool bossScreen = false;
	// Determines what image to use for the background
	if (screen == 111)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen2.png", 1152, 864);
	else if (screen == 112)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen3.png", 1152, 864);
	else if (screen == 113)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen4.png", 1152, 864);
	else if (screen == 114)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen5.png", 1152, 864);
	else if (screen == 122)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen6.png", 1152, 864);
	else if (screen == 132)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen7.png", 1152, 864);
	else if (screen == 133)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen8.png", 1152, 864);
	else if (screen == 134)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Screen9.png", 1152, 864);
	else if (screen == 135)
	{
		screenImage = FzlLoadSprite("../../../Assets/sprite/world1Boss.png", 1152, 864);
		bossScreen = true;
	}

	// Variables used in keeping track of the characters animation
	int aaronAnim = 0;
	int aaronFrame = 0;
	int shouldClose = 0;
	bool jumpKeyPressed = false;
	int count = 0; 
	int bossHP = 20;
	int bossYValue = 372;
	bool dead = false;
	bool upArrowPressed = false;

	// Makes sure the character can jump upon entering a new screen
	bool firstJump = false;

	// Variables to keep track of the players projectile
	bool onScreenProjectile = false;
	projectile pencil;

	// Loops the entire game
	while (!shouldClose)
	{
		// Determines how far the player can move in each direction every frame
		player.refreshChecks();

		// Platform collision
		for (int i = 0; i < platformCount; i++)
		{
			player.checkAround(platforms[i].getLeftX(), platforms[i].getRightX(), platforms[i].getTopY(), platforms[i].getBotY());
		}
		// Spike box collision
		for (int i = 0; i < spikeCount; i++)
		{
			if (player.detectSpikeBox(spikes[i].getLeftX(), spikes[i].getRightX(), spikes[i].getTopY(), spikes[i].getBotY()))
			{
				dead = true;
			}
		}
		// Trampoline box collision
		for (int i = 0; i < trampolineCount; i++)
		{
			if (player.detectSpikeBox(trampolines[i].getLeftX(), trampolines[i].getRightX(), trampolines[i].getTopY(), trampolines[i].getBotY()))
				player.trampolineJump();
		}
		// Projectile collision
		for (int i = 0; i < platformCount; i++)
		{
			if (bossScreen == true && bossHP > 0)
			{
				if (pencil.detectCollision(750, 1152, 510, 0))
				{
					bossHP--;
					pencil.destroy();
					onScreenProjectile = false;
				}
			}
			if (pencil.detectCollision(platforms[i].getLeftX(), platforms[i].getRightX(), platforms[i].getTopY(), platforms[i].getBotY()))
			{
				onScreenProjectile = false;
			}
		}
		// Projectile onto checkpoint collision
		for (int i = 0; i < checkpointCount; i++)
		{
			if (player.detectSpikeBox(checkpoints[i].getLeftX(), checkpoints[i].getRightX(), checkpoints[i].getTopY(), checkpoints[i].getBotY()))
				save(screen, player.getLeftX() - 5, player.getBotY() - 1, direction, pencilCase);
		}
		// Boss projectile collision
		for (int i = 0; i < bossProjectileCount; i++)
		{
			if (bossHP > 0)
			{
				if (player.detectSpikeBox(bossProjectiles[i].getLeftX(), bossProjectiles[i].getRightX(), bossProjectiles[i].getTopY(), bossProjectiles[i].getBotY()))
					shouldClose = true;
			}
		}

		// Determines if the projectile goes off screen (collision with the edges of the screen)
		if (pencil.checkOffScreen())
		{
			onScreenProjectile = false;
		}

		if (shouldClose == false)
		{
			// Changes character sprites based off last key pressed


			// Moves the character left
			if (dead == false)
			{
				if (FzlGetKey(FzlKeyLeftArrow))
				{
					direction = 0;
					player.moveLeft();
				}

				// Moves the character right
				else if (FzlGetKey(FzlKeyRightArrow))
				{
					direction = 1;
					player.moveRight();
				}

				else
				{
					aaronFrame = 0;
					aaronAnim = 0;
				}
			}

			// Shoots a projectile if the 'S' key is pressed
			if (FzlGetKey(FzlKeyS) && onScreenProjectile == false && pencilCase == 1)
			{
				// Modifys the pencil object depending on which direction the player is facing
				if (direction == 0)
				{
					pencil.create(true, player.getX(), player.getY());
				}
				else
				{
					pencil.create(false, player.getX(), player.getY());
				}
				onScreenProjectile = true;
			}

			// Reset to the previous save
			if (FzlGetKey(FzlKeyR))
			{
				shouldClose = true;
			}

			// If there is a pencil on the screen, let it travel through the screen
			if (onScreenProjectile == true)
				pencil.travel();

			// Jump command
			if (FzlGetKey(FzlKeyUpArrow))
			{
				if (jumpKeyPressed == false)
				{
					if (firstJump == false)
					{
						player.trampolineJump();
						firstJump = true;
					}
					else
						player.jump();
				}
				jumpKeyPressed = true;
			}
			else
			{
				jumpKeyPressed = false;
			}

			// Move the player up during a jump
			if (player.isJumping())
			{
				player.moveUp();
			}

			// Ignore falling if the character is mid-jump
			if (player.isJumping() == false && dead == false)
				player.moveDown();


			// Keeps the character animation at a specific frame as long as the character is in the air
			// aka prevents walking in mid-air
			if (player.isGrounded() == false)
			{
				aaronFrame = 6;
				aaronAnim = 6;
			}


			// Draws the background
			FzlDrawSprite(screenImage, 576, 432, 0.0f);

			if (dead == false)
			{
				// Draws the player
				if (direction == 0)
					FzlDrawAnimatedSprite(aaronLeft, aaronAnim, aaronFrame, player.getX(), player.getY(), 0.0f);
				else if (direction == 1)
					FzlDrawAnimatedSprite(aaronRight, aaronAnim, aaronFrame, player.getX(), player.getY(), 0.0f);
			}
			else
			{
				FzlDrawSprite(fail, 576, 442, 0.0f);
			}
			if (bossScreen == true)
			{
				FzlDrawSprite(boss1Sprite, 944, bossYValue, 0.0f);

				if (bossHP > 15)
				{
					FzlDrawSprite(full, 576, 432, 0.0f);
				}
				else if (bossHP > 10)
				{
					FzlDrawSprite(kindafull, 576, 432, 0.0f);
				}
				else if (bossHP > 5)
				{
					FzlDrawSprite(half, 576, 432, 0.0f);
				}
				else if (bossHP > 0)
				{
					FzlDrawSprite(almost, 576, 432, 0.0f);
				}

				if (bossHP > 0)
				{
					if (player.getRightX() >= 600)
						player.moveLeft();
					for (int i = 0; i < bossProjectileCount; i++)
					{
						bossProjectiles[i].travel(player.getX(), player.getY());
						FzlDrawSprite(boss1ProjectileSprite, bossProjectiles[i].getX(), bossProjectiles[i].getY(), 0.0f);
					}
				}
				else
				{
					FzlDrawSprite(done, 576, 432, 0.0f);
					bossYValue -= 5;
				}
			}

			if (screen == 114 && player.getX() > 531 && player.getX() < 621 && player.getY() > 387 && player.getY() < 477)
			{
				pencilCase = 1;
			}

			if (pencilCase == 0 && screen == 114)
				FzlDrawSprite(pencilCaseSprite, 576, 432, 0.0f);



			// Draws the projectile sprite if there is one on screen at the current time
			if (onScreenProjectile == true)
			{
				if (pencil.getDirection())
					FzlDrawSprite(projectileLeft, pencil.getX(), pencil.getY(), 0.0f);
				else
					FzlDrawSprite(projectileRight, pencil.getX(), pencil.getY(), 0.0f);
			}

			if (firstJump == false && player.isGrounded())
			{
				firstJump = true;
			}

			
			// Changes the frame of the animation (walking)
			if (count >= 3 && player.isJumping() == false)
			{
				count = 0;
				aaronFrame++;
			}
			count++;

			// Loops the animation
			if (aaronFrame >= 8)
			{
				aaronFrame = 0;
				aaronAnim++;
				if (aaronAnim >= 8)
					aaronAnim = 0;
			}

			if (player.getLeftX() >= 1152)
			{
				screen++;
				player.screenSwapRight();
				save(screen, player.getLeftX() + 7, player.getBotY() - 1, direction, pencilCase);
				shouldClose = true;
			}
			else if (player.getTopY() <= 0)
			{
				screen += 10;
				player.screenSwapDown();
				save(screen, player.getLeftX() - 5, player.getBotY() - 1, direction, pencilCase);
				shouldClose = true;
			}
			else if (player.getRightX() <= 0)
			{
				screen -= 1;
				player.screenSwapLeft();
				save(screen, player.getLeftX() - 17, player.getBotY() - 1, direction, pencilCase);
				shouldClose = true;
			}

			FzlSwapBuffers();
			//Until the user hits the escape key, keep looping
			//shouldClose = FzlGetKey(FzlKeyEscape);
		}
	}

	FzlDeleteSprite(left);
	FzlDeleteSprite(right);
	FzlDeleteSprite(aaronLeft);
	FzlDeleteSprite(aaronRight);
	FzlDeleteSprite(projectileLeft);
	FzlDeleteSprite(projectileRight);
	FzlDeleteSprite(pencilCaseSprite);
	FzlDeleteSprite(screenImage);
	FzlDeleteSprite(boss1ProjectileSprite);
	FzlDeleteSprite(boss1Sprite);
	FzlDeleteSprite(fail);
	FzlDeleteSound(walking);

	FzlDeleteSprite(full);
	FzlDeleteSprite(kindafull);
	FzlDeleteSprite(half);
	FzlDeleteSprite(almost);
	FzlDeleteSprite(done);


	return 0;
}







// Function to handle all maps within the first world
int world2()
{

	// Creates variables to load and store the players screen and position
	int screen;
	int playerX;
	int playerY;
	int direction;
	int pencilCase;
	load(screen, playerX, playerY, direction, pencilCase);

	// Creates a player object with the loaded position
	Player player(playerX, playerY);

	// Deals with setting up the level
	string txtName = getTextFileNameWorld2(screen);
	ifstream levelTextFile;
	levelTextFile.open(txtName);
	char read;
	int platformCount = 0;
	int spikeCount = 0;
	int trampolineCount = 0;
	int checkpointCount = 0;
	int bossProjectileCount = 0;

	// Creates vector to hold all the platform and spike objects
	std::vector<newPlatform> platforms;
	std::vector<spike> spikes;
	std::vector<trampoline> trampolines;
	std::vector<checkpoint> checkpoints;
	std::vector<bossProjectile> bossProjectiles;

	// Clears the vectors of all objects
	platforms.clear();
	spikes.clear();
	trampolines.clear();
	checkpoints.clear();
	bossProjectiles.clear();

	// Creates all the collision based objects in the level (reads text file and creates objects accordingly
	for (int i = 35; i >= 0; i--)
	{
		for (int j = 0; j < 48; j++)
		{
			levelTextFile >> read;
			if (read == 'P')
			{
				newPlatform temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				platforms.push_back(temp);
				platformCount++;
			}
			else if (read == 'S')
			{
				spike temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				spikes.push_back(temp);
				spikeCount++;
			}
			else if (read == 'T')
			{
				trampoline temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				trampolines.push_back(temp);
				trampolineCount++;
			}
			else if (read == 'C')
			{
				checkpoint temp(j * 24, i * 24, (j * 24) + 24, (i * 24) + 24);
				checkpoints.push_back(temp);
				checkpointCount++;
			}
			else if (read == 'F')
			{
				bossProjectile temp(j * 24, (i * 24) + 5, (j * 24) + 180, (i * 24) + 38);
				bossProjectiles.push_back(temp);
				bossProjectileCount++;
			}
		}
	}
	levelTextFile.close();

	// Creates all the sprites needed in the world
	FzlSpriteHandle left = FzlLoadSprite("../../../Assets/sprite/left.png", 24, 36);
	FzlSpriteHandle right = FzlLoadSprite("../../../Assets/sprite/right.png", 24, 36);
	FzlSpriteHandle aaronLeft = FzlLoadSprite("../../../Assets/sprite/aaronLeft.png", 24, 36);
	FzlSpriteHandle aaronRight = FzlLoadSprite("../../../Assets/sprite/aaronRight.png", 24, 36);
	FzlSpriteHandle projectileLeft = FzlLoadSprite("../../../Assets/sprite/projectileLeft.png", 19, 5);
	FzlSpriteHandle projectileRight = FzlLoadSprite("../../../Assets/sprite/projectileRight.png", 19, 5);
	FzlSpriteHandle pencilCaseSprite = FzlLoadSprite("../../../Assets/sprite/pencilCase.png", 90, 90);
	FzlSpriteHandle screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen1.png", 1152, 864);
	FzlSpriteHandle boss2ProjectileSprite = FzlLoadSprite("../../../Assets/sprite/boss2Projectile.png", 216, 48);
	FzlSpriteHandle boss2Sprite = FzlLoadSprite("../../../Assets/sprite/boss2Sprite.png", 820, 680);
	FzlSpriteHandle boss2SpriteHard = FzlLoadSprite("../../../Assets/sprite/boss2SpriteHard.png", 820, 680);

	FzlSpriteHandle fail = FzlLoadSprite("../../../Assets/sprite/fail.png", 824, 796);
	FzlSpriteHandle a = FzlLoadSprite("../../../Assets/sprite/a.png", 824, 796);

	FzlSpriteHandle full = FzlLoadSprite("../../../Assets/sprite/100.png", 1152, 864);
	FzlSpriteHandle kindafull = FzlLoadSprite("../../../Assets/sprite/75.png", 1152, 864);
	FzlSpriteHandle half = FzlLoadSprite("../../../Assets/sprite/50.png", 1152, 864);
	FzlSpriteHandle almost = FzlLoadSprite("../../../Assets/sprite/25.png", 1152, 864);
	FzlSpriteHandle done = FzlLoadSprite("../../../Assets/sprite/0.png", 1152, 864);

	FzlSoundHandle walking = FzlLoadSound("../../../Assets/sound/Footsteps.wav", false);
	FzlSoundHandle boss = FzlLoadSound("../../../Assets/sound/failureMusic2.wav", true);
	FzlSoundHandle tengaku = FzlLoadSound("../../../Assets/sound/tengaku.wav", true);

	bool bossScreen = false;
	// Determines what image to use for the background
	if (screen == 202)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen2.png", 1152, 864);
	else if (screen == 212)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen3.png", 1152, 864);
	else if (screen == 222)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen4.png", 1152, 864);
	else if (screen == 223)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen5.png", 1152, 864);
	else if (screen == 224)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen6.png", 1152, 864);
	else if (screen == 221)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen7.png", 1152, 864);
	else if (screen == 231)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen8.png", 1152, 864);
	else if (screen == 232)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen9.png", 1152, 864);
	else if (screen == 242)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen10.png", 1152, 864);
	else if (screen == 252)
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen11.png", 1152, 864);
	else if (screen == 253)
	{
		FzlPlaySound(boss);
		screenImage = FzlLoadSprite("../../../Assets/sprite/world2Screen12.png", 1152, 864);
		bossScreen = true;
	}

	// Variables used in keeping track of the characters animation
	int aaronAnim = 0;
	int aaronFrame = 0;
	int shouldClose = 0;
	int count = 0;
	int bossHP = 160;
	int bossYValue = 340;
	int aValue = -500;
	bool dead = false;
	int hype = 0;

	bool jumpKeyPressed = false;

	// Makes sure the character can jump upon entering a new screen
	bool firstJump = false;

	// Variables to keep track of the players projectile
	bool onScreenProjectile = false;
	projectile pencil;

	// Loops the entire game
	while (!shouldClose)
	{
		// Determines how far the player can move in each direction every frame
		player.refreshChecks();

		// Platform collision
		for (int i = 0; i < platformCount; i++)
		{
			player.checkAround(platforms[i].getLeftX(), platforms[i].getRightX(), platforms[i].getTopY(), platforms[i].getBotY());
		}
		// Spike box collision
		for (int i = 0; i < spikeCount; i++)
		{
			if (player.detectSpikeBox(spikes[i].getLeftX(), spikes[i].getRightX(), spikes[i].getTopY(), spikes[i].getBotY()))
			{
				dead = true;
			}
		}
		// Trampoline box collision
		for (int i = 0; i < trampolineCount; i++)
		{
			if (player.detectSpikeBox(trampolines[i].getLeftX(), trampolines[i].getRightX(), trampolines[i].getTopY(), trampolines[i].getBotY()))
				player.trampolineJump();
		}
		// Projectile collision
		for (int i = 0; i < platformCount; i++)
		{
			if (bossScreen == true && bossHP > 0)
			{
				if (pencil.detectCollision(260, 1152, 554, 260))
				{
					bossHP--;
					pencil.destroy();
					onScreenProjectile = false;
				}
			}
			if (pencil.detectCollision(platforms[i].getLeftX(), platforms[i].getRightX(), platforms[i].getTopY(), platforms[i].getBotY()))
			{
				onScreenProjectile = false;
			}
		}
		// Projectile onto checkpoint collision
		for (int i = 0; i < checkpointCount; i++)
		{
			if (player.detectSpikeBox(checkpoints[i].getLeftX(), checkpoints[i].getRightX(), checkpoints[i].getTopY(), checkpoints[i].getBotY()))
				save(screen, player.getLeftX() - 5, player.getBotY() - 1, direction, pencilCase);
		}
		// Boss projectile collision
		for (int i = 0; i < bossProjectileCount; i++)
		{
			if (bossHP > 0)
			{
				if (player.detectSpikeBox(bossProjectiles[i].getLeftX(), bossProjectiles[i].getRightX(), bossProjectiles[i].getTopY(), bossProjectiles[i].getBotY()))
					shouldClose = true;
			}
		}

		// Determines if the projectile goes off screen (collision with the edges of the screen)
		if (pencil.checkOffScreen())
		{
			onScreenProjectile = false;
		}

		if (shouldClose == false)
		{
			// Changes character sprites based off last key pressed


			if (dead == false)
			{
				// Moves the character left
				if (FzlGetKey(FzlKeyLeftArrow))
				{
					direction = 0;
					player.moveLeft();
				}

				// Moves the character right
				else if (FzlGetKey(FzlKeyRightArrow))
				{
					direction = 1;
					player.moveRight();
				}

				else
				{
					aaronFrame = 0;
					aaronAnim = 0;
				}
			}

			// Shoots a projectile if the 'S' key is pressed
			if (FzlGetKey(FzlKeyS) && onScreenProjectile == false && pencilCase == 1)
			{
				// Modifys the pencil object depending on which direction the player is facing
				if (direction == 0)
				{
					pencil.create(true, player.getX(), player.getY());
				}
				else
				{
					pencil.create(false, player.getX(), player.getY());
				}
				onScreenProjectile = true;
			}

			// Reset to the previous save
			if (FzlGetKey(FzlKeyR))
			{
				shouldClose = true;
			}

			if (FzlGetKey(FzlKeyH) && hype == 0)
			{
				hype++;
			}
			else if (FzlGetKey(FzlKeyY) && hype == 1)
			{
				hype++;
			}
			else if (FzlGetKey(FzlKeyP) && hype == 2)
			{
				hype++;
			}
			else if (FzlGetKey(FzlKeyE) && hype == 3)
			{
				hype++;
			}
			else if (hype == 4)
			{
				bossHP += 1000;
				hype++;
				FzlPauseSound(boss);
				FzlPlaySound(tengaku);
			}


			// If there is a pencil on the screen, let it travel through the screen
			if (onScreenProjectile == true)
				pencil.travel();

			// Jump command
			if (FzlGetKey(FzlKeyUpArrow))
			{
				if (jumpKeyPressed == false)
				{
					if (firstJump == false)
					{
						player.trampolineJump();
						firstJump = true;
					}
					else
						player.jump();
				}
				jumpKeyPressed = true;
			}
			else
			{
				jumpKeyPressed = false;
			}


			// Move the player up during a jump
			if (player.isJumping())
			{
				player.moveUp();
			}

			// Ignore falling if the character is mid-jump
			if (player.isJumping() == false && dead == false)
				player.moveDown();

			// Keeps the character animation at a specific frame as long as the character is in the air
			// aka prevents walking in mid-air
			if (player.isGrounded() == false)
			{
				aaronFrame = 6;
				aaronAnim = 6;
			}

			// Draws the background
			FzlDrawSprite(screenImage, 576, 432, 0.0f);
			if (dead == false)
			{
				// Draws the player
				if (direction == 0)
					FzlDrawAnimatedSprite(aaronLeft, aaronAnim, aaronFrame, player.getX(), player.getY(), 0.0f);
				else if (direction == 1)
					FzlDrawAnimatedSprite(aaronRight, aaronAnim, aaronFrame, player.getX(), player.getY(), 0.0f);
			}
			else
			{
				FzlDrawSprite(fail, 576, 442, 0.0f);
			}

			if (bossScreen == true)
			{
				if (hype == 5)
					FzlDrawSprite(boss2SpriteHard, 692, bossYValue, 0.0f);
				else
					FzlDrawSprite(boss2Sprite, 692, bossYValue, 0.0f);

				if (bossHP > 120)
				{
					FzlDrawSprite(full, 576, 432, 0.0f);
				}
				else if (bossHP > 80)
				{
					FzlDrawSprite(kindafull, 576, 432, 0.0f);
				}
				else if (bossHP > 40)
				{
					FzlDrawSprite(half, 576, 432, 0.0f);
				}
				else if (bossHP > 0)
				{
					FzlDrawSprite(almost, 576, 432, 0.0f);
				}

				if (bossHP > 0)
				{
					if (player.getRightX() >= 260)
						player.moveLeft();
					for (int i = 0; i < bossProjectileCount; i++)
					{
						bossProjectiles[i].travel(player.getX(), player.getY());
						FzlDrawSprite(boss2ProjectileSprite, bossProjectiles[i].getX(), bossProjectiles[i].getY(), 0.0f);
					}
				}
				else
				{
					FzlDrawSprite(a, 692, aValue, 0.0f);
					FzlDrawSprite(done, 576, 432, 0.0f);
					bossYValue --;
					aValue++;
				}
			}

			if (screen == 114 && player.getX() > 531 && player.getX() < 621 && player.getY() > 387 && player.getY() < 477)
			{
				pencilCase = 1;
			}

			if (pencilCase == 0 && screen == 114)
				FzlDrawSprite(pencilCaseSprite, 576, 432, 0.0f);



			// Draws the projectile sprite if there is one on screen at the current time
			if (onScreenProjectile == true)
			{
				if (pencil.getDirection())
					FzlDrawSprite(projectileLeft, pencil.getX(), pencil.getY(), 0.0f);
				else
					FzlDrawSprite(projectileRight, pencil.getX(), pencil.getY(), 0.0f);
			}



			if (firstJump == false && player.isGrounded())
			{
				firstJump = true;
			}


			// Changes the frame of the animation (walking)
			if (count >= 3 && player.isJumping() == false)
			{
				count = 0;
				aaronFrame++;
			}
			count++;

			// Loops the animation
			if (aaronFrame >= 8)
			{
				aaronFrame = 0;
				aaronAnim++;
				if (aaronAnim >= 8)
					aaronAnim = 0;
			}

			if (player.getLeftX() >= 1152)
			{
				screen++;
				player.screenSwapRight();
				save(screen, player.getLeftX() + 7, player.getBotY() - 1, direction, pencilCase);
				shouldClose = true;
			}
			else if (player.getTopY() <= 0)
			{
				screen += 10;
				player.screenSwapDown();
				save(screen, player.getLeftX() - 5, player.getBotY() - 1, direction, pencilCase);
				shouldClose = true;
			}
			else if (player.getRightX() <= 0)
			{
				screen -= 1;
				player.screenSwapLeft();
				save(screen, player.getLeftX() - 17, player.getBotY() - 1, direction, pencilCase);
				shouldClose = true;
			}

			FzlSwapBuffers();
			//Until the user hits the escape key, keep looping
			//shouldClose = FzlGetKey(FzlKeyEscape);
		}
	}
	FzlDeleteSprite(left);
	FzlDeleteSprite(right);
	FzlDeleteSprite(aaronLeft);
	FzlDeleteSprite(aaronRight);
	FzlDeleteSprite(projectileLeft);
	FzlDeleteSprite(projectileRight);
	FzlDeleteSprite(pencilCaseSprite);
	FzlDeleteSprite(screenImage);
	FzlDeleteSprite(boss2ProjectileSprite);
	FzlDeleteSprite(boss2Sprite);
	FzlDeleteSprite(fail);
	FzlDeleteSound(walking);
	FzlDeleteSound(boss);
	FzlDeleteSound(tengaku);


	FzlDeleteSprite(boss2SpriteHard);

	FzlDeleteSprite(full);
	FzlDeleteSprite(kindafull);
	FzlDeleteSprite(half);
	FzlDeleteSprite(almost);
	FzlDeleteSprite(done);

	FzlDeleteSprite(a);

	return 0;
}



int main()
{
	//The first thing we do is initialize the library with the function below
	//Provide it with a name for the window, in addition to a set of dimensions.
	//The trailing 0 means 'windowed' mode. 

	const int windowWidth = 1152;
	const int windowHeight = 864;

	bool game = true;

	int screenNumber;
	int holdx;
	int holdy;

	int temp;

	//Player player(72, 792);
	load(screenNumber, holdx, holdy, temp, temp);

	// Res = 1152x86
	FzlInit("The Failure", 1152, 864, 0);


	FzlSoundHandle music = FzlLoadSound("../../../Assets/sound/failureMusic.wav", true);


	FzlPlaySound(music);

	if (mainMenu() == 1)
		game = false;
	else 
		game = true;


	while (game == true)
	{
		load(screenNumber, holdx, holdy, temp, temp);
		if (screenNumber == 136)
		{
			screenNumber = 201;
			save(screenNumber, holdx+40, holdy, temp, temp);
		}
		if (screenNumber == 253)
		{
			FzlPauseSound(music);
		}
		else
		{
			FzlPlaySound(music);
		}
		if (screenNumber == 254)
		{
			save(101, 72, 792, 1, 0);
			load(screenNumber, holdx, holdy, temp, temp);
		}
		if (screenNumber > 100 && screenNumber < 200)
		{ 
			world1();
		}
		else if (screenNumber > 200 && screenNumber < 300)
		{
			world2();
		}
		
	}


	//Once we're done with our program, we should terminate it like so:
	FzlDestroy();
}