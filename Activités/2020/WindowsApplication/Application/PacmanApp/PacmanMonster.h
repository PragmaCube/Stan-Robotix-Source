#pragma once

#include <Windows.h>
#include "PacmanPlayer.h"
#include "PacmanGameBoard.h"

enum Monster
{
	eBlinky,
	ePinky,
	eInky,
	eClyde
};

class PacmanMonster
{
	// Copie du code d'Antoine

	double kSpeed = 40;
	double mCoorX, mCoorY;
	
	int mBoardCoordX = 1;
	int mBoardCoordY = 1;

	char mWay = 'd';

	// À revoir
	int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin;
	HBRUSH mBrush;
	const int mRadius = 20;
	bool mIsInit;

	Monster mMonsterType;

	PacmanGameBoard* mGameBoard;
	PacmanPlayer* mPlayer;

public:
	PacmanMonster();

	void initialise(RECT iWindowRect, Monster iMonsterType, PacmanGameBoard* iGameBoard, PacmanPlayer* iPlayer);

	// Pas d'intelligence artificielle
	// Seulement des modifieurs pour que l'on puisse
	// voir les différents monstres

	void moveMonsterUp();
	void moveMonsterDown();
	void moveMonsterRight();
	void moveMonsterLeft();

	void move();

	void paint(HDC ihdc);

	void updatePlayer(PacmanPlayer* iPlayer);
};

