#pragma once
#include <Windows.h>
#include "PacmanGameBoard.h"

class PacmanApplication;

class PacmanPlayer
{
public:

	PacmanPlayer();

	void setApplication(PacmanApplication* iApplication) 
	{
		mApplication = iApplication;
	}

	void initialise(RECT iWindowRect, PacmanGameBoard* iPacmanGameBoard);

	void initializeGameEngine(PacmanGameEngine* iPacmanGameEngine);

	void movePacmanUp();
	void movePacmanDown();
	void movePacmanRight();
	void movePacmanLeft();

	char getWay();

	void move(char iWay);
	void TpPacman(char iWay);

	int getX();
	int getY();

	bool getWeak();

	void setWeak(bool iState);

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

	const double mNbRows = 31.0;
	const double mNbColumns = 28.0;

	double mSideX, mSideY;

	char mWay = 'l';

	int mTimeSwitch = 0;

	bool mWeak = true;

	PacmanGameBoard *mGameBoard;
	PacmanGameEngine* mPacmanGameEngine;
	PacmanApplication* mApplication;
};