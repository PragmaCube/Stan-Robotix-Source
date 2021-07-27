#pragma once

#include "../../Framework/IApplication.h"
#include "PacmanPlayer.h"
#include "Blinky.h"
#include "PacmanGameBoard.h"

class PacmanGameEngine;

class PacmanApplication :
    public IApplication
{
public:
	PacmanApplication();

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

	PacmanGameBoard mPacmanGameBoard;
	PacmanGameEngine* mPacmanGameEngine;

	char mDir = 'l'; //  permet à pacman de conserver son mouvement 
					// ('l' = left, 'r' = right, 'd' = down, 'u' = up). va à gauche par défaut
	char mNextDir;

	int mCoorPacX, mCoorPacY;
	int mCoorBlocX = 5;
	int mCoorBlocY = 1;
};

