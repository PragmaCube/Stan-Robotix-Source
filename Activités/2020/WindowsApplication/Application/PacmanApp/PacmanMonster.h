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

	double kSpeed = 5;
	double mCoorX, mCoorY;

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

	void initialise(RECT iWindowRect, Monster iMonsterType);

	// Pas d'intelligence artificielle
	// Seulement des modifieurs pour que l'on puisse
	// voir les différents monstres

	void moveMonsterUp(int iModifier);
	void moveMonsterDown(int iModifier);
	void moveMonsterRight(int iModifier);
	void moveMonsterLeft(int iModifier);

	void paint(HDC ihdc);

	void setBoard(PacmanGameBoard* iGameBoard);
	void setPlayer(PacmanPlayer* iPlayer);
};

