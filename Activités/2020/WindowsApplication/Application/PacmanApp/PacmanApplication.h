#pragma once

#include "../../Framework/IApplication.h"
#include "PacmanPlayer.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "Pinky.h"
#include "PacmanGameBoard.h"

#include <ctime>

class PacmanGameEngine;
class PacmanPlayer;

class PacmanApplication :
	public IApplication
{
public:
	PacmanApplication();

	void setOldDirect(char OldDirect);

	void resetDirect();

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);

	void onMouseMove(int iPosX, int iPosY);

	void onTimer();

private:
	PacmanPlayer mPacman;

	Blinky mBlinky;
	Clyde mClyde;
	Inky mInky;
	Pinky mPinky;

	PacmanGameBoard mPacmanGameBoard;
	PacmanGameEngine* mPacmanGameEngine;

	clock_t mClock;

	bool mIsInit = false;

	char mDir = 'l'; //  permet à pacman de conserver son mouvement 
					// ('l' = left, 'r' = right, 'd' = down, 'u' = up). va à gauche par défaut
	char mNextDir;
	char mOldWay = 'l';

	int mCoorX, mCoorY;
	int mCoorBlocX = 5;
	int mCoorBlocY = 1;
};

