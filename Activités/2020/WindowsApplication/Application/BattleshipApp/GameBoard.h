#pragma once

#include <string>
#include <Windows.h>
#include "BoatsPosition.h"

class GameBoard
{
public:
	GameBoard();

	void reset();

	void drawGameBoard(HDC ihdc, RECT& iPaintArea);

	void click(int iX, int iY);

	void ResetStats();

private:
	HBRUSH mBlackBrush;
	HBRUSH mRedBrush;
	HBRUSH mGreenBrush;
	HBRUSH mGrayBrush;
	HBRUSH mWhiteBrush;
	HBRUSH mBlueBrush;
	HBRUSH mPurpleBrush;
	HBRUSH mOrangeBrush;
	HBRUSH mYellowBrush;
	BoatsPosition mBoatsPosition;

	HBRUSH getBrush(int i, int i2);
	void defineDefautBrush();

	const int mkLeftBoardCoor = 400;
	const int mkTopBoardCoor  = 100;
	const int mkSizeCell= 40;
	const int mkRadiusToken = 15;

	int mShots = 0;
	int mMissed = 0;
	int mHits = 0;

	bool mClick = true;
};

