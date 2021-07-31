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
	// 
	// À revoir
	int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin;
	HBRUSH mBrush;
	bool mIsInit;

	Monster mMonsterType;

public:
	int mBoardCoordX = 13;
	int mBoardCoordY = 14;

	int mStepX = 1; // 1 ---> 7
	int mStepY = 1; // 1 ---> 8

	double mCoorX, mCoorY;

	char mWay = 'u';

	PacmanGameBoard* mGameBoard;
	PacmanPlayer* mPlayer;

	PacmanMonster();

	void initialise(RECT iWindowRect, Monster iMonsterType, PacmanGameBoard* iGameBoard, PacmanPlayer* iPlayer);

	// Pas d'intelligence artificielle
	// Seulement des modifieurs pour que l'on puisse
	// voir les différents monstres

	bool isWallByWay(char iWay);

	void moveMonsterUp();
	void moveMonsterDown();
	void moveMonsterRight();
	void moveMonsterLeft();

	virtual void move();

	void paint(HDC ihdc);

	void updatePlayer(PacmanPlayer* iPlayer);
};