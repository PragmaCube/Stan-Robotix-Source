#pragma once

#include "../../Framework/IApplication.h"
#include "PacmanPlayer.h"
#include "PacmanMonster.h"
#include "PacmanGameBoard.h"

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
	PacmanPlayer Pacman;

	PacmanMonster mBlinky;
	PacmanMonster mPinky;
	PacmanMonster mInky;
	PacmanMonster mClyde;

	char mNextDir = 'l'; //  permet à pacman de conserver son mouvement 
					    // ('l' = left, 'r' = right, 'd' = down, 'u' = up). va à gauche par défaut
	PacmanGameBoard mPacmanGameBorad;
};

