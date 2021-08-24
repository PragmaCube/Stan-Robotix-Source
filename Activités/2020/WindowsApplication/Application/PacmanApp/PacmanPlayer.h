#pragma once
#include <Windows.h>
#include "PacmanGameBoard.h"

class PacmanPlayer
{
public:

	PacmanPlayer();

	void initialise(RECT iWindowRect, PacmanGameBoard* iPacmanGameBoard);

	void initializeGameEngine(PacmanGameEngine* iPacmanGameEngine);

	void movePacmanUp();
	void movePacmanDown();
	void movePacmanRight();
	void movePacmanLeft();

	char getWay();

	void move(char way);

	int getX();
	int getY();

	void initializeBitmap(HDC ihdc);

	void paint(HDC ihdc);

protected:	

	HDC mPacmanUpDC, mPacmanDownDC, mPacmanLeftDC, mPacmanRightDC, mPacmanPointDC;

	HDC createBitmap(HDC ihdc, const LPCWSTR lpBitmapName);


private:
	double kSpeed = 5;
	double mCoorX, mCoorY;
	int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin; // coordonnées des extrémités du plateau de jeu

	bool mIsInit;
	int mCoorBlocX, mCoorBlocY;
	char mDir = 'l';

	const double mNbRows = 28.0;
	const double mNbColumns = 31.0;

	double mSideX, mSideY;

	char mWay = 'l';

	int mTimeSwitch = 0;

	PacmanGameBoard *mGameBoard;
	PacmanGameEngine* mPacmanGameEngine;
};